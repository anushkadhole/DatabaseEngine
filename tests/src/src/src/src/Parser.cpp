#include "Parser.h"
#include <iostream>

void Parser::parseCommand(const std::string &command) {
    // Basic command parsing logic
    if (command.find("insert") != std::string::npos) {
        std::cout << "Parsing insert command: " << command << std::endl;
    } else if (command.find("query") != std::string::npos) {
        std::cout << "Parsing query command: " << command << std::endl;
    }
}
