#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <string>
#include<iostream>


using namespace std;


struct ReviewInfo{
    string movieName;
    string user;
    int time;
    string comment;
};

class PriorityQ
{
      // pointer to array of elements in heap
      ReviewInfo *heapArr;
      // maximum possible size of  heap
      int capacity;
      // Current number of elements in  heap
      int currentSize;

public:
      PriorityQ(){};
      PriorityQ(int capacity);
      int parent(int index);
      int leftChild(int index);
      int rightChild(int index);

      void peek();
      void heapify(int index);
      void pop();
      void insertElement(ReviewInfo value);
      void print();
    bool isEmpty(){return currentSize==0;};

};
#endif