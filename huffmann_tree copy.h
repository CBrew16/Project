//
// Created by Cameron Brewster on 2024-11-20.
//
// huffman_tree.h: Define the structure and operations for the Huffman Tree.
// priority_queue.h: Define the priority queue for storing nodes.
// compression.h: Functions for compressing files.
// decompression.h: Functions for decompressing files.
// file_utils.h: Utility functions for reading and writing files.


#ifndef HUFFMANN_TREE_H
#define HUFFMANN_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implementation.h"

//A structure for the node's to be placed in tree
typedef struct {
 int index;
 unsigned int weight;
} node_t;


// Create a Tree data structure for the Huffman Nodes
typedef struct HuffmanNode {
 int frequency;
 struct HuffmanNode* left;
 struct HuffmanNode* right;
 char data;
}HuffmanNode;


// A create node function
HuffmanNode *createLeafNode(char data, int frequency);
/* Parameters :
 a character to hold the node's symbol in tree
 a integer to hold the frequency associated with that character - Frequency of letters
 */



HuffmanNode *createInternalNodes(HuffmanNode* left, HuffmanNode *right);


HuffmanNode* buildHuffmanTree(Queue* queue);





#endif //HUFFMANN_TREE_H
