/*
 * @Description: stack的List实现（测试文件）
 * @Author: gaumn 
 * @Date: 2021-02-22 18:31:02
 * @LastEditTime: 2021-02-23 14:14:11
 * @LastEditors: gaumn
 */
#include "StackList.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    system("chcp 65001");
    StackList<int> stackInt(0);
    stackInt.Push(2);
    stackInt.Push(5);
    stackInt.PrintStack();
    cout << "弹出栈顶元素为:" << stackInt.Pop() << endl;
    cout << "栈顶元素为:" << stackInt.Top() << endl;
    cout << "弹出栈顶元素为:" << stackInt.Pop() << endl;
    stackInt.PrintStack();
    // cout << "hello";
    return 0;
}
