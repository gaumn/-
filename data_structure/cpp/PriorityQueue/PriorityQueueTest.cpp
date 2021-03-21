/*
 * @Description: PriorityQueueTest.cpp
 * @Author: gaumn 
 * @Date: 2021-03-21 11:47:41
 * @LastEditTime: 2021-03-21 18:58:01
 * @LastEditors: gaumn
 */
#include <iostream>
#include "Random.hpp"
#include <vector>
#include "PriorityQueue.hpp"
using namespace std;
#define N 50          //定义测试数组数目
#define MinNumber 0   //最小生成随机数
#define MaxNumber 100 //最大生成随机数
int main(int argc, char const *argv[])
{
    vector<int> arr = Random::get_array(N, MinNumber, MaxNumber);
    Random::printarr(arr);
    PriorityQueue<int> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.Insert(arr[i]);
    }
    cout << pq.Top() << endl;
    pq.Pop();
    cout << pq.Top() << endl;
    cout << pq.size() << endl;
    cout << pq.Empty() << endl;
    pq.Print();
}
