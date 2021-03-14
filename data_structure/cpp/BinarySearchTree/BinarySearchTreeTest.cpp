/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-03-05 22:06:29
 * @LastEditTime: 2021-03-07 18:38:28
 * @LastEditors: gaumn
 */
#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
    system("chcp 65001");
    BinarySearchTree<int> bst;
    bst.Insert(99);
    bst.Insert(9);
    bst.Insert(19);
    bst.Insert(199);
    bst.Insert(100);
    bst.Insert(299);
    bst.Insert(95);
    bst.Insert(28);
    bst.Insert(7);
    bst.Preorder();
    bst.Search(8);
    BinaryTreeNode<int> *bsn = bst.Search(7);
    cout << "值为" << bsn << endl; //地址
    return 0;
}
