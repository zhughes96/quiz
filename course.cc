/**
*@file course.cc
*@author Zachary Hughes
*3/1/18
*@section DESCRIPTION
* This file has the course object. It gives the information and basic
*functions for a user friendly time to compare and add them
*/
#include "course.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

course::course(){
    hours = 0.0;
}

/**
*adds a course
* this function takes in a file and reads in line by line what the course
* will be and the parameters will be the course number, grade receieved, and
* how many credit hours the course is.
@param takes in a file/user input
@return nothing
*/
void course::input(std::istream& ins){
    if(ins == cin){
	cout<<"Course Number: ";
	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
	cout<<"Grade received: ";
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
 	cout<<"Credit hours: ";
    	ins>>hours;
	upper_course();   // makes all lower case letters into caps
    }
    else{
    	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
    	ins>>hours;
    }
}

/**
*Shows the output of all the courses
*Can output to a file or to the screen of the course information
*that one is pointing too
@param takes in an output type
@return the course information
*/
void course::output(std::ostream& outs)const{
    if(outs == cout){
	outs<<"Course Number:"<<course_number<<endl;
	outs<<"Grade received:"<<grade<<endl;
	outs<<"Credit hours:"<<setprecision(2)<<hours<<endl;
      }
     else{
        outs<<course_number<<endl;
        outs<<grade<<endl;
        outs<<setprecision(2)<<hours<<endl;
      }
}


double course::get_number_grade()const{
    if(grade == "A") return 4.0;
    if(grade == "A-") return 3.667;
    if(grade == "B+") return 3.333;
    if(grade == "B") return 3.0;
    if(grade == "B-") return 2.667;
    if(grade == "C+") return 2.333;
    if(grade == "C") return 2.0; 
    if(grade == "C-") return 1.667;
    if(grade == "D+") return 1.333; 
    if(grade == "D") return 1.0;
    if(grade == "D-") return 0.667; 
    if(grade == "F") return 0.0;
    else return 0;
}

void course::set_course(std::string num, std::string grad, double hrs){
	course_number = num;
	grade = grad;
	hours = hrs;
}

istream& operator >>(istream& ins, course& c){
    c.input(ins);
    return ins;
}

ostream& operator <<(ostream& outs, const course& c){
    c.output(outs);
    return outs;
}

void course::upper_course(){
    for(int i =0; i<course_number.length(); ++i)
	course_number[i] = toupper(course_number[i]);
}
