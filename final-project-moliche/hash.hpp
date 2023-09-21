#ifndef HASH_HPP
#define HASH_HPP

#include <string>
#include "PriorityQueue.hpp"
#include <fstream>

using namespace std;

struct node
{
    string movieName;
    PriorityQ pq;
    struct node *next;
};

class HashTable
{
    int tableSize; // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node **table;

    node *createNode(string movieName, node *next);

    int numCollision;

public:
    HashTable(int bsize); // Constructor

    void buildBulk(string fname);

    void insertItem(ReviewInfo movie);

    unsigned int hashFunction(string key);

    int getNumCollision() { return numCollision; };

    node *searchItem(string key);

    void printTable();
};

#endif
