//
//  SinglyList.cpp
//  CH4-SinglyList
//
//  Created by Yik Hin Garret Lai on 13/8/2020.
//  Copyright © 2020 Yik Hin Garret Lai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SinglyList.h"
using namespace std;

SinglyList::SinglyList() {
    head = nullptr;
    numOfElement = 0;
}

SinglyList::~SinglyList() {
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    cout << "List is deleted" << endl;
}

bool SinglyList::isEmpty() {
    return (head == nullptr) ? true : false;
}

void SinglyList::displayList() {
    if (!isEmpty()) {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    else {
        cout << "List is empty!" << endl;
    }
}

// index = 0: insert as the beginning node
// index = any pos int: insert AFTER the index-1 node
void SinglyList::insertNode(int index, int val) {
    if (index < 0) {
        cout << "Invalid index!" << endl;
        return;
    }
    // Looking for the right pos
    int currIndex = 1;
    Node* currNode = head;
    while (currNode && index > currIndex) {
        currNode = currNode->next;
        currIndex++;
    }

    // Inappropriate index
    if (index > 0 && currNode == nullptr) {
        cout << "Invalid index!" << endl;
        return;
    }
    // Creating a new node for insertion
    Node* newNode = new Node;
    newNode->data = val;

    // insert at the beginning
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    // insert in between or at the end
    else {
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
}

void SinglyList::deleteNode(int val) {
    Node* prevNode = NULL;
    Node* currNode = head;
    while (currNode && currNode->data != val) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode) {
        if (prevNode) {
            prevNode->next = currNode->next;
            delete currNode;
        }
        else {
            head = currNode->next;
            delete currNode;
        }
        cout << "First encounter node with " << val << " is deleted." << endl;
        return;
    }
    cout << "Node " << val << " not found!" << endl;
    return;
}

Node* SinglyList::findNode(int val) {
    Node* currNode = head;
    while (currNode && currNode->data != val) {
        currNode = currNode->next;
    }
    if (currNode) {
        cout << "Node " << val << " found!" << endl;
        return currNode;
    }
    cout << "Node " << val << " not found!" << endl;
    return nullptr;
}
