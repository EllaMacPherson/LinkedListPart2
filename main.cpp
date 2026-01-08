/* Ella MacPherson 12/19/25
   Linked List part 1
*/

#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node*& head, Node* prev, Node* current, student* student);
void print(Node*& head, Node* next);
void Delete(Node*& head, Node* next, float GPA);


int main(){

  char input[10];
  bool go = true;

  //start empty
  Node* head = NULL;

  //loop forever
  while (go == true){
    input[0] = '\0';
    cout<<"ADD, DELETE, or PRINT? "<<endl;
    cin>>input;
    cin.ignore();
    //add and ask for inputs
    if(strcmp(input, "ADD") == 0) {

      float inGPA = 0;
      char inName[15];
      int inID;
  
      cout<<"GPA of student?";
      cin>>inGPA;
      cin.ignore();
      cout<<"Name of student?";
      cin.get(inName, 14);
      cin.ignore();
      cout<< "ID of student?";
      cin>>inID;
      cin.ignore();
      //create student pointer to assign to this node
      student* s = new student(inGPA, inName, inID);
      //assign that pointer
      add(head, NULL, head, s);
    }

    //print with recursion
    if(strcmp(input, "PRINT") == 0){
      print(head, head);
    }
    //delete -> only works for 1 node in list just testing destructor
    if(strcmp(input, "DELETE") == 0){
      cout<<"Enter GPA to delete"<<endl;
      float inGPA = 0;
      cin>>inGPA;
      
      Delete(head, head, inGPA);
    }
  }
  
  return 0;
}


//add func, do i need HEAD?
void add(Node*& head, Node* prev, Node* current, student* student){
  //head is always head, current is the one we are looking at at the moment.
  
  if(current == NULL){
    //add when list is empty
    head = new Node(student);
  }
  else{ //list has at least one node    
    if(current->getStudent()->getID() < student->getID()){
      if(current->getNext() == NULL){ //if student ID is still GREATER Than the one its currently on, but th enext is NULL, then we must add it at end of list!!! and NEVER let current become NULL excpet for when list is truly empty
	current->setNext(new Node(student));
	return;
      }
      prev = current;
      add(head, prev, current->getNext(), student);
    }else{ //must add this student IN FRONT of current
      if(prev == NULL){ //we are inserting at beginning of LIST must readjust head
	Node* newNode = new Node(student); //create new node
	newNode->setNext(current);
	head = newNode; //update head as this new node
	return;
      }
      //we are inserting BEFORE the CURRENT node!
      Node* newNode = new Node(student);
      newNode->setNext(current);
      prev->setNext(newNode);
      
    }
    //when the next thing is null, set the 
    
  }
}

//print func
void print(Node*& head, Node* current){
  if(current == head){ //on first one print 
    cout<<"List: ";
  }

  if(current != NULL){ //if we are not at last one in list
    cout<<current->getStudent()->getName()<<", ";
    cout<<current->getStudent()->getID()<<", ";
    cout<<current->getStudent()->getGPA()<<"  ";
    print(head,current->getNext()); //call func again but 1 more down list
  }
}

//delete func, ONLY works with 1 node at the moment
void Delete(Node*& head, Node* next, float GPA){

  if(next == head){ //first call
    cout<<"Matches found: ";
  }

  if(next == NULL){ //when nothing in list
    cout<<"No students currently in list"<<endl;
    return;
  }

  //if finds GPA
  if(next->getStudent()->getGPA() == GPA){
    cout<<next->getStudent()->getName()<<" " <<endl;
    delete next;
    head = NULL; //for 1 student manually set it like this
    return;
  }
  //recursively call again with next node
  Delete(head,next->getNext(), GPA);
}
