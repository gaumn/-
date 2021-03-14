/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-02-20 21:40:58
 * @LastEditTime: 2021-02-22 22:07:48
 * @LastEditors: vscode
 */
#pragma once
#include <iostream>
using namespace std;

template <class T>
struct LinkNode //节点类
{
    T Data;         //节点的数据
    LinkNode *Next; //指向该节点的下一个节点的指针
    LinkNode() : Next(NULL)
    {
        cout << "please enter data: ";
        cin >> Data;
    }
    LinkNode(const T &d, LinkNode *p = NULL) : Data(d), Next(p) {}
    ~LinkNode() {}
};
template <class T>
class SingleLinkedList
{
    LinkNode<T> *Head = nullptr; //首尾指针
    LinkNode<T> *Tail = nullptr;
    int ListSize = 0; //链表长度
public:
    SingleLinkedList(int Len = 0); //构造函数(顺序插入)
    ~SingleLinkedList()            //析构函数
    {
        DeleteList(); //释放new出来的节点
    }
    void DeleteList();
    void Delete(const T &Data); //可以使用&也可以不用，删除指定的一个元素
    bool IsEmpty() const
    {
        return ListSize == 0;
    }
    bool IsLast(LinkNode<T> *Node)
    {
        return Node == Tail;
    }
    int GetLength() const //返回链表长度
    {
        return ListSize;
    }
    int Find(const T &Data) const;                       //寻找链表中是否存在该值，存在返回其位置，不存在则返回-1，如果有重复则返回第一个找到的元素
    LinkNode<T> *FindPosition(const int position) const; //查看positio位置链表的值，若该位置不在链表中，则返回nullptr(position从0开始计数)
    void InsertHead(const T &Data);
    void InsertTail(const T &Data);
    void Reverse();         //反转链表
    void PrintList() const; //打印链表数据
};

#include "SingleLinkedList.cpp" //模板实现文件，包含编译模型
