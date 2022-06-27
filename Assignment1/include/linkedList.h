/* @Author
Student Name: Feyza Özen
Student ID : 150190014>
Date: 10.11.2021 */

#ifndef _H
#define _H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class materialNode{
    public:
        char id;
        int weight;
        materialNode* next;
};

class wagonNode{
    public:
        int wagonId;
        materialNode* material;
        wagonNode* next;
};

class Train{  

    wagonNode* head;
    
    public:
        void addWagon();
        int getlength();

        
        wagonNode* getLastWagon(char letter);
        void create();
        void addMaterial(char,int);
        void deleteFromWagon(char, int); 
        void printWagon(); //Prints wagon info
};

#endif