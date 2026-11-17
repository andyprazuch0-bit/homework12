#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

Student::Student(){ // constructor
    name = "";
    numScores = 0;
    scores = nullptr;
}

Student::Student(std::string setName, int setNumScores){ // 2 parameter constructor
    name = setName;
    numScores = setNumScores;
    scores = new int[numScores];
}

Student::Student(const Student& original){ // copy constructor
    name = original.name;
    numScores = original.numScores;
    scores = new int[numScores];
    for(int i = 0; i < numScores; i++){
        scores[i] = original.scores[i];
    }
}

Student& Student::operator=(const Student& original){ // assignment operator
    if (this != &original){
        delete[] scores;
        name = original.name;
        numScores = original.numScores;
        scores = new int[numScores];
        for(int i = 0; i < numScores; i++){
            scores[i] = original.scores[i];
        }
    }
    return *this;
}

Student::~Student(){ // destructor
    delete[] scores;
}

void Student::getUserInput(){ // gets scores 
    std::cout << "Enter Student Name: " << std::endl;
    std::cin >> name;
    std::cout << "How many test scores would you like to enter? " << std::endl;
    std::cin >> numScores;

    delete[] scores;
    scores = new int[numScores];

    std::cout << "Enter " << numScores << " scores: " << std::endl;
    int value = 0;
    for (int i = 0; i < numScores; ++i){
        std::cin >> value;
        scores[i] = value;
    }
}

void Student::setScore(int index, int setScore){ // sets score
    scores[index] = setScore;
}

double Student::getAverage(){ // returns average 
    double total = 0;
    for (int i = 0; i < numScores; ++i){
        total += scores[i];
    }
    return (total / numScores);
}

void Student::display(){
    std::cout << "Name: " << name << std::endl; // display name
    std::cout << "Scores: ";
    for (int i = 0; i < numScores; ++i){ // display scores 
        std::cout << scores[i] << " ";
    }
    std::cout << "Average: " << std::fixed << std::setprecision(1) << getAverage() << std::endl; // display average
}

