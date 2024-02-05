//THE3
//By Filiz Ipek Oktay - 30780

//Some class declerations are retrieved from the Lab Codes.
#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <string>
using namespace std;

struct StackNode{
    string value;
    StackNode *next;
};

class DynamicStringStack{
private:
    StackNode* top;

public:
    DynamicStringStack(void);
    DynamicStringStack(const DynamicStringStack& other);
    ~DynamicStringStack(void);
    void push(string);
    void pop(string &);
    bool isEmpty(void);
    void occurence(DynamicStringStack &stack1, DynamicStringStack &stack2);
};


#endif
