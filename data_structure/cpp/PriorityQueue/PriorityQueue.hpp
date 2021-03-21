/*
 * @Description: PriorityQueue.hpp
 * @Author: gaumn 
 * @Date: 2021-03-21 11:47:28
 * @LastEditTime: 2021-03-21 17:46:10
 * @LastEditors: gaumn
 */
#pragma onece
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class PriorityQueue
{
private:
    vector<T> Arr;
    int Size = 0;
    void MaxHeapfy(int begin, int end);

public:
    PriorityQueue(/* args */) {}
    void Insert(T &data);
    T Top();
    void Pop();
    bool Empty();
    int size();
    void Print();
    ~PriorityQueue() {}
};
#include "PriorityQueue.cpp"