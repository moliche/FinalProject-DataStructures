// CPP program to implement hashing with chaining
#include <iostream>
#include "hash.hpp"
#include <sstream>
#include <string>

using namespace std;

node *HashTable::createNode(string movieName, node *next)
{
    PriorityQ pq = PriorityQ(50);
    node *nn = new node;

    nn->movieName = movieName;
    nn->pq = pq;
    nn->next = next;

    return nn;
}

HashTable::HashTable(int bsize)
{
    table = new node *[bsize];
    tableSize = bsize;
    numCollision = 0;

    for (int i = 0; i < bsize; i++)
    {
        table[i] = NULL;
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        node *itr = table[i];
        cout << i << "|";
        while (itr != nullptr)
        {
            cout << itr->movieName << "-->";
            itr = itr->next;
        }
        cout << "NULL" << endl;
    }
}

// function to calculate hash function
unsigned int HashTable::hashFunction(string movieName)
{
    unsigned int index = 0;

    int sum = 0;

    for (int i = 0; i < movieName.length(); i++)
    {
        sum += (int)movieName[i];
    }

    index = sum % tableSize;

    return index;
}

node *HashTable::searchItem(string movieName)
{
    int index = hashFunction(movieName);
    node *head = table[index];
    while (head != nullptr)
    {
        if (head->movieName == movieName)
        {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

// function to insert
void HashTable::insertItem(ReviewInfo movie)
{
    int index = hashFunction(movie.movieName);

    node *temp = searchItem(movie.movieName);
    node *head = table[index];

    if (temp != nullptr)
    {
        while (head != nullptr)
        {
            if (head->movieName == movie.movieName)
            {
                head->pq.insertElement(movie);
                break;
            }
            head = head->next;
        }
    }
    else
    {
        if (table[index] != nullptr)
        {
            numCollision++;
        }
        node *nn = createNode(movie.movieName, head);
        table[index] = nn;
        nn->pq.insertElement(movie);

        
    }
}

void HashTable::buildBulk(string fname)
{

    ifstream ifile;
    ifile.open(fname.c_str());
    if (!ifile.is_open())
    {
        cout << "wrong file name or path" << endl;
        return;
    }
    string line;
    while (getline(ifile, line))
    {
        stringstream s(line);
        string temp;
        string uname, comment, movieName;
        int time;
        getline(s, movieName, ';'); // cout<<movieName<<endl;
        getline(s, comment, ';');   // cout<<comment<<endl;
        getline(s, uname, ';');     // cout<<uname<<endl;
        getline(s, temp, ';');      // cout<<temp<<endl;
        time = stoi(temp);

        ReviewInfo movie;
        movie.movieName = movieName;
        movie.user = uname;
        movie.comment = comment;
        movie.time = time;
        insertItem(movie);
    }
}
