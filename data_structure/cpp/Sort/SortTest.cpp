/*
 * @Descripttion: SortTest.cpp
 * @Author: gaumn
 * @Date: 2021-03-12 20:52:07
 * @LastEditors: gaumn
 * @LastEditTime: 2021-11-18 21:57:15
 */
#include <iostream>
#include "Random.hpp"
#include <vector>
#include "Sort.hpp"
using namespace std;
#define N 10         //定义测试数组数目
#define MinNumber 8  //最小生成随机数
#define MaxNumber 10 //最大生成随机数
int main(int argc, char const *argv[])
{
    vector<int> arr = Random::get_array(N, MinNumber, MaxNumber);
    Random::printarr(arr);
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
    // HeapSort(arr);
    /**
     * 4.非比较类排序
     **/
    //计数排序
    // CountingSort(arr);
    //基数排序
    // RadixSort(arr);
    //桶排序(链表)
    // BucketSort(arr); //存在问题，当排序数目500左右编译器(vscode)要报错

    // Random::printarr(arr);
    return 0;
}
