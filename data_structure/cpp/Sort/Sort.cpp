/*
 * @Descripttion: Sort.cpp
 * @Author: gaumn
 * @Date: 2021-03-12 20:41:10
 * @LastEditors: gaumn
 * @LastEditTime: 2021-03-20 21:40:20
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
void CountingSort(vector<int> &arr) //计数排序
{
   int size = arr.size();
   int maxs = arr[0], mins = arr[0];
   for (int i = 1; i < size; i++)
   {
      maxs = max(maxs, arr[i]);
      mins = min(mins, arr[i]);
   }
   int base = 0 - mins;
   vector<int> buckets(maxs - mins + 1, 0);
   for (int i = 0; i < size; i++)
   {
      buckets[arr[i] + base]++;
   }
   int index = 0, i = 0;
   size = buckets.size();
   while (index < size)
   {
      while (buckets[index])
      {
         arr[i++] = index - base;
         buckets[index]--;
      }
      index++;
   }
}
int MaxBits(vector<int> &arr)
{
   int maxs = arr[0];
   for (int i = 1; i < arr.size(); i++)
   {
      maxs = max(maxs, arr[i]);
   }
   int d = 0;
   while (maxs >= 1)
   {
      maxs /= 10;
      d++;
   }
   return d;
}
void RadixSort(vector<int> &arr) //基数排序
{
   int maxbit = MaxBits(arr);
   // cout << maxbit << endl;
   int size = arr.size();
   int temp[size];
   int count[10];
   int i, j, k;
   int radix = 1;
   for (i = 1; i <= maxbit; i++) //进行d次排序
   {
      for (j = 0; j < 10; j++)
         count[j] = 0; //归零处理
      for (j = 0; j < size; j++)
      {
         k = (arr[j] / radix) % 10; //当前bit数
         count[k]++;                //统计出现个数
      }
      for (j = 1; j < 10; j++)
      {
         count[j] = count[j] + count[j - 1]; //记录当前位置
      }
      for (j = size - 1; j >= 0; j--)
      {
         k = (arr[j] / radix) % 10; //当前bit数
         temp[count[k] - 1] = arr[j];
         count[k]--;
      }
      for (j = 0; j < size; j++)
         arr[j] = temp[j];
      radix = radix * 10;
   }
}
ListNode *insert(ListNode *head, int val)
{
   ListNode dumNode;
   ListNode *temp = new ListNode(val);
   dumNode.Next = head;
   ListNode *pre, *curr;
   pre = &dumNode;
   curr = head;
   while (nullptr != curr && curr->Data <= val)
   {
      pre = curr;
      curr = curr->Next;
   }
   temp->Next = curr;
   pre->Next = temp;

   return dumNode.Next;
}

ListNode *Merge(ListNode *head1, ListNode *head2)
{
   ListNode dumNode;
   ListNode *dum = &dumNode;
   while (nullptr != head1 && nullptr != head2)
   {
      if (head1->Data <= head2->Data)
      {
         dum->Next = head1;
         head1 = head1->Next;
      }
      else
      {
         dum->Next = head2;
         head2 = head2->Next;
      }
      dum = dum->Next;
   }
   if (nullptr != head1)
      dum->Next = head1;
   if (nullptr != head2)
      dum->Next = head2;
   return dumNode.Next;
}

void BucketSort(vector<int> &arr) //桶排序
{
   int size = arr.size();
   vector<ListNode *> buckets(BUCKET_NUM, (ListNode *)(0));
   for (int i = 0; i < size; i++)
   {
      int index = arr[i] / BUCKET_NUM;
      ListNode *head = buckets[index];
      buckets[index] = insert(head, arr[i]);
   }
   ListNode *head = buckets[0];
   for (int i = 1; i < BUCKET_NUM; i++)
   {
      head = Merge(head, buckets[i]);
   }
   for (int i = 0; i < size; i++)
   {
      arr[i] = head->Data;
      head = head->Next;
   }
}
