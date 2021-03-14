/*
 * @Description: Queue的测试文件
 * @Author: gaumn 
 * @Date: 2021-02-23 14:37:56
 * @LastEditTime: 2021-02-23 15:25:11
 * @LastEditors: gaumn
 */
#include <iostream>
#include "QueueList.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
    system("chcp 65001");
    QueueList<int> queue(2);
    queue.PrintQueue();
    queue.push(50);
    queue.push(500);
    queue.push(100);
    cout << "队列首个值：" << queue.front() << endl;
    cout << "队列末尾值：" << queue.back() << endl;
    queue.PrintQueue();
    queue.pop();
    queue.pop();
    queue.PrintQueue();
    queue.pop();
    queue.pop();
    queue.PrintQueue();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.PrintQueue();
    return 0;
}
