/* @Author
Student Name: Feyza Özen
Student ID : 150190014
Date: 26.10.2021 */

#include <iostream> 
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "linkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
    system("clear");


	//system("clear");// make this line as comment if you are compiling on Linux or Mac
	//system("cls"); // make this line as comment if you are compiling on Windows
    LinkedList newLinkedList;

    fstream input_file;
    input_file.open(argv[1], ios::in);

    char letter;
    


    
    if (!input_file.is_open()) {
        cout << "Error" << endl;
        return EXIT_FAILURE;
    }
    input_file >> letter;
    newLinkedList.insertNode(letter);

    while (input_file.get(letter)) {
        
        input_file >> letter;
        newLinkedList.insertNode(letter);
        
        
        
    }

    

    
    input_file.close();

    cout <<  newLinkedList.getLength() << endl;
    

    cout<<"Readed letters in linked list: ";
    newLinkedList.printList();

    
    newLinkedList.reorderList();
    cout<<"After reordering: ";
    
    newLinkedList.printList();

    newLinkedList.removeDublicates();
    cout<<"After removing dublicates: ";
    newLinkedList.printList();
   
    newLinkedList.reverseList();
    cout<<"Reversed list: ";
    newLinkedList.printList();


    return EXIT_SUCCESS;
}