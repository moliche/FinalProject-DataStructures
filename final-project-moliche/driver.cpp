#include<iostream>
#include "hash.hpp"
#include "PriorityQueue.hpp"
#include <vector>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void displayMenu()//keep it in starter code
{
    cout<<"------------------"<<endl;
    cout<<"1: Build the datastructure (call it only once)"<<endl;
    cout<<"2: Add a movie review tweet"<<endl;
    cout<<"3: Retrieve most recent review for a movie"<<endl;
    cout<<"4: Pop most recent review for a movie"<<endl;
    cout<<"5: Print reviews for a movie"<<endl;
    cout<<"6: Get number of collision"<<endl;
    cout<<"7: Print the table"<<endl;
    cout<<"8: Exit"<<endl;
    cout<<"------------------"<<endl;

}

int main(int argc, char* argv[])
{
    if (argc <3)
    {
        cout<<"need correct num of arg"<<endl;
    }
    string fname =argv[1];
    int tableSize = stoi(argv[2]);
    
    int ch = 0;
    string chs;
    HashTable ht(5);
    bool built = false;
    while(ch!=8)
    {
        displayMenu();
        cout<<"Give your choice >>";
        getline(cin, chs);
        ch =stoi(chs);
        switch (ch)
        {
            case 1:{
                if(!built){
                    built = true;
                    ht.buildBulk(fname);
                }
                else{
                    cout<<"Already built."<<endl;
                }
                break;
            }
            case 2:{
                string movieName; cout<<"Moviename: "; getline(cin, movieName);
                string uname; cout<<"Username: "; getline(cin, uname);
                string comment; cout<<"Comment: "; getline(cin, comment);
                string timest; cout<<"Time: "; getline(cin, timest); int time =stoi(timest);
                
                ReviewInfo movie;
                movie.movieName = movieName;
                movie.user = uname;
                movie.comment = comment;
                movie.time = time;
                
                ht.insertItem(movie);
                break;
            }
            case 3:
                {
                    string mvn;
                    cout<<"movie name:";
                    getline(cin,mvn);
                    node* loc = ht.searchItem(mvn);
                    if(loc)
                    {
                        cout<<"retrieved result"<<endl;
                        loc->pq.peek();
        
                    }
                    else{
                        cout<< "no record found"<<endl;
                    }
                    break;
                }
            case 4:{
                string mvn;
                cout<<"movie name:";
                getline(cin,mvn);
                node* loc = ht.searchItem(mvn);
                if(loc)
                {
                    //cout<<"retrieved result"<<endl;
                    loc->pq.pop();
        
                }
                else{
                    cout<< "no record found"<<endl;
                }
                break;
            }
            case 5:
                {
                    string mvn;
                    cout<<"movie name:";
                    getline(cin,mvn);
                    node* loc = ht.searchItem(mvn);
                    if(loc)
                    {
                        cout<<"Movie: "<<loc->movieName<<endl;
                        loc->pq.print();
                    }
                    else{
                        cout<< "no record found"<<endl;
                    }
                    break;
                }
            case 6:
                cout<< "Number of collision:"<<ht.getNumCollision()<<endl;
                break;
            case 7:
                ht.printTable();
                break;

            case 8:
                cout << "Bye, bye."
                    break;
       
            default:
                cout<<"Give a valid entry"<<endl;
                break;
        }
    }
}
