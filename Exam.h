#ifndef EXAM_H
#define EXAM_H

#include<string>
using std::string;

int read(string);

extern char *savedQuestions;

class Exam{
    public:
        Exam(int,string);
        void setRightAnswers(void);
        void add(void);
        void toAnswer(void); 

        string name;

    private:
        int nQuestions,*wrongAnswersInt, score=0;
        char *rightAnswers,*answers;
};
#endif