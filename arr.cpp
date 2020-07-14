#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;

class Array
{

private:
    int size;
    int length;
    int *ptrArr;

public:
    Array(/* 利用constructor Initialize */)
    {
        std::cout << "Enter Array size: " << flush;
        cin >> this->size;
        ptrArr = new int[this->size];
        std::cout << "Enter the number of elements: " << flush;
        cin >> this->length;

        for (int i = 0; i < this->length; i++)
        {
            cout << "Enter your elements in index " << i << ": " << flush;
            cin >> ptrArr[i];
        }
    }

    Array(int size, int length)
    {
        this->size = size;
        ptrArr = new int[this->size];
        this->length = length;
    }

    //構建一個操作符重載
    Array operator=(const Array &arr)
    {
        Array res(this->size + arr.size, this->length + arr.length);
        return res;
    }

    void init_rand()
    {
        /* initialize random seed: */
        srand(time(NULL));

        for (int i = 0; i < this->length; i++)
        {
            ptrArr[i] = rand() % 100 + 1;
        }
    }

    void display()
    {
        for (int i = 0; i < this->length; i++)
        {
            cout << ptrArr[i] << " ";
        }
        printf("\n");
    }

    void info()
    {
        std::cout << "length = " << this->length << std::endl;
        std::cout << "size = " << this->size << std::endl;
        std::cout << "address = " << this->ptrArr << std::endl;
    }

    void append(int x)
    {
        //check if it's full
        if (this->size == this->length)
        {
            std::cout << "Array has been full!!..." << std::endl;
            return;
        }

        //append (push_back)
        ptrArr[this->length] = x;
        this->length++;
    }

    void insert(int pos, int data)
    {
        //check if it's full
        if (this->size == this->length)
        {
            std::cout << "Array has been full!!..." << std::endl;
            return;
        }

        //insert: 把從要插入位置所有人後移（含本身）
        for (int i = this->length; i > pos; i--)
        {
            //後移
            ptrArr[i] = ptrArr[i - 1];
        }
        ptrArr[pos] = data;
        this->length++;
    }
    void delete_index(int pos)
    {
        //check if it's empty
        if (this->length == 0)
        {
            std::cout << "Array is Empty!..." << std::endl;
        }

        //delete: 把所有指定pos後方的data前移覆蓋
        for (int i = pos; i < this->length; i++)
        {
            ptrArr[i] = ptrArr[i + 1];
        }

        this->length--;
    }
    void swap(int index_x, int index_y)
    {
        int temp = 0;
        if (index_x > this->length || index_y > this->length)
        {
            std::cout << "Error index!!" << std::endl;
            return;
        }

        temp = ptrArr[index_x];
        ptrArr[index_x] = ptrArr[index_y];
        ptrArr[index_y] = temp;
    }

