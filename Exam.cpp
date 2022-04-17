#include<iostream>  
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;
using std::getline;

#include<fstream>
using std::ios;
using std::ofstream;

#include<stdlib.h>

#include "Exam.h"

Exam::Exam(int numberQuestions, string examName){

    nQuestions=numberQuestions;
    name=examName;  
}

void Exam::setRightAnswers(){
    rightAnswers=new char[nQuestions+1];

    for(int i=0;i<nQuestions;i++)
    {
        std::cout<<"Enter the right answer to the question number "<<(i+1)<<std::endl;
        std::cin>>*(rightAnswers+i);
    }
    add();
    std::cout<<"Your exam has been registered sucessfully";
    delete[] rightAnswers;
}


void Exam::add()
{
	ofstream file;
    char outStreamChar;
	string route;    
    
    route="C:/Users/"+name+".txt";        //Insert here the route where you want to save the files what contains the answers of the exam

	file.open(route,ios::app);		
	
    if(file.fail())
    {
		std::cout<<"Error\n";
		exit(1);
    }
    
    for(int i=0;i<nQuestions;i++)
    {
        outStreamChar=*(rightAnswers+i);
        file<<outStreamChar;
    }
	
	file.close();
}

void Exam::toAnswer(){

    int counterWrgAnswers=0;
    char watchMistakesOption;

    rightAnswers=new char[nQuestions];
    answers=new char[nQuestions];
    wrongAnswersInt=new int[nQuestions];

    for(int i=0;i<=nQuestions;i++)
        *(rightAnswers+i)=*(savedQuestions+i);
    
    delete[] savedQuestions;

    for(int i=0;i<nQuestions;i++)
    {
        std::cout<<"Enter the answer to the question number "<<i+1<<std::endl;
        std::cin>>*(answers+i);
    }

    for(int i=0;i<nQuestions;i++)
    {
        if(*(answers+i)==*(rightAnswers+i))
            score++;
            
        else{
            *(wrongAnswersInt+counterWrgAnswers)=i;
            counterWrgAnswers++;
        }
    }
    std::cout<<"Your score is:   "<<score<<" / "<<nQuestions<<std::endl;
    std::cout<<"You want to know which were your mistakes?    y(YES)/any other key(NO)\n";
    std::cin>>watchMistakesOption;

    if(watchMistakesOption=='y')
    {
        for(int i=0;i<counterWrgAnswers;i++)
        {
            std::cout<<"Correct answer to question "<<*(wrongAnswersInt+i)+1<<" is      "<<*(rightAnswers+(*(wrongAnswersInt+i)))<<std::endl;
            std::cout<<"And here you chose       "<<*(answers+(*(wrongAnswersInt+i)))<<"\n\n";
        }
    }

    delete[] savedQuestions;
    delete[] rightAnswers;
    delete[] answers;
    delete[] wrongAnswersInt;
}
