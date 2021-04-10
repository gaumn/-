/*
 * @Description: Random.hpp
 * @Author: gaumn 
 * @Date: 2021-03-20 17:54:27
 * @LastEditTime: 2021-04-10 16:06:52
 * @LastEditors: gaumn
 */
#pragma onece

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

namespace Random
{
    vector<int> get_array(int n, int rangeL, int rangeR)
    {
        vector<int> arr;
        srand(int(time(0)));
        assert(rangeL <= rangeR);
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr.push_back(rand() % (rangeR - rangeL + 1) + rangeL);
        }
        return arr;
    }
    //函数模板，打印数组中元素
    void printarr(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
} // namespace Random
