// SelectionSort

#ifndef SORT_ALGORITHMS
#define SORT_ALGORITHMS

#include <iostream>


namespace SortAlgorithms
{
    // Selection Sort
    // 遍历整个数组，选择当前最小的一项与第一项进行交换
    template<typename T>
    void selectionSort(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }

    // 插入排序
    // 遍历整个数组，与前面的元素对比，并插入一个较小的位置
    template<typename T>
    void insertionSort(T arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            T e = arr[i];
            int j;
            for (j = i; j > 0 && arr[j - 1] > e; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    // 冒泡排序
    // 从前向后遍历，遇到比当前数小的进行swap，如果遇到比当前数大的则不变
    template<typename T>
    void bubbleSort(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template<typename T>
    void conqureHelper(T arr[], int l, int mid, int r)
    {
        // Need a temp array
        T* temp = new T[r - l + 1];
        
        for (int i = l; i <= r; i++)
        {
            temp[i - l] = arr[i];
        }

        // Based on segment [l ... mid] and [mid + 1 ... r]
        // Rearrange all
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++)
        {
            if (i > mid)
            {
                arr[k] = temp[j - l];
                j++;
            }
            else if (j > r)
            {
                arr[k] = temp[i - l];
                i++;
            }
            else if (temp[i - l] > temp[j - l])
            {
                arr[k] = temp[j - l];
                j++;
            }
            else
            {
                arr[k] = temp[i - l];
                i++;
            }
        }
        delete[] temp;
        return;
    }

    template<typename T>
    void divideHelper(T arr[], int l, int r)
    {
        // range: [l ... r]
        if (l >= r)
        {
            return;
        }

        int mid = (l + r) / 2;

        divideHelper(arr, l, mid);
        divideHelper(arr, mid + 1, r);
        conqureHelper(arr, l, mid, r);
    }

    // 并归排序
    // 先分治 再并归
    template<typename T>
    void mergeSort(T arr[], int n)
    {
        //mergeSortHelper(arr, 0, n - 1);
        divideHelper(arr, 0, n - 1);
    }


    // 对 arr[l...r]部分进行partition
    // 返回索引p使得 arr[l...p] < arr[p]; arr[p+1...r] > arr[p]
    template<typename T>
    int __partition(T arr[], int l, int r)
    {
        T v = arr[l];   // 获得标准
        // arr[l+1...j] < v; arr[j+1...i] > v
        // 遍历的标识表示大于v部分的结尾
        // 用另一个标识j表示小于v的结尾
        int j = l;
        for (int i = l + 1; i <= r; i++)
        {
            if (arr[i] < v)
            {
                swap(arr[j + 1], arr[i]);
                j++;
            }
        }

        // 将v值放置到分界点
        swap(arr[l], arr[j]);

        return j;
    }

    // 双路快速排序
    template<typename T>
    int __partition2(T arr[], int l, int r)
    {
        T v = arr[l];

        // arr[l+1...i] <= v; arr[j...r] >= v
        int i = l + 1, j = r;
        while (true)
        {
            // 确保 arr[i] 是小于 v 的
            while (i <= r && arr[i] < v)
            {
                i++;
            }

            while (j >= l + 1 && arr[j] > v)
            {
                j--;
            }

            if (i > j)
            {
                break;
            }

            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        // 此时 i > j
        // j 表示的是最后一个小于 v 的元素
        swap(arr[l], arr[j]);

        return j;
    }

    template <typename T>
    void __quickSort3Ways(T arr[], int l, int r) {

        T v = arr[l];

        int lt = l;     // arr[l+1...lt] < v
        int gt = r + 1; // arr[gt...r] > v
        int i = l + 1;    // arr[lt+1...i) == v
        while (i < gt) {
            if (arr[i] < v) {
                swap(arr[i], arr[lt + 1]);
                i++;
                lt++;
            }
            else if (arr[i] > v) {
                swap(arr[i], arr[gt - 1]);
                gt--;
            }
            else { // arr[i] == v
                i++;
            }
        }

        swap(arr[l], arr[lt]);

        __quickSort3Ways(arr, l, lt - 1);
        __quickSort3Ways(arr, gt, r);
    }


    template<typename T>
    void __quickSort(T arr[], int l, int r)
    {
        if (l >= r)
        {
            return;
        }

        int p = __partition2(arr, l, r);     // 获得基点的位置作为分割点
        __quickSort(arr, l, p);
        __quickSort(arr, p + 1, r);
    }

    // Quick sort
    template<typename T>
    void quickSort(T arr[], int n)
    {
        __quickSort(arr, 0, n - 1);
        //__quickSort3Ways(arr, 0, n - 1);
    }

}

#endif // !

