//
// Created by Cameron Brewster on 2024-11-25.
//

#ifndef HUFFMAN_TREE_TRAVERSE_H
#define HUFFMAN_TREE_TRAVERSE_H
#include "huffmann_tree.h"
#define MAX 128

void getCode(HuffmanNode *root, char codes[MAX],char* currentCode,int depth);

void HuffmanCodes(HuffmanNode *root);

#endif //HUFFMAN_TREE_TRAVERSE_H
