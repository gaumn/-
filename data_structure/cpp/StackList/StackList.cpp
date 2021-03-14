/*
 * @Description: stack的List实现（StackList.cpp）
 * @Author: gaumn 
 * @Date: 2021-02-22 18:29:40
 * @LastEditTime: 2021-02-23 14:14:02
 * @LastEditors: gaumn
 */
template <class T>
StackList<T>::StackList(int len)
{
    // LinkNode<T>* Cur=this->Head;
    LinkNode<T> *Cur;
    for (int i = 0; i < len; i++)
    {
        Cur = new LinkNode<T>();
        if (i == 0)
        {
            this->Head = Cur;
        }
        else
        {
            Cur->Next = this->Head;
            this->Head = Cur;
        }
        Size++;
    }
}
template <class T>
void StackList<T>::Push(const T &data)
{
    LinkNode<T> *Cur = new LinkNode<T>(data);
    if (this->Head == nullptr)
        this->Head = Cur;
    else
    {
        LinkNode<T> *Temp = this->Head;
        Cur->Next = Temp;
        this->Head = Cur;
    }
    Size++;
}
template <class T>
T StackList<T>::Top() const
{
    LinkNode<T> *Cur = this->Head;
    if (Cur != nullptr)
        return Cur->Data;
    else
        return -1;
}
template <class T>
T StackList<T>::Pop()
{
    LinkNode<T> *Cur = this->Head;
    if (Cur == nullptr)
        return -1;
    T Top = Cur->Data;
    this->Head = Cur->Next;
    Size--;
    return Top;
}
template <class T>
void StackList<T>::PrintStack()
{
    LinkNode<T> *Cur = this->Head;
    if (Cur == nullptr)
    {
        cout << "当前栈为空";
    }
    int n = 0;
    while (Size - n > 0 && Cur != nullptr)
    {
        cout << "第" << n++ << "个元素为：" << Cur->Data << endl;
        Cur = Cur->Next;
    }
}
