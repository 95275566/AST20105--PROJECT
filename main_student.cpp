//
//  main.cpp
//  AST20105 - Lab 10 - Hashing-Separate-Chaining
//  Fu Tsz Hin
//  H10002473

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Node.h"
#include "SinglyList.h"
using namespace std;

// Task 3B: HashFcnChaining - to compute and return a hash value
int hashFcnChaining(const int& key, const int& size) {
    // hash value = key % size of the hash table
    int value = key % size;
    return value;
}

int main(int argc, const char* argv[]) {
    // insert code here...

    int n; //Size of data

    // Random seed
    srand(time(NULL));

    // Prompt users for # of numbers to be generated
    std::cout << "Input number of random numbers: ";
    cin >> n;

    // Create an int array with size and initialise each slot with a random
    // number.  Duplicate numbers are allowed.
    int* arrNum = new int[n];
    for (int i = 0; i < n; i++) {
        arrNum[i] = rand() % n + 1; // generate numbers from 1 to n
    }

    // Task 1: create an int variable, m, as the size of the hash table and intialize it
    // Hint: Size in chaining should be n / 3
    // Code here...
    int m = n / 3;  //table size

        // Task 2: Create an array of SinglyList, i.e. an array of linked list
        // Code here...
    SinglyList** hash = new SinglyList * [m]; //Create an array of single NULL node. This is the hash table

    for (int i = 0; i < m; i++) 
    {
        hash[i] = new SinglyList;  
    }  //initial the array

        // Task 3A: Insert random numbers stored in arrNum to the Hash Table.
        //         Hash value for each random number must be generated via the hash
        //         function.  You may use the random number itself as the key.

        for (int i = 0; i < n; i++) {
            // Code here...
            int HaVa = hashFcnChaining(arrNum[i], m);
            //cout << "Array index: " << HaVa << " | Random number which need to insert: " << arrNum[i]   << endl;
            hash[HaVa]->insertNode(0, arrNum[i]);
        }

    cout << "Size of array list: " << m << endl;

    // Task 4: Display all elements in the Hash Table
    for (int i = 0; i < m; i++) {
        // Code here...
       
        cout << "List " << i << ": ";
        hash[i]->displayList();
    }

    // Free the memory
    for (int i = 0; i < m; i++) {
        //Task 5: free memory of each linked list in the array
        delete hash[i];
    }
    delete[] arrNum;

    return 0;
}
