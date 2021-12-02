#include "Student.hpp"
#include <iostream>


Student::Student(const std::string& name, int index) : index_(index), name_(name) {}

std::istream& operator>>(std::istream& is, Student& student) {
    std::cout << "Enter the name of the student: ";
    std::getline(is, student.name_);
    std::cout << "Enter the index of the student: ";
    is >> student.index_;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student name: " << student.name_ << '\n'; 
    os << "Student index: " << student.index_ << '\n'; 
    return os;
}

