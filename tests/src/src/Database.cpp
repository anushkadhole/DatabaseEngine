#include "Database.h"
#include <iostream>
#include <fstream>

Database::Database(const std::string &filename) : filename(filename) {
    // Initialize database storage
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::ofstream newFile(filename);
        std::cout << "Created new database file: " << filename << std::endl;
    }
    file.close();
}

void Database::setIndex(BTree* index) {
    this->index = index;
}

void Database::insert(const std::string &key, const std::string &value) {
    std::cout << "Inserting key: " << key << " with value: " << value << std::endl;
    index->insert(key, value);
}

void Database::query(const std::string &key) {
    std::string value = index->search(key);
    std::cout << "Query result for key " << key << ": " << value << std::endl;
}
