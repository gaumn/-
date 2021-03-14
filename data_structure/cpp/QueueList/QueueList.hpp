/*
 * @Description: Queue的头文件
 * @Author: gaumn 
 * @Date: 2021-02-23 13:38:58
 * @LastEditTime: 2021-02-23 14:56:33
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
        cout << "please input data:";
        cin >> Data;
    }
    LinkNode(const T &data, LinkNode *next = nullptr) : Data(data), Next(next){};
};

template <class T>
class QueueList
{
    // private:
    LinkNode<T> *Head = nullptr;
    LinkNode<T> *Tail = nullptr;
    int Size = 0;

public:
    QueueList(int len = 0);
    ~QueueList()
    {
        DeleteList(); //释放new出来的节点
    }
    void DeleteList();
    void PrintQueue();
    /**
     * front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
     * back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
     * push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
     * pop()：删除 queue 中的第一个元素。
     * size()：返回 queue 中元素的个数。
     * empty()：如果 queue 中没有元素的话，返回 true。
     * **/
    bool empty()
    {
        return Size == 0;
    }
    int size()
    {
        return Size;
    }
    T front() const;
    T back() const;
    void push(const T &obj);
    void pop();
};

#include "QueueList.cpp"