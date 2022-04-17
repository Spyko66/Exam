#include<iostream>  
using std::cout;

#include<string>
using std::string;
using std::getline;

#include<fstream>
using std::ios;
using std::ifstream;

#include<stdlib.h>

#include<cstring>

#include "Exam.h"

int read(string name)
{
	ifstream file;
    string text, route,textRegister;
    int numQuestions;
	
    route="C:/Users/"+name+".txt";        //Insert here the route where you want to save the files what contains the answers of the exam
	file.open(route,ios::in);	
	
	
    if(file.fail())
    {
		cout<<"That exam haven't been registered yet\n";
		exit(1);
    }
	
	while(!file.eof())
        std::getline(file,text);

    file.close();

    numQuestions=text.length();
    savedQuestions=new char[numQuestions+1];

    strcpy(savedQuestions,text.c_str());

    return numQuestions;
}