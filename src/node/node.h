//
// Created by koech on 8/17/2023.
//

#ifndef AGEINTERVIEWQUIZ1_NODE_H
#define AGEINTERVIEWQUIZ1_NODE_H

#include <malloc.h>

typedef enum TagType {
    ADD,
    SUB,
    MUL,
    DIV,
} TagType;


typedef struct Node {
    TagType type;
    int result;
} Node;

typedef Node *(*OpFuncWithNodes)(Node *, Node *);

typedef Node *(*OpFuncWithInts)(int, int);

OpFuncWithNodes getOpFuncNodes(TagType type);

OpFuncWithInts getOpFuncInts(TagType type);

#endif //AGEINTERVIEWQUIZ1_NODE_H
