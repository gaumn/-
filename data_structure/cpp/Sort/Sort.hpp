/*
 * @Descripttion: Sort.hpp
 * @Author: gaumn
 * @Date: 2021-03-12 20:51:56
 * @LastEditors: gaumn
 * @LastEditTime: 2021-03-20 21:40:11
 */
#pragma onece
#include <iostream>
#include <vector>
using namespace std;
const int BUCKET_NUM = 10;
struct ListNode
{
    explicit ListNode(int i = 0) : Data(i), Next(NULL) {}
    ListNode *Next;
    int Data;
};
void test();
/**
 * 交换排序类型
 *   冒泡排序和快速排序
*/
void BubbleSort(vector<int> &arr);                       //冒泡排序
void quicklySort(vector<int> &arr, int left, int right); //快速排序
/**
*  插入排序类型
*   简单插入排序和希尔排序
*/
void InsertSort(vector<int> &arr); //插入排序
void ShellSort(vector<int> &arr);  //希尔排序
/**
 * 选择排序类型
 *  简单选择排序和堆排序
*/
void SelectSort(vector<int> &arr); //简单选择排序
void HeapSort(vector<int> &arr);   //堆排序
/**
 * 非比较排序
 *  计数排序，基数排序，桶排序
 * **/
void CountingSort(vector<int> &arr); //计数排序
void RadixSort(vector<int> &arr);    //基数排序
void BucketSort(vector<int> &arr);
// void BucketSort(vector<int> &arr);   //桶排序
#include "Sort.cpp"