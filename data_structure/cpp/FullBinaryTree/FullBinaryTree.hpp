/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-03-05 21:07:58
 * @LastEditTime: 2021-03-05 21:57:39
 * @LastEditors: gaumn
 */
#pragma onece
#include <iostream>
using namespace std;

template <class T>
struct BinaryTreeNode
{
    T val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : left(nullptr), right(nullptr)
    {
        cout << "please input data:";
        cin >> val;
    }
    BinaryTreeNode(const T &data, BinaryTreeNode *l = nullptr, BinaryTreeNode *r = nullptr) : val(data), left(l), right(r) {}
    ~BinaryTreeNode() {}
};

template <class T>
class FullBinaryTree
{
private:
    BinaryTreeNode<T> *root = nullptr;
    int position = 0;

public:
    FullBinaryTree(int len = 0);
    ~FullBinaryTree() {}
    // void print();
};

#include "FullBinaryTree.cpp" //模板实现文件，包含编译模型