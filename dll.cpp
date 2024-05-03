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
         newNode->next=START; // STEP 3: make the new mode point to the first node
         if(START != NULL){
            START->prev = newNode; // step 4: make the fisrt node point to the new node

         }
         newNode->prev =NULL;  //step 5: make the nwe node point to null
         START =newNode; //step 6: make the new node the firt node
    }
    else {
        //insert the new mode in the middle or at the end
        Node*current = START; //step 1.a : start from the firts node
        Node*previous = NULL; //step 1.b: previous node is NULL initially

        while (current !=NULL && current->noMhs < newNode->noMhs)
        {                          //step1.c: traverse the list to find the correct position
            previous = current;     // step 1.d :move the previous to currect node
            current = current -> next; //step 1.e : move the current to the next node
        }

        newNode->next =current; // step 4: make the next field of the new node point to current.
        newNode-> prev =previous;   //step 5: make the previous of the new node point to previous .

        if (current != NULL)
        {
            current->prev = newNode;   // step 6 : make rhe previous field of the current node point to the new node
        }
        if (previous != NULL)
        {
           previous->next =newNode; //step 7:make the next field of the previous node point to the new node
        }
        else
        {
            //if previous is sti;; NULL, it means newNode is now the firts node
            START =newNode;
        }
    }
    
}

bool search(int rollNo, Node **previous, Node**current)
 {
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)-> noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return(*current != NULL);

 }
void deleteNode()
{
    Node *previous, *current; 
    int rollNo;

    cout <<"\nEnter the roll number of the student whole record is to be delete: ";
    cin>> rollNo; //step 3:get the roll number to be delete 

    if (START ==NULL)
    {
        cout <<"List is empty"<<endl;
        return;
    }
    current =START;  //Step 1:start from the firts node
    previous = NULL;

    // locate the node to be deleted
    while(current != NULL && current-> noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }
    if (current ==NULL )
    {
        cout <<"\033[31mTge record with roll number "<< rollNo << "not found\033[om" <<endl;
        return;
    }

    //node to be deleted is the firts node
    if(current ==START)
    {
        START = START->next; //step 2:update the start ponter
        if (START != NULL)
        {
            START ->prev =NULL; 
        }
    }
    else
    {
        //node to be deleted is not the firts node
        previous->next =current->next;
            if (current->next !=NULL)
            {
                //if there's a succersor, update its prev pointer
                current ->next->prev =previous;
            }   
    }

    //relse the memory of the node marked as current
    delete current;
    cout <<"\x1b[32mRecord with roll number " <<rollNo <<"deleted\x1b[om" <<endl;

    
}

bool listEmpty()
{
    return (START ==NULL);

}
void traverse()
{
    if(listEmpty())
       cout <<"\nList is empty" <<endl;
    else
    {
        cout <<"\nRecords in ascending order of roll number are : " <<endl; 
        Node *currentNode = START;  //STEP 1
        while (currentNode != NULL) //STEP 2
        {
          cout <<currentNode->noMhs <<" " <<currentNode -> name <<endl; //step 3
          currentNode =currentNode->next;                //step 4
        }
    }
}

void revtraverse()
{
    if(listEmpty())
    cout << "\nList is empty "<<endl;
    else
    {
        cout <<"\nRecords in descending  orde of the roll number are: "<< endl;
        Node*currentNode = START;
        while(currentNode ->next != NULL)
            currentNode = currentNode->next;
        while (currentNode != NULL) 
        {
            cout << currentNode-> noMhs <<" "<<currentNode ->name <<endl;
            currentNode = currentNode->prev;
        }
    }
}

void searchData()
{
    if (listEmpty()== true)
    {
        cout <<"\nList is empty "<<endl;

    }
    Node *prev, *curr;
    prev = curr =NULL;
    cout <<"\nEnter the roll number of the student whose record you want to seacrh:";
    int num;
    if (search(num,&prev, &curr)== false)
       cout <<"\nRecord not found"<< endl;
    else{
        cout <<"\nRecord found"<<endl;
        cout <<"\nRoll number: " <<curr ->noMhs <<endl;
        cout <<"\nName: "<<curr->name <<endl;
    }
}
int main()
{
    while(true)
    {
        try
        {
            
                cout <<"\nMenu"<<endl;
                cout <<"1. Add a record to the list" << endl;
                cout <<"2. Delete a record from the list" << endl;
                cout <<"3. View all records in the ascending order of roll numbers" << endl;
                cout <<"4. View all records in the descending order of roll numbers" << endl;
                cout <<"5. Search for a record in the list" << endl;
                cout <<"6. Exit" << endl;
                cout <<"\nEnter your choice (1-6): ";
                char ch;
                cin >> ch;

                switch (ch)
                {
                    case '1':
                        addNode();
                        break;
                    case '2':
                        deleteNode();
                        break;
                    case '3':
                        traverse();
                        break;
                    case '4':
                        revtraverse();
                        break;
                    case '5':
                        searchData();
                        break;
                    case '6':
                        return 0;
                    default:
                         cout << "\nInvalid option" << endl;
                         break;
                }
            }
             catch (exception &e)
            {
          cout << "Check for the values  entered. " << endl;
            
        }
        
    }
}
