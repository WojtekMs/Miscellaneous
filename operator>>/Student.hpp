#pragma once

#include <string>
#include <istream>
#include <ostream>

class Student {
    int index_{};
    std::string name_{};
    public:
    Student() = delete;
    Student(const std::string& name, int index);
    friend std::istream& operator>>(std::istream& is, Student& student);
    friend std::ostream& operator<<(std::ostream& is, const Student& student);
};
