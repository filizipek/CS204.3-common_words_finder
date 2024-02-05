//THE3
//By Filiz Ipek Oktay - 30780

#include <iostream>
#include "DynStack.h"
using namespace std;

//Some of the implementations are retrieved from the Lab Codes.

//Default Constructor
DynamicStringStack::DynamicStringStack(){
    top=nullptr;
}

//Destructor
DynamicStringStack:: ~DynamicStringStack() {
    while (top != nullptr) {//Deallocating the memory
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

// Copy constructor for deep copy
DynamicStringStack::DynamicStringStack(const DynamicStringStack& other) {
    // Initializing top for the new stack
    top = nullptr;

    // Iterating through the other stack and copying its elements
    StackNode* otherNode = other.top;
    StackNode* prevNode = nullptr;
    while (otherNode != nullptr) {
        StackNode* newNode = new StackNode;
        newNode->value = otherNode->value;//Equalizing the value of the nodes
        newNode->next = nullptr;

        if (prevNode == nullptr) {
            top = newNode;
        } else {
            prevNode->next = newNode;
        }

        prevNode = newNode;
        otherNode = otherNode->next;
    }
}


// Pushing back elements to the stack
void DynamicStringStack::push(string elmt){
    StackNode *newNode = nullptr;

    newNode = new StackNode;
    newNode->value = elmt;

    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}

// Popping up elements from the stack
void DynamicStringStack::pop(string &elmt){
    StackNode *temp = nullptr;

    if(isEmpty())
        cout<<"Stack is empty!\n";
    else{
        elmt = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

// If the stack is empty check function
bool DynamicStringStack::isEmpty(){
    bool status;

    if(top==nullptr)
        status=true;

    else
        status=false;

    return status;
}

//This function implementation is for calculating the occurence numbers of the words in the file1 and file2
void DynamicStringStack::occurence(DynamicStringStack &stack1, DynamicStringStack &stack2){
    string poppedWord;
    int minOccurence = 0;
    DynamicStringStack words; //Stack for adding the existing words

    while(!stack1.isEmpty()){//Checking every word in Stack1
        bool exist = false;
        int occurence1 = 0, occurence2 = 0;
        minOccurence = 0;
        //Creating temporary stacks with deep copy
        DynamicStringStack tempStack1(stack1);
        DynamicStringStack tempStack2(stack2);

        tempStack1.pop(poppedWord);//poppedWord is the top element of the tempStack1
        DynamicStringStack tempWords(words);//Cloning the words Stack to tempWords with deep copy
        while(!tempWords.isEmpty()){//Checking if the words are occured once
            string word;
            tempWords.pop(word);
            if(word == poppedWord){//If the word is in the words stack
                exist = true;
                stack1.pop(poppedWord);//The word will not be shown in the output again, we need to pop up
                break;
            }
        }

        if(!exist){//The word has not been added to word Stack
            if(occurence1 == 0)//It means it occured once and has not been pushed into words stack yet
                occurence1++;
            words.push(poppedWord);//Now it is added
            while(!tempStack1.isEmpty()){//Counting the occurence of the word in Stack1
                string isSame;
                tempStack1.pop(isSame);
                if(isSame == poppedWord){//If poppedWords occurs again, increasing the number of occurence
                    occurence1++;
                }
            }

            while (!tempStack2.isEmpty()) {//Counting the occurence of the word in Stack2
                string currentWord;
                tempStack2.pop(currentWord);
                if (currentWord == poppedWord) {
                    occurence2++;
                }
            }

            //Declaring the minimum occurence in both files
            if(occurence1 < occurence2)
                minOccurence = occurence1;
            else
                minOccurence = occurence2;

            //If the word occurs at least one time in both files
            if(minOccurence != 0)
                cout << "The word \"" << poppedWord << "\" occurred at least " << minOccurence << " time(s) in both files.\n";

            //Popping the poppedWord in order to check the other words in the list
            stack1.pop(poppedWord);

        }
    }
}
