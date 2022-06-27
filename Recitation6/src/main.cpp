/* @Author
Student Name: Feyza Özen
Student ID : 150190014
Date: 11.01.2022 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <iomanip>

using namespace std;

string file_path;


bool perform_operation(char);
void print_menu();
void listProducts();
void listDay();



int main(int argc, char* argv[])
{
    bool end = false;
    char choice;
    ifstream inFile;

    file_path = argv[1];

    inFile.open(file_path,ios::in);
    if (!inFile.is_open()) 
    {
        cerr << "File cannot be opened";
        return EXIT_FAILURE;
    }

    while (!end)
    {
        print_menu();
        cin >> choice;
        end = perform_operation(choice);
    }
    
    inFile.close();
    return EXIT_SUCCESS;


}


void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "L: List 5 products with the highest revenue for total" << endl;
    cout << "D: List 5 products with the highest revenue for each day" << endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {L, D, E}: ";
}

bool perform_operation(char choice)
{
    bool terminate = false;
    string strday;

    switch (choice)
    {
    case 'L':
    case 'l':
        listProducts();
        break;
    case 'D':
    case 'd':
        listDay();
        break;
    case 'E':
    case 'e':
            terminate = true;
        break;
    default:
        cout << "Error: You have entered an invalid choice" << endl;
        cin >> choice;
        terminate = perform_operation(choice);
        break;
    }
    return terminate;
}

void listProducts()
{
    
    string product;
    double price;
    int quantity;
    string day;
    
    map<string, double> rev_map;

    ifstream inFile;
    inFile.open(file_path, ios::in);
    string l;
    
    getline(inFile,l);
   
    while (getline(inFile,l))
    {
        stringstream line(l);
        line>>product>>price>>quantity;
        //cout << product << " " << price << " " << quantity << " " << day << endl;
      
        if(rev_map.find(product) != rev_map.end()){
            rev_map.find(product)->second += price*quantity;
        }
        else{
            rev_map.insert(pair<string,double>(product,price* quantity));
        }
            
    }

    cout << "5 products with the highest revenue for total are:" << endl;

    multimap<double, string> rev_multimap;
    for (auto const &pair: rev_map) {
        rev_multimap.insert(make_pair(pair.second, pair.first));
    }
 
 
    int i=0;
    for (auto it = rev_multimap.rbegin(); it != rev_multimap.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }

    

    

    inFile.close();

}





void listDay()
{
    string product;
    double price;
    int quantity;
    string day;
    
    map<string, double> monday;
    map<string, double> sunday;
    map<string, double> tuesday;
    map<string, double> wednesday;
    map<string, double> thursday;
    map<string, double> friday;
    map<string, double> saturday;


    ifstream inFile;
    inFile.open(file_path, ios::in);
    string l;
    
    getline(inFile,l);
   
    while (getline(inFile,l))
    {
        stringstream line(l);
        line>>product>>price>>quantity>>day;
       // cout << product << " " << price << " " << quantity << " " << day << endl;
        
        
        if(day=="Monday"){
            if(monday.find(product) != monday.end()){
                    monday.find(product)->second += price*quantity;
            }
            else{
                monday.insert(pair<string,double>(product,price* quantity));
            }
        }

        if(day=="Sunday"){
            if(sunday.find(product) != sunday.end()){
                    sunday.find(product)->second += price*quantity;
            }
            else{
                sunday.insert(pair<string,double>(product,price* quantity));
            }
        }
        if(day=="Tuesday"){
            if(tuesday.find(product) != tuesday.end()){
                    tuesday.find(product)->second += price*quantity;
            }
            else{
                tuesday.insert(pair<string,double>(product,price* quantity));
            }
        }
        if(day=="Wednesday"){
            if(wednesday.find(product) != wednesday.end()){
                    wednesday.find(product)->second += price*quantity;
            }
            else{
                wednesday.insert(pair<string,double>(product,price* quantity));
            }
        }
        if(day=="Thursday"){
            if(thursday.find(product) != thursday.end()){
                   thursday.find(product)->second += price*quantity;
            }
            else{
                thursday.insert(pair<string,double>(product,price* quantity));
            }
        }

        if(day=="Friday"){
            if(friday.find(product) != friday.end()){
                   friday.find(product)->second += price*quantity;
            }
            else{
                friday.insert(pair<string,double>(product,price* quantity));
            }
        }
        

        if(day=="Saturday"){
            if(saturday.find(product) != saturday.end()){
                   saturday.find(product)->second += price*quantity;
            }
            else{
                saturday.insert(pair<string,double>(product,price* quantity));
            }
        }
        
            
    }

    //monday
    cout << "5 products with the highest revenue for Monday are:" << endl;
    multimap<double, string> monday_mm;
    for (auto const &pair: monday) {
        monday_mm.insert(make_pair(pair.second, pair.first));
    }
    int i=0;
    for (auto it = monday_mm.rbegin(); it != monday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }

    
    //sunday
    cout << "5 products with the highest revenue for Sunday are:" << endl;
    multimap<double, string> sunday_mm;
    for (auto const &pair: sunday) {
        sunday_mm.insert(make_pair(pair.second, pair.first));
    }
 
 
    i=0;
    for (auto it = sunday_mm.rbegin(); it != sunday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }
    //tuesday
    cout << "5 products with the highest revenue for Tuesday are:" << endl;
    multimap<double, string> tuesday_mm;
    for (auto const &pair: tuesday) {
        tuesday_mm.insert(make_pair(pair.second, pair.first));
    }
 
 
    i=0;
    for (auto it = tuesday_mm.rbegin(); it != tuesday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }


    //wednesday
    cout << "5 products with the highest revenue for Wednesday are:" << endl;
    multimap<double, string> wednesday_mm;
    for (auto const &pair: wednesday) {
        wednesday_mm.insert(make_pair(pair.second, pair.first));
    }
 
 
    i=0;
    for (auto it = wednesday_mm.rbegin(); it != wednesday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }
    //thursday
    cout << "5 products with the highest revenue for Thursday are:" << endl;
    multimap<double, string> thursday_mm;
    for (auto const &pair: thursday) {
        thursday_mm.insert(make_pair(pair.second, pair.first));
    }
 
 
    i=0;
    for (auto it = thursday_mm.rbegin(); it != thursday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }
    //friday
    cout << "5 products with the highest revenue for Friday are:" << endl;
    multimap<double, string> friday_mm;
    for (auto const &pair: friday) {
        friday_mm.insert(make_pair(pair.second, pair.first));
    }
 
    i=0;
    for (auto it = friday_mm.rbegin(); it != friday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }
    //saturday
    
    cout << "5 products with the highest revenue for Saturday are:" << endl;
    multimap<double, string> saturday_mm;
    for (auto const &pair: saturday) {
        saturday_mm.insert(make_pair(pair.second, pair.first));
    }
 
 
    i=0;
    for (auto it = saturday_mm.rbegin(); it != saturday_mm.rend(); ++it)
    {
        cout << fixed << it->second << " " << setprecision(2) << it->first << endl;
        if(i==4){
            break;
        }
        i++;
    }


 inFile.close();

}