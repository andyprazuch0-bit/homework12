#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private: 
    std::string name;
    int numScores;
    int* scores;

public: 
    Student(); // constructor 
    Student(std::string setName, int setNumScores); // 2 parameter constructor
    Student(const Student& original); // copy constructor
    Student& operator=(const Student& original); // assignment operator 
    ~Student(); // destructor

    void getUserInput(); // gets scores
    void setScore(int index, int score); // sets score
    double getAverage(); // returns average
    void display(); // displays student name, all scores, and the average score

};  

#endif 

