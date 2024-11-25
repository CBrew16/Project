//
// Created by Cameron Brewster on 2024-11-25.
//

#include "huffman_tree_traverse.h"

void getCode(HuffmanNode *root, char codes[MAX],char* currentCode,int depth) {
    if(root == NULL) {
        return; // Edge case if the tree doesn't exist
    }

    if(root -> left == NULL && root-> right == NULL) { // The base case to stop recustion; Tells it to read a character
        currentCode[depth] = '\0';
        strcpy(codes[(unsigned char) root-> data], currentCode);
        printf("Character :%c, code: %s\n", root->data, currentCode);
        return;
    }
    currentCode[depth] = '0'; // Appending 0 to the string after the character has been added at the left node
    getCode(root->left, codes, currentCode, depth+1); // pre-order Recursively travesering
    currentCode[depth] = 1; // Appending 1 to the string after the character has been added and right node reached
    getCode(root->right, codes, currentCode, depth+1); // recursively calling left subtree

}


void HuffmanCodes(HuffmanNode *root) {
    char codes[MAX] = {0}; // initializing the array to store codes to zero
    char currentCode[MAX] = {0}; // Initializing the array that keeps track of the codes in the traversal

    getCode(root, codes, currentCode, 0); // Calling the getCode function to append the codes to the string
}