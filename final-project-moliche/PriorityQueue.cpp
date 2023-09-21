#include "PriorityQueue.hpp"
#include <limits.h>
using namespace std;

void swap(ReviewInfo *a, ReviewInfo *b)
{
  ReviewInfo temp = *a;
  *a = *b;
  *b = temp;
}

/*
Constructor for our MinHeap implementation
*/
PriorityQ::PriorityQ(int cap)
{
  capacity = cap;
  heapArr = new ReviewInfo[capacity];
  currentSize = 0;
}

/*
Finds the parent of a node, given its index.
*/
int PriorityQ::parent(int index)
{
  return index - 1 / 2;
}

/*
Returns the left child of a node.
*/
int PriorityQ::leftChild(int index)
{
  return 2 * index + 1;
}

/*
Returns the right child of a node.
*/
int PriorityQ::rightChild(int index)
{
  return 2 * index + 2;
}

void PriorityQ::peek()
{

  if (currentSize > 0)
  {
    cout << "Movie: " << heapArr[0].movieName << endl;
    cout << "User:" << heapArr[0].user << endl;
    cout << "Comment:" << heapArr[0].comment << endl;
    cout << "Time:" << heapArr[0].time << endl;
  }
  else
  {
    cout << "no record found" << endl;
  }
}

void PriorityQ::heapify(int i)
{
  int left = leftChild(i);
  int right = rightChild(i);
  int max = i;

  if (left < currentSize && heapArr[left].time > heapArr[max].time)
  {
    max = left;
  }
  if (right < currentSize && heapArr[right].time > heapArr[max].time)
  {
    max = right;
  }

  if (max != i)
  {
    swap(&heapArr[max], &heapArr[i]);
    heapify(max);
  }
}

void PriorityQ::insertElement(ReviewInfo movie)
{
  heapArr[currentSize] = movie;
  currentSize++;

  for (int i = currentSize / 2 - 1; i >= 0; i--)
  {
    heapify(i);
  }
 
}

/*
Prints the elements in the heap
*/
void PriorityQ::print()
{
  for (int i = 0; i < currentSize; i++)
  {
    cout << "\t"
         << "User: " << heapArr[i].user << endl;
    cout << "\t"
         << "Comment: " << heapArr[i].comment << endl;
    cout << "\t"
         << "Time: " << heapArr[i].time << endl;
    cout << "\t"
         << "=====" << endl;
  }
}

// Method to remove maximum element (or root) from max heap
void PriorityQ::pop()
{
  if (currentSize > 0)
  {
    swap(&heapArr[0], &heapArr[currentSize - 1]);
    // delete heapArr[currentSize - 1];

    currentSize--;
    heapify(0);
  }
}
