//
// Created by ASUS on 3/17/2024.
//

#ifndef GITHUBLIB_LINKEDLIST_H
#define GITHUBLIB_LINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int newData){

    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node) );
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertAtBeginning(struct Node** head,int newData){

    struct Node* newNode = createNode(newData);
    newNode->next=*head;
    if(*head != NULL){

        (*head)->prev = newNode;

    }
    *head = newNode;
}

void append(struct Node** head, int newData){

    struct Node* newNode = createNode(newData);
    struct Node* last = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }
    last->next = newNode;

    newNode->prev = last;

}

void displayForward(struct Node* node){

    if(node == NULL){
        return;
    }
    while ( node!= NULL ){
        printf("Data : %d\n",node->data);
        node = node->next;
    }
}

void displayBackward(struct Node* node){
    struct Node* temp[100];
    int i = 0;
    if(node == NULL){
        return;
    }
    while ( node!= NULL ){
        temp[i] = node;
        node = node->next;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("Data: %d\n", temp[j]->data);
    }
}

void deleteData(struct Node **head, int data) {
    struct Node* current = *head;

    if (current->data == data) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    while (current != NULL) {
        if (current->data == data) {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

#endif //GITHUBLIB_LINKEDLIST_H
