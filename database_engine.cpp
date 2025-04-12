#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    int id;
    std::string name;
    int age;
};

std::vector<Student> database;

// Function to load students from file
void loadDatabase(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) return;

    Student s;
    while (infile >> s.id >> s.name >> s.age) {
        database.push_back(s);
    }

    infile.close();
}

// Function to save students to file
void saveDatabase(const std::string& filename) {
    std::ofstream outfile(filename);
    for (const auto& s : database) {
        outfile << s.id << " " << s.name << " " << s.age << "\n";
    }
    outfile.close();
}

// Function to insert student
void insertStudent(int id, const std::string& name, int age) {
    for (const auto& s : database) {
        if (s.id == id) {
            std::cout << "Error: Student with ID " << id << " already exists.\n";
            return;
        }
    }
    database.push_back({id, name, age});
    std::cout << "Inserted successfully.\n";
}

// Function to select all students
void selectStudents() {
    std::cout << "ID\tName\tAge\n";
    for (const auto& s : database) {
        std::cout << s.id << "\t" << s.name << "\t" << s.age << "\n";
    }
}

// Function to delete student by ID
void deleteStudent(int id) {
    auto it = std::remove_if(database.begin(), database.end(), [id](const Student& s) {
        return s.id == id;
    });

    if (it != database.end()) {
        database.erase(it, database.end());
        std::cout << "Deleted student with ID " << id << ".\n";
    } else {
        std::cout << "No student found with ID " << id << ".\n";
    }
}

// Parse and execute commands
void parseCommand(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string word;
    iss >> word;

    if (word == "INSERT") {
        std::string into, table, values, name;
        int id, age;
        char comma;
        iss >> into >> table >> values;
        iss.ignore(); // skip '('
        iss >> id >> comma >> name >> comma >> age;
        insertStudent(id, name, age);
    } else if (word == "SELECT") {
        std::string star, from, table;
        iss >> star >> from >> table;
        selectStudents();
    } else if (word == "DELETE") {
        std::string from, table, where, col;
        int id;
        char equal;
        iss >> from >> table >> where >> col >> equal >> id;
        deleteStudent(id);
    } else if (word == "EXIT") {
        std::cout << "Saving and exiting...\n";
        saveDatabase("db.txt");
        exit(0);
    } else {
        std::cout << "Unknown command.\n";
    }
}

int main() {
    std::cout << "Welcome to DatabaseEngine (C++)\n";
    std::cout << "Supported commands:\n";
    std::cout << "- INSERT INTO students VALUES (1, Alice, 21)\n";
    std::cout << "- SELECT * FROM students\n";
    std::cout << "- DELETE FROM students WHERE id = 1\n";
    std::cout << "- EXIT\n\n";

    loadDatabase("db.txt");

    std::string input;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, input);
        parseCommand(input);
    }

    return 0;
}
