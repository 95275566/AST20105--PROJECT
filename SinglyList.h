//
//  SinglyList.h
//  CH4-SinglyList
//
//  Created by Yik Hin Garret Lai on 13/8/2020.
//  Copyright © 2020 Yik Hin Garret Lai. All rights reserved.
//

#ifndef SinglyList_h
#define SinglyList_h
#include "Node.h"
class SinglyList {
private:
    Node* head;
    int numOfElement;
public:
    SinglyList();
    ~SinglyList();
    bool isEmpty();
    Node* findNode(int);
    void insertNode(int, int);
    void deleteNode(int);
    void displayList();
};
#endif /* SinglyList_h */
