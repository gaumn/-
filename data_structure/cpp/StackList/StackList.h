/*
 * @Description: StackList.h
 * @Author: gaumn 
 * @Date: 2021-02-22 18:30:12
 * @LastEditTime: 2021-02-22 22:29:38
 * @LastEditors: gaumn
 */
#pragma onece
#include <iostream>
using namespace std;

template <class T>
struct LinkNode
{
    T Data;
    LinkNode *Next;
    LinkNode() : Next(nullptr)
    {
        cout << "Please input data: ";
        cin >> Data;
    }
    LinkNode(const T &data, LinkNode *next = nullptr) : Data(data), Next(next) {}
    ~LinkNode() {}
};

template <class T>
class StackList
{
    // private:
    LinkNode<T> *Head;
    int Size = 0;

public:
    StackList(int Len = 0);
    ~StackList() {}
    /**
     * push
     * pop
     * top
     * isempty
     * **/
    bool IsEmpty() //判断栈是否为空
    {
        return Size == 0;
    }
    void Push(const T &data); //向栈顶加入元素
    T Top() const;            //返回栈顶元素
    T Pop();                  //返回栈顶元素并移除
    void PrintStack();        //打印stack内的所有值，调试使用
};
#include "StackList.cpp" //模板实现文件
