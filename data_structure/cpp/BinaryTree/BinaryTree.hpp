/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-03-05 21:07:58
 * @LastEditTime: 2021-04-08 20:37:42
 * @LastEditors: gaumn
 */
#pragma onece
#include <iostream>
using namespace std;

template <class T>
struct TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : left(nullptr), right(nullptr)
    {
        cout << "please input data:";
        cin >> val;
    }
    TreeNode(const T &data, TreeNode *l = nullptr, TreeNode *r = nullptr) : val(data), left(l), right(r) {}
    ~TreeNode() {}
};

template <class T>
class BinaryTree
{
private:
    TreeNode<T> *root = nullptr;
    int position = 0;

public:
    BinaryTree(int len = 0);
    ~BinaryTree() {}
    // void print();
};

#include "BinaryTree.cpp" //模板实现文件，包含编译模型