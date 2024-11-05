#include <iostream>
#include "gradebook.hpp"

using namespace std;

int main(){

    Gradebook gradebook;

    gradebook.add_student("Bob Bobberson", "ABC123");
    gradebook.add_student("Sam Sammerson", "DEF456");
    gradebook.add_student("Jess Jesserson", "HIJ789");
    gradebook.add_student("Owen Ceresa", "GEH981");
    gradebook.add_student("Louis Kok", "ZOP223");
    gradebook.add_student("Ryan Batt", "PIE314");
    gradebook.add_student("Brandon Thompson", "B$SWAG");

    gradebook.add_assignment("Quiz 1", 100);
    gradebook.add_assignment("Lab 1", 50);
    gradebook.add_assignment("Activity 3", 1);

    gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
    gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
    gradebook.enter_grade("Jess Jesserson", "Lab 1", 49);
    gradebook.enter_grade("Jess Jesserson", "Quiz 1", 93);
    gradebook.enter_grade("Bob Bobberson", "Lab 1", 0);
    gradebook.enter_grade("Owen Ceresa", "Quiz 1", 100);
    gradebook.enter_grade("Louis Kok", "Quiz 1", 95);
    gradebook.enter_grade("Ryan Batt", "Quiz 1", 49);
    gradebook.enter_grade("Brandon Thompson", "Quiz 1", 0);
    gradebook.enter_grade("Owen Ceresa", "Lab 1", 0);
    gradebook.enter_grade("Louis Kok", "Lab 1", 30);
    gradebook.enter_grade("Ryan Batt", "Lab 1", 45);
    gradebook.enter_grade("Brandon Thompson", "Lab 1", 50);
    gradebook.enter_grade("Owen Ceresa", "Activity 3", 1);
    gradebook.enter_grade("Louis Kok", "Activity 3", 1);
    gradebook.enter_grade("Ryan Batt", "Activity 3", 0);
    gradebook.enter_grade("Brandon Thompson", "Activity 3", 1);
    


    gradebook.report();

    return 0;
}