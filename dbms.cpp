#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    std::string name;
    int rollNumber;
    double grade;
};

int main() {
    // Create and open a text file for writing
    ofstream outFile("student_records.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return 1;
    }

    // Create student records and write them to the file
    Student students[] = {
        {"Alice", 101, 85.5},
        {"Bob", 102, 92.0},
        {"Charlie", 103, 78.5}
    };

    for (const Student& student : students) {
        outFile << student.name << "," << student.rollNumber << "," << student.grade << "\n";
    }

    // Close the file
    outFile.close();

    std::cout << "Student records have been stored." << std::endl;

    return 0;
}
