#include <iostream>
#include <string>
using namespace std;

struct Node
{
   int noMhs;
   string name;
   Node*next;
   Node*prev;
};

Node*START=NULL;

void addNode(){
    Node* newNode = new Node(); // step 1: create a new node
    cout <<"\nEnter the roll number of the student: ";
    cin>> newNode->noMhs;       //assign value to the data field of the new mode
    cout << "\nEnter the name of the student: ";
    cin>> newNode->name;        //assign value to the data field of the new mode

    //insert the new node in the list
    if (START == NULL || newNode->noMhs <= START->noMhs){

        if (START != NULL && newNode -> noMhs == START->noMhs) {
            cout << "\033[31mDuplicate roll numbers not allowed\033[om" <<endl;
            return;
        }
        //if the list is empty, make the new mode the START
    
    }
    
}


