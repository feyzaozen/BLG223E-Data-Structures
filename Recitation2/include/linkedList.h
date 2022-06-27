/* @Author
Student Name: Feyza Özen
Student ID : 150190014
Date: 26.10.2021 */


#ifndef _H
#define _H

#include <iostream>
#include <stdio.h>

using namespace std;

class Node{
    public:
        char letter;
        Node* next;
        Node(){
            letter = 'x';
            next = NULL;
        }
        Node(char l){
            letter = l;
            next = NULL;
        }
};


class LinkedList{

    Node* head;

    public:
        
        LinkedList();
        void insertNode(char data);



        int getLength();
        void reorderList();
        void removeDublicates();
        void reverseList();
        void printList();
        void swap(Node*,Node*);
};

#endif