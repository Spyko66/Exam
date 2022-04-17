#include<iostream>  
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;
using std::getline;

#include "Exam.h"

char *savedQuestions;

int main(){
    char option;
    int numQuestions;
    string eName;

    std::cout<<"What do you want to do?  Press n to add a new exam.  Press a to answer an exam.\n";
    std::cin>>option;

    if(option=='n'){
        std::cout<<"What is its name?    ";
        std::getline(cin,eName);
        std::cout<<"How many questions it has?  ";
        std::cin>>numQuestions;
       
        Exam aNewExam=Exam(numQuestions,eName);
        aNewExam.setRightAnswers();
    }

    else if(option=='a'){
        std::cout<<"What is the name of the exam you are looking for?       ";
        std::getline(cin,eName);
        numQuestions=read(eName);

        Exam aNewExam=Exam(numQuestions,eName);
        aNewExam.toAnswer();
    }

    else
        std::cout<<"Invalid option\n";
    
    return 0;
}

