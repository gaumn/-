/*
 * @Description: PriorityQueue.cpp
 * @Author: gaumn 
 * @Date: 2021-03-21 11:47:22
 * @LastEditTime: 2021-03-21 18:58:21
 * @LastEditors: gaumn
 */
template <class T>
void PriorityQueue<T>::MaxHeapfy(int begin, int end)
{
    int dad = begin, son = 2 * dad + 1, temp;
    while (son <= end)
    {
        if (son + 1 <= end && this->Arr[son + 1] > this->Arr[son])
            son += 1;
        if (this->Arr[dad] > this->Arr[son])
            return;
        else
        {
            temp = this->Arr[dad];
            this->Arr[dad] = this->Arr[son];
            this->Arr[son] = temp;
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

template <class T>
void PriorityQueue<T>::Insert(T &data)
{
    this->Arr.push_back(data);
    this->Size++;
    for (int i = this->Size / 2 - 1; i >= 0; i--)
    {
        MaxHeapfy(i, this->Size - 1);
    }
}
template <class T>
T PriorityQueue<T>::Top()
{
    if (!this->Size)
    {

        cout << "该优先队列为空" << endl;
    }
    return this->Arr[0];
}
template <class T>
void PriorityQueue<T>::Pop()
{
    if (!this->Size)
    {

        cout << "该优先队列为空" << endl;
        return;
    }
    this->Arr.erase(this->Arr.begin());
    this->Size--;
    this->MaxHeapfy(0, this->Size - 1);
}
template <class T>
bool PriorityQueue<T>::Empty()
{
    return (this->Size);
}
template <class T>
int PriorityQueue<T>::size()
{
    return this->Size;
}

template <class T>
void PriorityQueue<T>::Print()
{
    for (int i = 0; i < this->Size; i++)
    {
        cout << this->Arr[i] << "    ";
    }
    cout << endl;
}
