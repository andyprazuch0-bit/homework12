#include "Student.h"
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    Student student1; // CREATE A STUDENT OBJECT NAMED STUDENT1
    student1.getUserInput();
    Student student2(student1); // CREATE STUDENT2 USING THE COPY CONSTRUCTOR
    Student student3 = student1; // CREATE STUDENT3 AND USE THE ASSIGNMENT OPERATOR TO ASSIGN STUDENT1 TO IT

    student2.setScore(0, 100); // MODIFY ONE SCORE IN STUDENT2
    
    std::vector<Student> all = {student1, student2, student3}; // add to vector to print using for loop
    for (int i = 0; i < all.size(); ++i){ // DISPLAY ALL OBJECTS TO VERIFY THAT A DEEP COPY HAS BEEN PERFORMED CORRECTLY 
        std::cout << "Student " << (i+1) << ": " << std::endl;
        all.at(i).display();
    }
}

/*
Why is it no longer necessary to use delete[] if scores is declared as unique_ptr<int[]>? 
    unique_ptr<int[]> is a smart pointer, smart pointers are responsible for deleting data after it goes out of scope.

What happens to the dynamically allocated memory when the object goes out of scope? 
    when unique_ptr goes out of scope, the object owned by it is deleted. 

What is one advantage of using a smart pointer instead of a raw pointer? 
    smart pointers can only have one owner and the object gets automatically deleted once it is out of scope.

Why does using smart pointers help reduce memory leaks? 
    It lowers the chance of something not being deleted whenever pointers change, since smart pointers are responsible for deleting the object, they will always delete it.
*/