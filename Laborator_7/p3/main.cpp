#include<iostream>
#include "TreeNode.h"



int main() {
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* node1 = new TreeNode<int>(20);
    TreeNode<int>* node2 = new TreeNode<int>(30);
    TreeNode<int>* node3 = new TreeNode<int>(40);
    TreeNode<int>* node4 = new TreeNode<int>(50);

    root->add_node(node1);
    root->add_node(node2);
    node1->add_node(node3);
    node1->add_node(node4);

    TreeNode<int>* foundNode = root->get_node(node1);
    if (foundNode != nullptr) {
        std::cout << "Nod gasit: " << foundNode->get_value() << std::endl;
    } else {
        std::cout << "Nu s-a gasit nodul!" << std::endl;
    }

    root->delete_node(node2);
    std::cout << "Count dupa stergere" << root->count() << std::endl;


    TreeNode<int>* found = root->find(root, 30);
    if (found != nullptr) {
        std::cout << "Valoare: " << found->get_value() << std::endl;
    } else {
        std::cout << "Nu s-a gasit valoarea" << std::endl;
    }

    TreeNode<int>* newNode = new TreeNode<int>(60);
    root->insert(root, newNode, 1);

    // Test sort method
    root->sort(root, [](const int& a, const int& b) { return a < b; });

    std::cout << "Sortare: ";
    TreeNode<int>* current = root->get_children();
    while (current != nullptr) {
        std::cout << current->get_value() << " ";
        current = current->get_nextSibling();
    }
    std::cout << std::endl;

    return 0;
}
