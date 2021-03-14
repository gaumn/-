/*
 * @Descripttion: SortTest.cpp
 * @Author: gaumn
 * @Date: 2021-03-12 20:51:56
 * @LastEditors: gaumn
 * @LastEditTime: 2021-03-14 21:22:24
 */
#pragma onece
#include <iostream>
#include <vector>
using namespace std;
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
#include "Sort.cpp"