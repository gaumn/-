/*
 * @Descripttion: SortTest.cpp
 * @Author: gaumn
 * @Date: 2021-03-12 20:41:10
 * @LastEditors: gaumn
 * @LastEditTime: 2021-03-14 21:16:11
 */
void test()
{
   cout << "hello" << endl;
}
void BubbleSort(vector<int> &arr)
{ //冒泡排序
   int size = arr.size();
   for (int i = 0; i < size - 1; i++)
   {
      for (int j = 0; j < size - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}
void quicklySort(vector<int> &arr, int left, int right)
{
   // int size=arr.size();
   int temp = arr[left];
   if (left > right)
      return;
   int i = left, j = right;
   while (i != j)
   {
      while (i < j && temp <= arr[j])
         j--;
      while (i < j && temp >= arr[i])
         i++;

      if (i < j)
      {
         int t = arr[i];
         arr[i] = arr[j];
         arr[j] = t;
      }
   }
   arr[left] = arr[i];
   arr[i] = temp;
   quicklySort(arr, left, i - 1);
   quicklySort(arr, i + 1, right);
}

void InsertSort(vector<int> &arr)
{ //插入排序
   int size = arr.size(), j;
   for (int i = 1; i < size; i++)
   {
      int temp = arr[i];
      for (j = i - 1; i >= 0 && arr[j] > temp; j--)
      {
         arr[j + 1] = arr[j];
      }
      arr[j + 1] = temp;
   }
}
void ShellSort(vector<int> &arr)
{
   int size = arr.size();
   int grap = size / 2, j;
   for (; grap > 0; grap /= 2)
   {
      for (int i = grap; i < size; i++)
      {
         int temp = arr[i];
         for (j = i - grap; j >= 0 && arr[j] > temp; j -= grap)
         {
            arr[j + grap] = arr[j];
         }
         arr[j + grap] = temp;
      }
   }
}
void SelectSort(vector<int> &arr) //简单选择排序
{
   int size = arr.size();
   int temp, position;
   for (int i = 0; i < size; i++)
   {
      temp = arr[i];
      position = i;
      for (int j = i + 1; j < size; j++)
      {
         if (arr[j] < arr[position])
         {
            position = j;
         }
      }
      arr[i] = arr[position];
      arr[position] = temp;
   }
}
//大项堆
void MaxHeapfy(vector<int> &arr, int begin, int end)
{
   int dad = begin, son = 2 * dad + 1, temp;
   while (son <= end)
   {
      if (son + 1 <= end && arr[son + 1] > arr[son])
         son += 1;
      if (arr[dad] > arr[son])
         return;
      else
      {
         temp = arr[dad];
         arr[dad] = arr[son];
         arr[son] = temp;
         dad = son;
         son = 2 * dad + 1;
      }
   }
}
void HeapSort(vector<int> &arr) //堆排序（大项堆）
{
   int size = arr.size();
   int temp;
   for (int i = size / 2 - 1; i >= 0; i--)
   {
      MaxHeapfy(arr, i, size - 1);
   }
   for (int i = size - 1; i > 0; i--)
   {
      temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
      MaxHeapfy(arr, 0, i - 1);
   }
}