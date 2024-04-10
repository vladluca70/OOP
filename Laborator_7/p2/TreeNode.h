#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

float operator"" _Kelvin(long double kelvin) {
    return kelvin - 273.15; // Convert Kelvin to Celsius
}

float operator"" _Fahrenheit(long double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9; // Convert Fahrenheit to Celsius
}

// Tree template
template <typename T>
class TreeNode {
private:
    T value;
    TreeNode* parent;
    TreeNode* children[10]; // Assuming max 10 children per node
    int numChild    ren;

public:
    TreeNode(T val, TreeNode* par = nullptr) : value(val), parent(par), numChildren(0) {}

    void add_node(TreeNode* node) {
        if (numChildren < 10) {
            children[numChildren++] = node;
        } else {
            std::cerr << "Cannot add more children to this node." << std::endl;
        }
    }

    TreeNode* get_node(TreeNode* par = nullptr) {
        return (par == nullptr) ? this : par;
    }

    void delete_node(TreeNode* node) {
        if (node == nullptr)
            return;

        // Recursively delete children
        for (int i = 0; i < node->numChildren; ++i) {
            delete_node(node->children[i]);
        }

        // Remove from parent's children list
        if (node->parent != nullptr) {
            for (int i = 0; i < node->parent->numChildren; ++i) {
                if (node->parent->children[i] == node) {
                    // Shift remaining children to fill the gap
                    for (int j = i; j < node->parent->numChildren - 1; ++j) {
                        node->parent->children[j] = node->parent->children[j + 1];
                    }
                    node->parent->numChildren--;
                    break;
                }
            }
        }

        delete node;
    }

    TreeNode* find(T param, bool (*compareFunc)(T, T)) {
        if (compareFunc(value, param)) {
            return this;
        }
        TreeNode* found = nullptr;
        for (int i = 0; i < numChildren && found == nullptr; ++i) {
            found = children[i]->find(param, compareFunc);
        }
        return found;
    }

    void insert(TreeNode* node, int index) {
        if (index < 0 || index > numChildren) {
            std::cerr << "Invalid index." << std::endl;
            return;
        }

        // Shift children to make space for the new node
        for (int i = numChildren; i > index; --i) {
            children[i] = children[i - 1];
        }
        children[index] = node;
        node->parent = this;
        numChildren++;
    }

    void sort(bool (*compareFunc)(T, T) = nullptr) {
        if (compareFunc == nullptr) {
            // Using default comparison
            compareFunc = [](T a, T b) { return a < b; };
        }
        for (int i = 0; i < numChildren - 1; ++i) {
            for (int j = i + 1; j < numChildren; ++j) {
                if (compareFunc(children[i]->value, children[j]->value)) {
                    TreeNode* temp = children[i];
                    children[i] = children[j];
                    children[j] = temp;
                }
            }
        }
    }

    int count(TreeNode* node = nullptr) {
        if (node == nullptr)
            node = this;

        int totalCount = 0;
        for (int i = 0; i < node->numChildren; ++i) {
            totalCount++;
            totalCount += count(node->children[i]);
        }
        return totalCount;
    }
};

#endif // TREENODE_H



