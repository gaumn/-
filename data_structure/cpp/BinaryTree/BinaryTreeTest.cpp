/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-03-05 21:08:10
 * @LastEditTime: 2021-04-10 21:48:15
 * @LastEditors: gaumn
 */
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;
#define N 50          //定义测试数组数目
#define MinNumber 0   //最小生成随机数
#define MaxNumber 100 //最大生成随机数
int main(int argc, char const *argv[])
{
    vector<int> arr = Random::get_array(N, MinNumber, MaxNumber);
    Random::printarr(arr);
    return 0;
}
