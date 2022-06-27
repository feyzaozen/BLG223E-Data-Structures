

/* @Author 
Student Name:  FEYZA ÖZEN >
Student ID :  150190014> 
Date: 12.10.2021 */


#include "team.h"

using namespace std;

Team::Team(){
};
string Team::getName() { return name; };
int Team::getCurrentSize() { return current_size; };
int Team::getId() { return id; };
int Team::getCapacity() { return capacity; };
Player *Team::getPlayer(int number)
{
    for (int i = 0; i < current_size; i++)
    {
        if (player_list[i].getNumber() == number)
            return &player_list[i];
    }
    return nullptr;
};
Player *Team::getPlayerList()
{
    return player_list;
};
void Team::setName(string new_name) { name = new_name; };
void Team::setId(int newId) { id = newId; };
void Team::listPlayers()
{
    cout << "Number"
         << " Name"
         << " Age"
         << " #Goals"
         << " #Assists"
         << " #Matches" << endl;
    ;
    for (int i = 0; i < current_size; i++)
    {
        cout << player_list[i].getNumber() << " - ";
        cout << player_list[i].getName() << " - ";
        cout << player_list[i].getAge() << " - ";
        cout << player_list[i].getGoalNumber() << " - ";
        cout << player_list[i].getAssistNumber() << " - ";
        cout << player_list[i].getMatchNumber() << endl;
    }
};
void Team::addPlayer(int number, string name, int age, int goals, int assists, int matches)
{ 

    Player p(name, number, age,  goals,  assists, matches); 

 

    if(current_size==0){

        capacity = 3;
    
        player_list = new Player[capacity];
        player_list[0] = p;
        current_size++;
       
    }
    else{
        for(int i=0;i<current_size;i++){
        if(player_list[i].getNumber() == p.getNumber()){
                cout<<"Player "<<p.getNumber()<<" exists."<<endl;
                return;
            }
        }
        if (capacity==current_size){

            capacity = capacity * 2; 
            
            Player *temp = new Player[capacity];
            
            for (int i = 0; i < current_size; i++){
                
                temp[i] = player_list[i];
            }

            temp[current_size] = p;
        
            delete[] player_list;
        
            player_list = temp;
            current_size += 1;
        
       
        }

        player_list[current_size] = p;
        current_size += 1;

    
    }
return; 
}
    

	// *********************Fill this method 

   
   

bool Team::checkNumber(int number)
{
     for (int i = 0; i < current_size; i++)
    {
        if (player_list[i].getNumber() == number)
            return true;
    }
    return false;
}