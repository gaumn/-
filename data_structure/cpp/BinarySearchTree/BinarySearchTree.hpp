/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-03-05 22:06:21
 * @LastEditTime: 2021-03-06 11:50:11
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
        cout << "Please input data";
        cin >> val;
    }
    BinaryTreeNode(const T &data, BinaryTreeNode *l = nullptr, BinaryTreeNode *r = nullptr) : val(data), left(l), right(r) {}
    ~BinaryTreeNode() {}
};

template <class T>
class BinarySearchTree
{
private:
    BinaryTreeNode<T> *Root;
    void Insert(const T &data, BinaryTreeNode<T> *TreeNode);               //插入
    BinaryTreeNode<T> *Search(const T &data, BinaryTreeNode<T> *TreeNode); //搜索
    void Preorder(BinaryTreeNode<T> *TreeNode);                            //前序遍历
    //删除
    //中序遍历
    //后序遍历
    //层序遍历

public:
    BinarySearchTree(); //初始化根节点
    ~BinarySearchTree() {}
    void Insert(const T &data);               //插入
    BinaryTreeNode<T> *Search(const T &data); //搜索
    void Preorder();                          //前序遍历
    //删除
    //前序遍历
    //中序遍历
    //后序遍历
    //层序遍历
};
#include "BinarySearchTree.cpp"
/*参考：
https://www.cprogramming.com/tutorial/lesson18.html
https://en.wikipedia.org/wiki/Binary_search_tree
**/