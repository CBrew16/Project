//
// Created by Cameron Brewster on 2024-11-20.
//
#include "huffmann_tree.h"



HuffmanNode *createLeafNode(char data, int frequency) {
    HuffmanNode * newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode)); // Allocating memory
    if(newNode == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE); //Edge case if memory allocation fails
    }

    newNode -> frequency = frequency;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right =NULL; // Initializing leaf node
    return newNode;

}

HuffmanNode *createInternalNodes(HuffmanNode *left, HuffmanNode *right) {
    HuffmanNode *newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode)); // allocating memory for internal node
    if(newNode == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);  //Edge case if memory allocation fails
    }
    newNode -> frequency = left->frequency + right->frequency; // Setting the frequency to the sum of both its child nodes
    newNode -> data = '\0'; // Internal nodes do not hold a character
    newNode -> left = left; // Point to children
    newNode -> right = right;

    return newNode;
}


HuffmanNode* buildHuffmanTree(Queue* queue) {
    while(queue->front != NULL && queue -> front ->next !=NULL) { // Looping through the queue
        void* leftData = priorityDequeue(queue);
        HuffmanNode* left = (HuffmanNode*)leftData; // dequeue the highest priority

        void* rightData = priorityDequeue(queue);
        HuffmanNode* right= (HuffmanNode*)rightData; // dequeue the next highest priority

        HuffmanNode* internalNode = createInternalNodes(left,right);  // Calling the function to create an internal node

        priorityEnqueue(queue,internalNode, getHuffmanWeight);
    }

    return (HuffmanNode*)priorityDequeue(queue);
}


