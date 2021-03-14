/*
 * @Description: 
 * @Author: gaumn 
 * @Date: 2021-03-05 22:06:15
 * @LastEditTime: 2021-03-07 18:40:08
 * @LastEditors: gaumn
 */
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->Root = nullptr;
}
template <class T>
void BinarySearchTree<T>::Insert(const T &data, BinaryTreeNode<T> *TreeNode)
{
    // if (TreeNode == nullptr)
    // {
    //     TreeNode = new BinaryTreeNode<T>(data);
    // }
    // else
    // {
    //     if (TreeNode->val > data)
    //     {
    //         cout << "Insert right" << endl;
    //         Insert(data, TreeNode->right);
    //     }
    //     else
    //     {
    //         cout << "Insert left" << endl;
    //         Insert(data, TreeNode->left);
    //     }
    // }
    if (TreeNode->val <= data)
    {
        // cout << "Insert right" << endl;
        if (TreeNode->right != nullptr)
        {
            Insert(data, TreeNode->right);
        }
        else
        {
            TreeNode->right = new BinaryTreeNode<T>(data);
        }
    }
    else
    {
        // cout << "Insert left" << endl;
        if (TreeNode->left != nullptr)
        {
            Insert(data, TreeNode->left);
        }
        else
        {
            TreeNode->left = new BinaryTreeNode<T>(data);
        }
    }
}
template <class T>
void BinarySearchTree<T>::Insert(const T &data)
{
    if (this->Root != nullptr)
    {
        Insert(data, this->Root);
    }
    else
    {
        this->Root = new BinaryTreeNode<T>(data);
    }
}
template <class T>
BinaryTreeNode<T> *BinarySearchTree<T>::Search(const T &data, BinaryTreeNode<T> *TreeNode)
{
    if (TreeNode == nullptr)
    {
        cout << "该值不在此树中" << endl;
        return nullptr;
    }
    if (TreeNode->val == data)
    {
        return TreeNode;
    }
    else if (TreeNode->val < data)
    {
        return Search(data, TreeNode->right);
    }
    else
    {
        return Search(data, TreeNode->left);
    }
}
template <class T>
BinaryTreeNode<T> *BinarySearchTree<T>::Search(const T &data)
{
    return Search(data, this->Root);
}

template <class T>
void BinarySearchTree<T>::Preorder(BinaryTreeNode<T> *TreeNode)
{
    if (TreeNode == nullptr)
        return;
    Preorder(TreeNode->left);
    cout << TreeNode->val << endl;
    Preorder(TreeNode->right);
}
template <class T>
void BinarySearchTree<T>::Preorder()
{
    if (this->Root != nullptr)
    {
        Preorder(this->Root->left);
        cout << this->Root->val << endl;
        Preorder(this->Root->right);
    }
    else
    {
        cout << "该树为空";
    }
}
