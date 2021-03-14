/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-02-23 13:08:57
 * @LastEditTime: 2021-02-23 15:19:40
 * @LastEditors: gaumn
 */
template <class T>
QueueList<T>::QueueList(int len)
{
    LinkNode<T> *Cur;
    for (int i = 0; i < len; i++)
    {
        Cur = new LinkNode<T>();
        if (i == 0)
        {
            this->Head = Cur;
            this->Tail = this->Head;
        }
        else
        {
            this->Tail->Next = Cur;
            this->Tail = this->Tail->Next;
        }
        Size++;
    }
}
template <class T>
void QueueList<T>::DeleteList()
{
    LinkNode<T> *Temp, *DeleteTemp;
    DeleteTemp = this->Head;
    while (DeleteTemp != nullptr)
    {
        Temp = DeleteTemp->Next;
        free(DeleteTemp);
        DeleteTemp = Temp;
        Size--;
    }
    this->Head = nullptr;
    this->Tail = nullptr;
}
template <class T>
T QueueList<T>::front() const
{
    LinkNode<T> *Cur = this->Head;
    if (Cur == nullptr)
        cout << "队列为空，返回未定义值";
    return Cur->Data;
}
template <class T>
T QueueList<T>::back() const
{
    LinkNode<T> *Cur = this->Tail;
    if (Cur == nullptr)
        cout << "队列为空，返回未定义值";
    return Cur->Data;
}
template <class T>
void QueueList<T>::push(const T &obj)
{
    LinkNode<T> *Cur = new LinkNode<T>(obj);
    if (this->Head == nullptr)
    {
        this->Head = Cur;
        this->Tail = Cur;
    }
    else
    {
        this->Tail->Next = Cur;
        this->Tail = this->Tail->Next;
    }
    Size++;
}
template <class T>
void QueueList<T>::pop()
{
    LinkNode<T> *Cur = this->Head;
    if (Cur == nullptr)
    {
        cout << "没有可以删除的元素" << endl;
    }
    else
    {
        this->Head = this->Head->Next;
        free(Cur);
    }
}
template <class T>
void QueueList<T>::PrintQueue()
{
    LinkNode<T> *Cur = this->Head;
    if (Cur == nullptr)
    {
        cout << "当前队列为空" << endl;
    }
    int n = 0;
    while (Size - n > 0 && Cur != nullptr)
    {
        cout << "第" << n++ << "个元素为：" << Cur->Data << endl;
        Cur = Cur->Next;
    }
}