    int linearSearch(int key)
    {
        for (int i = 0; i < this->length; i++)
        {
            //return first elements if find.
            if (ptrArr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    int linearSearch_trans(int key)
    {
        for (int i = 0; i < this->length; i++)
        {
            //return first elements if find.
            if (ptrArr[i] == key)
            {
                this->swap(i, i - 1);
                return i;
            }
        }
        return -1;
    }

    int linearSearch_move_to_heaven(int key)
    {
        for (int i = 0; i < this->length; i++)
        {
            //return first elements if find.
            if (ptrArr[i] == key)
            {
                this->swap(i, 0);
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int key)
    {
        int l = 0;
        int h = this->length - 1;

        //if l > h ->表示沒有找到
        while (l < h)
        {
            int mid = (l + h) / 2;

            if (key == ptrArr[mid])
            {
                return mid;
            }
            else if (key < ptrArr[mid])
            {
                h = mid - 1;
            }
            else if (key > ptrArr[mid])
            {
                l = mid + 1;
            }
        }
        return -1;
    }

    int binarySearch_recursion(int l, int h, int key)
    {

        if (l <= h)
        {
            int mid = (l + h) / 2;
            if (key == ptrArr[mid])
            {
                return mid;
            }
            else if (key < ptrArr[mid])
            {
                return this->binarySearch_recursion(l, mid - 1, key);
            }
            else if (key > ptrArr[mid])
            {
                return this->binarySearch_recursion(mid + 1, h, key);
            }
        }
        return -1;
    }

    int get(int pos)
    {
        //check valid
        if (pos < 0 || pos >= this->length)
        {
            return 0;
        }

        return ptrArr[pos];
    }

    void set(int pos, int data)
    {
        //check valid
        if (pos < 0 || pos >= this->length)
        {
            return;
        }

        ptrArr[pos] = data;
    }

    int max()
    {
        //Assume maximum is first element
        int max = this->ptrArr[0];

        for (int i = 0; i < this->length; i++)
        {
            if (ptrArr[i] > max)
            {
                max = ptrArr[i];
            }
        }
        return max;
    }

    int min()
    {
        //Assume maximum is first element
        int min = this->ptrArr[0];

        for (int i = 0; i < this->length; i++)
        {
            if (ptrArr[i] < min)
            {
                min = ptrArr[i];
            }
        }
        return min;
    }

    int sum()
    {
        int sum = ptrArr[0];

        for (int i = 1; i < this->length; i++)
        {
            sum += ptrArr[i];
        }

        return sum;
    }

    //ｎ要傳長度
    int sum_recursion(int n)
    {
        int sum = this->ptrArr[0];

        if (n < 0)
        {
            return 0;
        }
        return sum_recursion(n - 1) + ptrArr[n];
    }

    int avg()
    {
        return (this->sum()) / (this->length);
    }

    void reverse_copy()
    {
        Array reverse_cpy(this->size, this->length);
        //i 從左到右，j從右到左反轉assign給copy的array
        for (int i = 0, j = this->length - 1; i < this->length; i++, j--)
        {
            reverse_cpy.ptrArr[j] = this->ptrArr[i];
        }
        //重新assign給 this
        for (size_t i = 0; i < this->length; i++)
        {
            this->ptrArr[i] = reverse_cpy.ptrArr[i];
        }
    }

    void reverse_swap()
    {
        for (size_t i = 0, j = this->length - 1; i < j; i++, j--)
        {
            int temp;
            temp = this->ptrArr[i];
            this->ptrArr[i] = this->ptrArr[j];
            this->ptrArr[j] = temp;
        }
    }

    void left_shift()
    {
        for (size_t i = 0; i < this->length; i++)
        {
            ptrArr[i] = ptrArr[i + 1];
        }
    }

    void left_rotate()
    {
        for (size_t i = 0; i < this->length; i++)
        {
            if (i == 0)
            {
                std::cout << "this->length = " << this->length << std::endl;
                ptrArr[this->length] = ptrArr[i];
            }
            ptrArr[i] = ptrArr[i + 1];
        }
    }

    bool isSorted()
    {
        //check arr[i+1] > arr[i]
        for (size_t i = 0; i < this->length; i++)
        {
            if (ptrArr[i] > ptrArr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void insert_sorted(int data)
    {
        //check if it's full
        if (this->size == this->length)
        {
            std::cout << "Array has been full!!..." << std::endl;
            return;
        }

        int i = this->length - 1;
        while (ptrArr[i] > data)
        {
            ptrArr[i] = ptrArr[i + 1];
            i--;
        }
        ptrArr[i + 1] = data;
        this->length++;
    }

    void negative_shift_left()
    {
        int i = 0;
        int j = this->length - 1;

        while (i < j)
        {
            while (ptrArr[i] < 0)
            {
                i++; //keep searching
            }
            while (ptrArr[j] >= 0)
            {
                j--;
            }
            //swap()
            int temp = ptrArr[i];
            ptrArr[i] = ptrArr[j];
            ptrArr[j] = temp;
        }
    }

    Array merge_arr(Array &array)
    {
        //將自己和其他Array 合併
        int i = 0; //本身index
        int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        int merge_size = this->size + array.size;
        int merge_length = this->length + array.length;

        Array mergeArr(merge_size, merge_length);

        //先把兩者共用的記憶體大小空間依順序填滿
        while (i < this->length && j < array.length)
        {
            if (this->ptrArr[i] < array.ptrArr[j])
            {
                mergeArr.ptrArr[k++] = this->ptrArr[i++];
            }
            else
            {
                mergeArr.ptrArr[k++] = array.ptrArr[j++];
            }
        }
        //再把剩下的放入剩下空間
        for (; i < this->length; i++)
        {
            mergeArr.ptrArr[k++] = this->ptrArr[i];
        }
        for (; j < array.length; j++)
        {
            mergeArr.ptrArr[k++] = array.ptrArr[j];
        }
        return mergeArr;
    }

    //Set operation

    //Union: 和merge唯一不同為當兩者相同時，只copy其一
    Array union_unsorted(const Array &arr)
    {
        //將自己和其他Array 合併
        // int i = 0; //本身index
        // int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        //Creat return Array
        int merge_size = this->size + arr.size;
        int merge_length = this->length;
        Array mergeArr(merge_size, merge_length);

        //先將A copy到final array
        for (int i = 0; i < this->length; i++)
        {
            mergeArr.ptrArr[k++] = this->ptrArr[i];
        }

        for (int j = 0; j < arr.length; j++)
        {
            k = 0;
            int flag = 0;
            while (k < mergeArr.length)
            {
                if (arr.ptrArr[j] == mergeArr.ptrArr[k])
                {
                    //利用flag標誌有重複
                    flag++;
                    break;
                }
                k++;
            }
            if (!flag)
            {
                mergeArr.append(arr.ptrArr[j]);
                mergeArr.length++;
            }
        }
        return mergeArr;
    }

    Array union_sorted(const Array &arr)
    {
        // 將自己和其他Array 合併
        int i = 0; //本身index
        int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        //Creat return Array
        int merge_size = this->size + arr.size;
        int merge_length = this->length;
        Array mergeArr(merge_size, merge_length);

        int final_length = 0;

        //兩者個數交集範圍內
        while (i < this->length && j < arr.length)
        {
            if (this->ptrArr[i] < arr.ptrArr[j])
            {
                mergeArr.ptrArr[k++] = this->ptrArr[i++];
                final_length++;
            }
            else if (this->ptrArr[i] > arr.ptrArr[j])
            {
                mergeArr.ptrArr[k++] = this->ptrArr[j++];
                final_length++;
            }
            else
            {
                mergeArr.ptrArr[k++] = this->ptrArr[i++];
                final_length++;

                j++;
            }
        }

        //過長的Array直接全部加入
        for (; i < this->length; i++)
        {
            mergeArr.ptrArr[k++] = this->ptrArr[i];
            final_length++;
        }
        for (; j < arr.length; j++)
        {
            mergeArr.ptrArr[k++] = arr.ptrArr[j];
            final_length++;
        }
        mergeArr.length = final_length;

        return mergeArr;
    }

    //intersection_unsorted: O(n**2)
    Array intersection_unsorted(Array const &arr)
    {
        int merge_size = this->size + arr.size;
        int merge_length = this->length + arr.length;
        int final_length = 0; // 用來計算最終長度

        int i = 0; //本身index
        int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        Array mergeArr(merge_size, merge_length);

        for (int i = 0; i < this->length; i++)
        {
            for (int j = 0; j < arr.length; j++)
            {
                if (this->ptrArr[i] == arr.ptrArr[j])
                {
                    mergeArr.ptrArr[k++] = this->ptrArr[i];
                    final_length++;
                }
            }
        }
        mergeArr.length = final_length;
        return mergeArr;
    }

    //intersection_sorted: O(n)
    Array intersection_sorted(Array const &arr)
    {
        int merge_size = this->size + arr.size;
        int merge_length = this->length + arr.length;
        int final_length = 0; // 用來計算最終長度

        int i = 0; //本身index
        int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        Array mergeArr(merge_size, merge_length);

        while (i < this->length && j < arr.length)
        {
            //若兩者相同
            if (this->ptrArr[i] == arr.ptrArr[j])
            {
                //加到target Array中
                mergeArr.ptrArr[k++] = this->ptrArr[i++];
                j++;
                final_length++;
            }
            else if (this->ptrArr[i] < arr.ptrArr[j])
            {
                i++;
            }
            else if (arr.ptrArr[j] < this->ptrArr[i])
            {
                j++;
            }
        }

        mergeArr.length = final_length;
        return mergeArr;
    }

    Array difference_unsorted(Array const &arr)
    {
        int merge_size = this->size + arr.size;
        int merge_length = this->length;
        int final_length = 0; // 用來計算最終長度

        // int i = 0; //本身index
        // int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        Array mergeArr(merge_size, merge_length);
        int flag = 0;

        for (int i = 0; i < this->length; i++)
        {
            for (int j = 0; j < arr.length; j++)
            {
                if (this->ptrArr[i] == arr.ptrArr[j])
                {
                    flag++;
                }
            }
            if (!flag)
            {
                mergeArr.ptrArr[k++] = this->ptrArr[i];
                final_length++;
            }
        }
        mergeArr.length = final_length;
        return mergeArr;
    }

    Array difference_sorted(Array const &arr)
    {
        int merge_size = this->size + arr.size;
        int merge_length = this->length;
        int final_length = 0; // 用來計算最終長度

        int i = 0; //本身index
        int j = 0; //傳入的arr之index
        int k = 0; //回傳array之index

        Array mergeArr(merge_size, merge_length);

        while (i < this->length && j < arr.length)
        {
            //若兩者相同
            if (this->ptrArr[i] == arr.ptrArr[j])
            {
                //不copy
                i++;
                j++;
            }
            //若欲減去的Array的元素較大
            else if (this->ptrArr[i] < arr.ptrArr[j])
            {
                mergeArr.ptrArr[k++] = this->ptrArr[i++];
                final_length++;
                //j不變
            }
            //若this的Array的元素較大
            else if (arr.ptrArr[j] < this->ptrArr[i])
            {
                j++;
            }
        }

        mergeArr.length = final_length;
        return mergeArr;
    }

    void find_missing()
    {
        int diff = this->ptrArr[0] - 0;
        for (int i = 0; i < this->length; i++)
        {
            if (this->ptrArr[i] - i != diff)
            {
                std::cout << "find missing elem: " << diff + i << std::endl;
                std::cout << "index should be: " << i << std::endl;
                diff = this->ptrArr[i] - i;
            }
        }
    }

    void multiple_finding()
    {
        int diff = this->ptrArr[0] - 0;

        for (int i = 0; i < this->length; i++)
        {
            if (diff != (this->ptrArr[i] - i))
            {
                while (diff < (this->ptrArr[i] - i))
                {
                    std::cout << "find missing elem: " << diff + i << std::endl;
                    diff++;
                }
            }
        }
    }

    void hashTable_finding()
    {

        int mp_length = this->max();
        int mp_size = this->size;
        Array res(mp_size, mp_length);

        for (int i = 0; i < this->length; i++)
        {
            res.ptrArr[this->ptrArr[i]]++;
        }
        for (int i = 1; i < res.length; i++)
        {
            if (res.ptrArr[i] == 0)
            {
                std::cout << "find missing elem: " << i << std::endl;
            }
        }
    }

    void find_duplicated() //必須sorted
    {
        for (int i = 0; i < this->length - 1; i++)
        {
            int j = i + 1;
            int cnt = 1;
            if (this->ptrArr[i] == this->ptrArr[i + 1])
            {

                while (this->ptrArr[j] == this->ptrArr[j + 1])
                {
                    j++;
                }
                std::cout << "find_duplicated: " << this->ptrArr[i] << std::endl;
                std::cout << "duplicated_times: " << j - i << std::endl;
                i = j - 1; //i 在if中：要跟在j後面
            }
        }
    }

    void find_duplicated_unsorted()
    {

        for (int i = 0; i < this->length; i++)
        {
            int cnt = 1; //數到的當下那一次
            for (int j = i + 1; j < this->length; j++)
            {
                if (this->ptrArr[i] == this->ptrArr[j] && this->ptrArr[i] != -1)
                {
                    cnt++;
                    this->ptrArr[j] = -1; //數過的標誌
                }
            }
            if (cnt > 1)
            {
                std::cout << "find_duplicated: " << this->ptrArr[i] << std::endl;
                std::cout << "duplicated_times: " << cnt << std::endl;
            }
        }
    }

    void find_duplicated_hashTable() //必須sorted
    {
        int mp_length = this->max();
        int mp_size = this->size;
        Array res(mp_size, mp_length);
        for (int i = 0; i < res.length; i++)
        {
            res.ptrArr[i] = 0;
        }

        for (int i = 0; i < this->length; i++)
        {
            res.ptrArr[this->ptrArr[i]]++;
        }
        for (int i = 0; i <= res.length; i++) //因為i可能為maximum number
        {
            if (res.ptrArr[i] > 1)
            {
                std::cout << "find_duplicated: " << i << std::endl;
                std::cout << "duplicated_times: " << res.ptrArr[i] - 1 << std::endl;
            }
        }
    }

    ~Array()
    {
        if (this->ptrArr != NULL)
        {
            delete[] this->ptrArr; //釋放連續記憶體
            this->ptrArr = NULL;
            std::cout << "Array has been destructed." << std::endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    printf("Hello Arrray!!\n");

    Array arr_1;
    // arr_1.init_rand();
    arr_1.find_duplicated_unsorted();
    arr_1.display();
    arr_1.info();

    return 0;
}