//THE3
//By Filiz Ipek Oktay - 30780

#include <iostream>
#include "DynStack.h"
#include <fstream>
#include <sstream>
using namespace std;

//Function for getting the valid file and opening it
void fileCheck(string &filename, ifstream &file, int &filenum){
    file.open(filename.c_str()); //Opening the file
    while(file.fail()){
        if(filenum == 1){
            cout << "Enter the first file name:\n";
        } else if(filenum == 2){
            cout << "Enter the second file name:\n";
        }
        cin >> filename;
        file.open(filename.c_str());
    }
}

//This function checks the input that indicates the file which words will be sorted
bool isValid(string &choice, bool &firstOpt, bool &secOpt){
    int digitReal = 0;
    string digit;
    if(choice.length() == 1){
        //Converting string to integer
        istringstream iss(choice);
        while (iss >> digit) {
            istringstream ss1(digit);
            ss1 >> digitReal;
        }
        if(digitReal == 1){
            firstOpt = true;
            return true;
        }else if(digitReal == 2){
            secOpt = true;
            return true;
        }else
            return false;
    } else {
        return false;
    }
}

int main() {
    ifstream file1, file2;
    string filename1, filename2, sentence1, sentence2, choice;
    bool firstOpt = false, secOpt = false;
    int filenum = 1;

    //Promting the welcome message
    cout << "This program finds the common words of two files using stacks.\n---\n";
    //Getting the first file
    cout << "Enter the first file name:\n";
    cin >> filename1;
    fileCheck(filename1, file1, filenum);

    //Creating the first stack for words in file1
    DynamicStringStack stack1;
    //Creating a temporary stack in order to reserve the words in the order of exactly the file1
    DynamicStringStack temp1;

    //Pushhing every word into the stack1
    while(getline(file1, sentence1)){
        if(!sentence1.empty()){//Ignoring the empty lines
            //Using isstringstream for getting rid of unwanted white space and taking every word in the line
            istringstream iss(sentence1);
            string word;

            while(iss >> word){
                temp1.push(word);
            }
        }
    }

    while(!temp1.isEmpty()){//Traversing the temp1 for filling stack1 in the correct order
        string popped;
        temp1.pop(popped);
        stack1.push(popped);
    }


    //Getting the second file
    filenum = 2;
    cout << "Enter the second file name:\n";
    cin >> filename2;
    fileCheck(filename2, file2, filenum);

    //Creating the first stack for words in file2
    DynamicStringStack stack2;
    //Creating a temporary stack in order to reserve the words in the order of exactly the file2
    DynamicStringStack temp2;

    //Pushing every word into the stack2
    while(getline(file2, sentence2)){
        if(!sentence2.empty()){//Ignoring the empty lines
            //Using isstringstream for getting rid of unwanted white space and taking every word in the line
            istringstream iss(sentence2);
            string word;

            while(iss >> word){
                temp2.push(word);
            }
        }
    }

    while(!temp2.isEmpty()){//Traversing the temp1 for filling stack1 in the correct order
        string popped;
        temp2.pop(popped);
        stack2.push(popped);
    }


    //Getting the input
    cout << "Choose with respect to which file the result will be sorted to (1: first file, 2: second file):\n";
    cin >> choice;
    cout << "---\n";

    //Asking for the valid input until it is correct
    while(!isValid(choice,firstOpt,secOpt)){
        cout << "Invalid choice" << "\n---\n";
        cout << "Choose with respect to which file the result will be sorted to (1: first file, 2: second file):\n";
        cin >> choice;
        cout << "---\n";
    }

    //If the words will be shown according to the order of file1
    if(firstOpt){
        stack1.occurence(stack1, stack2);
    }else if(secOpt){
        //If the words will be shown according to the order of file2
        stack2.occurence(stack2, stack1);
    }

    return 0;
}
