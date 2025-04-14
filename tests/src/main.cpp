#include <iostream>
#include "Database.h"
#include "Parser.h"

int main() {
    std::cout << "Welcome to the File-Based Database Engine!" << std::endl;

    // Initialize database
    Database db("data.db");
    
    // Create B+ Tree index
    BTree index(3); // Degree 3 for simplicity
    db.setIndex(&index);

    // Command loop
    std::string input;
    while (true) {
        std::cout << "Enter SQL-like command: ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        Parser parser;
        parser.parseCommand(input);
    }
    
    return 0;
}
