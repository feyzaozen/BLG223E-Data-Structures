
/* @Author
Student Name: Feyza Özen
Student ID : 150190014>
Date: 10.11.2021 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

using namespace std;

void Train::create(){
    head = NULL;
}; 


void Train::deleteFromWagon(char material, int weight){
    
    wagonNode* tempclr = head;
    int count2;
        
    if(material=='A'){
        wagonNode *lastt = getLastWagon('A');
        if(weight<=lastt->material->weight){
            lastt->material->weight -= weight;
        }else{
            int remain = weight - (lastt->material->weight);
            lastt->material->weight = 0;
            int count = remain / 2000;
            int remain2 = remain - (2000*count);
            count2 = getlength()-(count + 2);
            wagonNode* temp = head; 
            for(int i = 0; i < count2 ; i++){
                temp = temp->next;
            }
            tempclr = temp->next;
            temp->material->weight -=remain2;
            temp = temp->next;
            for(int i = 0; i < count ; i++){
                    temp->material->weight=0;
                    temp = temp->next;
            }
        }
    }   
    else if(material=='B'){
        wagonNode *lastt = getLastWagon('B');
        if(weight<=lastt->material->next->weight){
            lastt->material->next->weight -= weight;
        }else{
            int remain = weight - (lastt->material->next->weight);
            lastt->material->next->weight = 0;
            int count = remain / 2000;
            int remain2 = remain - (2000*count);
            count2 = getlength()-(count + 2);
            wagonNode* temp = head; 
            for(int i = 0; i < count2 ; i++){
                    temp = temp->next;
            }
            tempclr = temp->next;
            temp->material->next->weight -=remain2;
            temp = temp->next;
            for(int i = 0; i < count ; i++){
                    temp->material->next->weight=0;
                    temp = temp->next;
            }
        }
            

    }
    else if(material=='C'){
        wagonNode *lastt = getLastWagon('C');
        if(weight<=lastt->material->next->next->weight){
            lastt->material->next->next->weight -= weight;
                
        }else{
            int remain = weight - (lastt->material->next->next->weight);
            lastt->material->next->next->weight = 0;
            int count = remain / 2000;
            int remain2 = remain - (2000*count);
            count2 = getlength()-(count + 2);
            wagonNode* temp = head; 
            for(int i = 0; i < count2 ; i++){
                temp = temp->next;
            }
            tempclr = temp->next;
            temp->material->next->next->weight -=remain2;
            temp = temp->next;
            for(int i = 0; i < count ; i++){
                temp->material->next->next->weight=0;
                temp = temp->next;
            }
        }


    }
    else if(material=='D'){
            wagonNode *lastt = getLastWagon('D');
            if(weight<=lastt->material->next->next->next->weight){
                lastt->material->next->next->next->weight -= weight;
                
            }else{
                int remain = weight - (lastt->material->next->next->next->weight);
                lastt->material->next->next->next->weight = 0;
                int count = remain / 2000;
                int remain2 = remain - (2000*count);
                count2 = getlength()-(count + 2);
                wagonNode* temp = head; 
                for(int i = 0; i < count2 ; i++){
                    temp = temp->next;
                }
                tempclr = temp->next;
                temp->material->next->next->next->weight -=remain2;
                temp = temp->next;
                for(int i = 0; i < count ; i++){
                    temp->material->next->next->next->weight=0;
                    temp = temp->next;
                }
            }
        
    } 


    wagonNode* tempdel = head;
    wagonNode* prevv = tempdel;

    int s = getlength()- count2;
    for(int i = 0;i<s;i++){
        prevv = tempdel;
        
        tempdel  = tempdel -> next;

    }
    if(tempdel){
        prevv = tempdel;
        tempdel  = tempdel -> next;
    }
    
    
    int fullFlag = 1;
    while(tempdel){
        if(tempdel->material->weight == 0 &&
        tempdel->material->next->weight == 0 &&
        tempdel->material->next->next->weight == 0 &&
        tempdel->material->next->next->next->weight == 0){
            
            fullFlag = 0;
        }
        else{
            fullFlag = 1;
        }
        
        if(fullFlag == 0){

            wagonNode* current = tempdel;
            
     
            if (current != NULL){
                prevv->next = prevv->next->next;
                tempdel = current->next; 
                delete current;    
            }       
        
        
        }
        else if(tempdel->next!=NULL){
        tempdel = tempdel->next;
    }
 
      
    }    
    


};  

int Train::getlength(){
    int counter = 0; 
    wagonNode* temp = head; 
    while (temp) 
    { 
        temp = temp->next;
        counter++;  
    } 
    return counter; 
}


wagonNode* Train::getLastWagon(char letter){
        
    int count = getlength();
     
    wagonNode* temp = head; 
    

    
    for(int i = 0 ; i < count-1;i++){
        if(letter == 'A'){
            if(temp->material->weight == 0 ||temp->next==NULL )
            return temp;

            temp = temp->next;
        }
        if(letter == 'B'){
            if(temp->material->next->weight == 0 ||temp->next==NULL )
            return temp;

            temp = temp->next;
        }
        if(letter == 'C'){
            if(temp->material->next->next->weight == 0 ||temp->next==NULL )
            return temp;
            temp = temp->next;  
        }
        if(letter == 'D'){
            if(temp->material->next->next->next->weight == 0 ||temp->next==NULL )
            return temp;

            temp = temp->next;  
        }
    }

return temp;}; 

void Train::addWagon(){

    wagonNode* newWagon = new wagonNode();
      
    materialNode* A = new materialNode();
    materialNode* B = new materialNode();
    materialNode* C = new materialNode();
    materialNode* D = new materialNode();

    
    
    A->id = 'A';
    B->id = 'B';
    C->id = 'C';
    D->id = 'D';
    
    A->weight = 0;
    B->weight = 0;
    C->weight = 0;
    D->weight = 0;

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = NULL;
    
    if(head == NULL){
        head = newWagon;
        newWagon->wagonId = getlength();
        newWagon->material = A;
        return;

        
    }

    wagonNode *temp = head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = newWagon;
    newWagon->wagonId = getlength();
    newWagon->material = A;



return;}

void Train::addMaterial(char material, int weight){
    
    int count = weight/2000;
     
    if(head == NULL){
        addWagon();
    
        if(weight<=2000){
            if(material=='A'){
                head->material->weight = weight; 
            }else if(material=='B'){
                head->material->next->weight = weight;
            }else if(material=='C'){
                head->material->next->next->weight = weight;
            }else if(material=='D'){
                head->material->next->next->next->weight = weight;
            }  
        }
        else if(weight > 2000){
  
            wagonNode* temp = head;

            if(material=='A'){
                temp->material->weight = 2000;
                
            }else if(material=='B'){
                temp->material->next->weight = 2000;
                    
            }else if(material=='C'){
                temp->material->next->next->weight = 2000;
                    
            }else if(material=='D'){
                temp->material->next->next->next->weight = 2000;
                    
            }  

            for(int i = 0; i < count-1;i++){
             
             addWagon(); 

                if(material=='A'){
                    temp->next->material->weight = 2000;
                    temp = temp->next;
                }else if(material=='B'){
                    temp->next->material->next->weight = 2000;
                    temp = temp->next;
                }else if(material=='C'){
                    temp->next->material->next->next->weight = 2000;
                    temp = temp->next;
                }else if(material=='D'){
                    temp->next->material->next->next->next->weight = 2000;
                    temp = temp->next;
                } 
            } 

            addWagon();

            if(material=='A'){
                    temp->next->material->weight = weight-(2000*count);
                    
            }else if(material=='B'){
                    temp->next->material->next->weight = weight-(2000*count);
                    
            }else if(material=='C'){
                    temp->next->material->next->next->weight = weight-(2000*count);
                    
            }else if(material=='D'){
                    temp->next->material->next->next->weight = weight-(2000*count);
                   
            } 
         
            

        }
   

    }
    else{
        if(material=='A'){
        wagonNode *lastt = getLastWagon('A');
        if(lastt->material->weight + weight<=2000){
            lastt->material->weight += weight;

        }else if (lastt->material->weight+weight>2000){
            if(lastt->next==NULL){
                addWagon(); 
            }
            int remain = weight - (2000-lastt->material->weight);
            wagonNode* temp = lastt;
            lastt->material->weight = 2000;

            int count = remain /2000;

            for(int i = 0; i <count;i++){
                if(temp->next ==NULL)
                    addWagon();
                temp->next->material->weight = 2000;
                temp = temp->next;
            }

            if(remain-(count*2000!=0)){
                if(temp->next ==NULL)      
                addWagon();

                temp->next->material->weight = remain-(2000*count);
            }
           

        }


    }else if(material=='B'){
        wagonNode *lastt = getLastWagon('B');
        if(head->material->next->weight+weight<=2000){
            head->material->next->weight += weight;
        }else if (head->material->next->weight+weight>2000){
            if(lastt->next==NULL){
                addWagon(); 
            }
            int remain = weight - (2000-lastt->material->next->weight);
            wagonNode* temp = lastt;
            lastt->material->next->weight = 2000;

            int count = remain /2000;

            for(int i = 0; i <count;i++){
                 if(temp->next ==NULL)
                    addWagon();
                temp->next->material->next->weight = 2000;
                temp = temp->next;
            }
            if(remain-(count*2000!=0)){
                if(temp->next ==NULL)
                    addWagon();

            temp->next->material->next->weight = remain-(2000*count); 
            }    
        }

    }else if(material=='C'){
        wagonNode *lastt = getLastWagon('C');
        if(head->material->next->next->weight + weight<=2000){
            head->material->next->next->weight += weight;
        }else if (head->material->next->next->weight+weight>2000){
             if(lastt->next==NULL){
                addWagon(); 
            }
           int remain = weight - (2000-lastt->material->next->next->weight);
            wagonNode* temp = lastt;
            lastt->material->next->next->weight = 2000;

            int count = remain /2000;

            for(int i = 0; i <count;i++){
                 if(temp->next ==NULL)
                    addWagon();
                temp->next->material->next->next->weight = 2000;
                temp = temp->next;
            }
            if(remain-(count*2000!=0)){
                if(temp->next ==NULL)
                    addWagon();

            temp->next->material->next->next->weight = remain-(2000*count); 
            }    
        }
        
    }else if(material=='D'){
        wagonNode *lastt = getLastWagon('D');
        if(head->material->next->next->next->weight+weight<=2000){
            head->material->next->next->next->weight += weight;
        }else if (head->material->next->next->next->weight+weight>2000){
             if(lastt->next==NULL){
                addWagon(); 
            }
            int remain = weight - (2000-lastt->material->next->next->next->weight);
            wagonNode* temp = lastt;
            lastt->material->next->next->next->weight = 2000;

            int count = remain /2000;

            for(int i = 0; i <count;i++){
                 if(temp->next ==NULL)
                    addWagon();
                temp->next->material->next->next->next->weight = 2000;
                temp = temp->next;
            }
            if(remain-(count*2000!=0)){
             if(temp->next ==NULL)
                    addWagon();

            temp->next->material->next->next->next->weight = remain-(2000*count);
            }     
        }

        
    }  
  
    }
}; 

void Train::printWagon(){
    wagonNode* tempWagon = head;

    if(tempWagon == NULL){
            cout<<"Train is empty!!!"<<endl;
            return;
    }

    while(tempWagon != NULL){
        materialNode* tempMat = tempWagon->material;
        cout<<tempWagon->wagonId<<". Wagon:"<<endl; 
        while (tempMat != NULL){
            
            if(tempMat->weight!=0){
               cout<<tempMat->id<<": "<<tempMat->weight<<"KG, ";   
            }
            
            
            tempMat = tempMat->next;  
        }
        cout<<endl; 
        tempWagon = tempWagon->next;
    }
    cout<<endl;
}