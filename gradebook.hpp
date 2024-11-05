#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <iostream>

struct StudentName {
    std::string first_name;
    std::string last_name;
    int student_number;
};

struct AssignmentData{
    int total_score;
};

struct GradeData {
    std::string full_name;
    int score;
};

class Gradebook {
private:
    std::map<std::string, StudentName> student_data;
    std::map<std::string, AssignmentData> assignment_data;
    std::map<std::string, std::map<std::string, GradeData>> grade_data;
    int assignment_count = 0;
    int student_count = 0;

public:
    void add_student(std::string full_name, std::string id){
        std::istringstream seperated_name(full_name);
        std::string first_name, last_name;

        seperated_name >> first_name >> last_name;

        student_data[id] = {first_name, last_name, student_count++};
    }

    void add_assignment(std::string assignment_name, int total_score){
        if (assignment_data.find(assignment_name) == assignment_data.end()){
            assignment_data[assignment_name] = {total_score};
            assignment_count++;
        } else {
            std::cout << "Assignment already exists!" << std::endl;
        }
    }

    void enter_grade(std::string full_name, std::string assignment_name, int individual_score){
        std::string student_id;
        for (auto& student : student_data) {
            if (student.second.first_name + " " + student.second.last_name == full_name) {
                student_id = student.first;
                break;
            }
        }

        if (student_id.empty()) {
            std::cout << "Student was not found!" << std::endl;
            return;
        }
             
        if (assignment_data.find(assignment_name) != assignment_data.end()){
            AssignmentData& assignment = assignment_data[assignment_name];

            if (individual_score >= 0 && individual_score <= assignment.total_score){
                grade_data[student_id][assignment_name] = {full_name, individual_score};
            } else {
                std::cout << "Invalid grade! Must be less than or equal to " << assignment.total_score << " and greater than or equal to 0. << endl;";
            }
        } else {
            std::cout << "Assignment does not exist!" << std::endl;
        }
    }

    void report(){
        std::cout << "Last_Name,First_Name,Student_Id";

        for (const auto& assignment : assignment_data) {
            std::cout << "," << assignment.first;
            }
            std::cout << std::endl;

            for (const auto& student : student_data) {
            const StudentName& name = student.second; 
            std::cout << name.last_name << "," << name.first_name << "," << student.first; 
            
            
            for (const auto& assignment : assignment_data) {
                const std::string& assignment_name = assignment.first;
                if (grade_data[student.first].find(assignment_name) != grade_data[student.first].end()) {
                    std::cout << "," << grade_data[student.first][assignment_name].score; 
                } else {
                    std::cout << ",none";
                }
            }
            std::cout << std::endl;
        }
    }

};

#endif // GRADEBOOK_H