/*
 * @Descripttion: SortTest.cpp
 * @Author: gaumn
 * @Date: 2021-03-12 20:52:07
 * @LastEditors: gaumn
 * @LastEditTime: 2021-03-14 21:16:52
 */
#include <iostream>
#include <vector>
#include "Sort.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr{0, 1, 20, 32, 41, 38, 30, 40, 1, 3, 5, 2, 9, 105, 49};
    /**
    * 交换排序类型
    *   冒泡排序和快速排序
    */
    /*冒泡排序测试 */
    // BubbleSort(arr);
    /*快速排序测试 */
    // int size=arr.size();
    // quicklySort(arr,0,size-1);
    /**
    *  插入排序类型
    *   简单插入排序和希尔排序
    */
    /*插入排序测试 */
    // InsertSort(arr);
    /*希尔排序测试 */
    // ShellSort(arr);
    /**
    * 3.选择排序类型
    */
    //简单选择排序
    // SelectSort(arr);
    //堆排序
    HeapSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "    ";
    }

    return 0;
}
