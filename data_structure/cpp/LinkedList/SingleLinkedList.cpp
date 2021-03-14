/*
 * 内存泄漏总结：
 * 局部定义的指针，指向new出来的节点（堆空间），指针就可以返回
 * （如果指针没有指向堆空间，函数退出后，栈内的内容销毁，返回的指针也就是无效的）
 * 链表析构的时候delete 这些new出来的节点的地址（堆指针）
 */
template <class T>
SingleLinkedList<T>::SingleLinkedList(int len)
{
    LinkNode<T> *Cur;
    for (size_t i = 0; i < len; i++)
    {
        Cur = new LinkNode<T>();
        if (i == 0)
        {
            Head = Cur;
            Tail = Cur;
        }
        else
        {
            Tail->Next = Cur;
            Tail = Tail->Next;
        }
        ListSize++;
    }
}

template <class T>
void SingleLinkedList<T>::DeleteList()
{
    LinkNode<T> *Temp, *DeleteTemp;
    DeleteTemp = this->Head;
    while (DeleteTemp != nullptr)
    {
        Temp = DeleteTemp->Next;
        free(DeleteTemp);
        DeleteTemp = Temp;
        ListSize--;
    }
    Head = nullptr;
    Tail = nullptr;
}
template <class T>
void SingleLinkedList<T>::Delete(const T &Data)
{
    LinkNode<T> *Prev = this->Head;
    LinkNode<T> *Temp = nullptr;
    if (this->Head->Data == Data)
    {
        this->Head = Prev->Next;
        Prev->Next = nullptr;
        free(Prev);
        ListSize--;
    }

    while (Prev->Next != nullptr && Prev->Next->Data != Data)
    {
        Prev = Prev->Next;
    }
    if (Prev->Next != nullptr && Prev->Next != this->Tail)
    {
        Temp = Prev;
        Temp->Next = Prev->Next->Next;
        free(Prev->Next);
        ListSize--;
    }
    else
    {
        this->Tail = Prev;
        this->Tail->Next = nullptr;
        free(Prev->Next);
        ListSize--;
    }
}
template <class T>
int SingleLinkedList<T>::Find(const T &Data) const
{
    LinkNode<T> *Temp = this->Head;
    int position = 0;
    while (Temp != nullptr && Temp->Data != Data)
    {
        Temp = Temp->Next;
        position++;
    }
    if (Temp == nullptr)
        return -1;
    else
        return position;
}
template <class T>
LinkNode<T> *SingleLinkedList<T>::FindPosition(const int position) const
{
    if (position > ListSize)
        return nullptr;
    LinkNode<T> *Temp = this->Head;
    for (int i = 0; i < position; i++)
    {
        Temp = Temp->Next;
    }
    return Temp;
}
template <class T>
void SingleLinkedList<T>::InsertHead(const T &data)
{
    LinkNode<T> *temp = new LinkNode<T>(data);
    if (Head == nullptr)
    {
        Head = temp;
        Tail = temp;
    }
    else
    {
        temp->Next = Head;
        Head = temp;
    }
    // 局部变量不需要free，除非使用malloc申请时
    ListSize++;
}
template <class T>
void SingleLinkedList<T>::InsertTail(const T &data)
{
    LinkNode<T> *temp = new LinkNode<T>(data);
    if (Head == nullptr)
    {
        Head = temp;
        Tail = temp;
    }
    else
    {
        Tail->Next = temp;
        Tail = Tail->Next;
    }
    ListSize++;
}
template <class T>
void SingleLinkedList<T>::Reverse()
{
    if (this->Head == this->Tail)
        return;
    this->Tail = this->Head;
    LinkNode<T> *Prev = this->Head;
    LinkNode<T> *Cur = Prev->Next;
    while (Cur != nullptr)
    {
        LinkNode<T> *Temp = Cur->Next;
        Cur->Next = Prev;
        Prev = Cur;
        Cur = Temp;
    }
    this->Head = Prev;
    this->Tail->Next = nullptr;
}
template <class T>
void SingleLinkedList<T>::PrintList() const
{
    int n = 0;
    LinkNode<T> *temp = this->Head;
    while (temp != nullptr)
    {
        cout << "第" << n++ << "个:" << temp->Data << endl;
        temp = temp->Next;
    }
}