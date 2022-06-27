/* @Author
Student Name: Feyza Özen
Student ID : 150190014
Date: 26.10.2021 */

#include <iostream>
#include <stdio.h>

#include "linkedList.h"

using namespace std;

LinkedList::LinkedList(){
    head = NULL;
}

int LinkedList::getLength() 
{ 
    int counter = 0; 
    Node* temp = head; 
    while (temp) 
    { 
        temp = temp->next;
        counter++;  
    } 
    return counter; 
} 
 
 

void LinkedList::insertNode(char data){
    
    Node* newnode = new Node(data);

    if(head == NULL){
        head = newnode;
        return;
    }

    Node *temp = head;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = newnode;
}

void LinkedList::swap(Node* temp1,Node* temp2){
    char temp = temp1->letter;
    temp1->letter = temp2->letter;
    temp2->letter = temp;
}

void LinkedList::reorderList(){
    //FILL THIS FUNCTION ACCORDINGLY
    
    int size = getLength();
    Node* temp1 = head;
    Node* temp2 = head->next;
    int i,j,k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (temp1->letter < temp2->letter) {
                swap(temp1,temp2);
            }
            temp2 = temp2->next;
        }
        temp2 = head;
        temp1 = head->next;
       for (k = 0; k < i; k++) {
            temp1 = temp1->next;
        }
    
    }
  
};







void LinkedList::removeDublicates(){
    //FILL THIS FUNCTION ACCORDINGLY

    Node* temp = head;
    Node* temp2 = new Node();
    temp2 = NULL;

    while (temp->next)
    {
        if (temp->letter == temp->next->letter)
        {
            temp2 = temp->next->next;
            delete[] temp->next;
            temp->next = temp2;
        }
        else{
            temp = temp->next;
        }
        
        
    
    }
};

void LinkedList::reverseList(){
    //FILL THIS FUNCTION ACCORDINGLY  
    int size = getLength();
    Node* temp1 = head;
    Node* temp2 = head->next;
    int i,j,k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (temp1->letter > temp2->letter) {
                swap(temp1,temp2);
            }
            temp2 = temp2->next;
        }
        temp2 = head;
        temp1 = head->next;
        for (k = 0; k < i; k++) {
            temp1 = temp1->next;
        }
    
    }
  
};

void LinkedList::printList(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->letter<<" ";
        temp = temp->next;
    }
    cout<<endl;
};


