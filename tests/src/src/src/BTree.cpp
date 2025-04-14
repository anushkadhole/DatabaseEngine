#include "BTree.h"
#include <iostream>

BTree::BTree(int degree) : degree(degree) {}

void BTree::insert(const std::string &key, const std::string &value) {
    // Insert logic for B+ Tree
    std::cout << "Inserting into B+ Tree: " << key << std::endl;
}

std::string BTree::search(const std::string &key) {
    // Simulated search logic
    std::cout << "Searching B+ Tree for: " << key << std::endl;
    return "Sample value for " + key;
}
