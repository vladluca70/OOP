#include <iostream>

template <typename T>
class TreeNode
{
private:
    T value;
    TreeNode* parent;
    TreeNode* children;
    TreeNode* nextSibling;
    int childCount;

public:
    TreeNode(const T& val, TreeNode* par = nullptr)
    {
        value=val;
        parent=par;
        children=nullptr;
        nextSibling=nullptr;
        childCount=0;
    }

    T get_value() const
    {
        return value;
    }

    TreeNode* get_children() const
    {
        return children;
    }

    TreeNode* get_nextSibling() const
    {
        return nextSibling;
    }

    void add_node(TreeNode* node)
    {
        if (children == nullptr)
        {
            children = node;
        }
        else
        {
            TreeNode* temp = children;
            while (temp->nextSibling != nullptr)
            {
                temp = temp->nextSibling;
            }
            temp->nextSibling = node;
        }
        node->parent = this;
        childCount++;
    }

    TreeNode* get_node(TreeNode* parent = nullptr)
    {
        if (parent == nullptr)
            return this;
        else
        {
            TreeNode* current = children;
            while (current != nullptr)
            {
                if (current->value == parent->value)
                {
                    return current;
                }
                current = current->nextSibling;
            }
            return nullptr;
        }
    }

    void delete_node(TreeNode* node)
    {
        if (node == nullptr)
            return;

        TreeNode* child = node->children;
        while (child != nullptr)
        {
            TreeNode* next = child->nextSibling;
            delete_node(child);
            child = next;
        }

        if (node->parent != nullptr)
        {

            TreeNode* prevSibling = nullptr;
            TreeNode* sibling = node->parent->children;
            while (sibling != nullptr && sibling != node)
            {
                prevSibling = sibling;
                sibling = sibling->nextSibling;
            }
            if (prevSibling == nullptr)
            {
                node->parent->children = node->nextSibling;
            }
            else
            {
                prevSibling->nextSibling = node->nextSibling;
            }
            delete node;
            node->parent->childCount--;
        }
        else
        {
            delete node;
        }
    }

    TreeNode* find(TreeNode* root, const T& value)
    {
        if (root == nullptr)
            return nullptr;

        if (root->value == value)
            return root;

        TreeNode* child = root->children;
        while (child != nullptr)
        {
            TreeNode* found = find(child, value);
            if (found != nullptr)
                return found;
            child = child->nextSibling;
        }
        return nullptr;
    }

    void insert(TreeNode* parent, TreeNode* newNode, int index)
    {
        if (parent == nullptr)
            return;

        if (index == 0)
        {
            newNode->nextSibling = parent->children;
            parent->children = newNode;
        }
        else
        {
            TreeNode* current = parent->children;
            int i = 0;
            while (i < index - 1 && current != nullptr)
            {
                current = current->nextSibling;
                i++;
            }
            if (current != nullptr)
            {
                newNode->nextSibling = current->nextSibling;
                current->nextSibling = newNode;
            }
        }
        newNode->parent = parent;
        parent->childCount++;
    }

    void sort(TreeNode* node, bool (*compare)(const T&, const T&))
    {
        if (node == nullptr)
            return;

        TreeNode* current = node->children;
        while (current != nullptr)
        {
            TreeNode* minNode = current;
            TreeNode* nextNode = current->nextSibling;
            while (nextNode != nullptr)
            {
                if (compare(nextNode->value, minNode->value))
                    minNode = nextNode;
                nextNode = nextNode->nextSibling;
            }
            if (minNode != current)
            {
                T temp = minNode->value;
                minNode->value = current->value;
                current->value = temp;
            }
            current = current->nextSibling;
        }
    }

    int count(TreeNode* node = nullptr)
    {
        if (node == nullptr)
            return childCount;

        int cnt = 0;
        TreeNode* current = node->children;
        while (current != nullptr)
        {
            cnt++;
            cnt += count(current);
            current = current->nextSibling;
        }
        return cnt;
    }
};
