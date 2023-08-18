//
// Created by koech on 8/17/2023.
//

#include <stdio.h>
#include "node.h"

Node *addInts(int first, int second);

Node *addNodes(Node *first, Node *second);

Node *subInts(int first, int second);

Node *subNodes(Node *first, Node *second);

Node *mulInts(int first, int second);

Node *mulNodes(Node *first, Node *second);

Node *divdInts(int first, int second);

Node *divdNodes(Node *first, Node *second);

static OpFuncWithNodes opFuncWithNodes[] = {
        addNodes,
        subNodes,
        mulNodes,
        divdNodes
};

static OpFuncWithInts opFuncWithInts[] = {
        addInts,
        subInts,
        mulInts,
        divdInts,
};

Node *newNode() {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("%s: Failed to allocate memory\n", __func__);
        return NULL;
    }
    newNode->type = VALUE;
    return newNode;
}

Node *addInts(int first, int second) {
    Node *result = newNode();
    result->type = ADD;
    result->value = first + second;
    return result;
}

Node *subInts(int first, int second) {
    Node *result = newNode();
    result->type = SUB;
    result->value = second - first;
    return result;
}

Node *mulInts(int first, int second) {
    Node *result = newNode();
    result->type = MUL;
    result->value = second * first;
    return result;
}

Node *divdInts(int first, int second) {
    Node *result = newNode();
    result->type = DIV;
    if (second == 0) {
        return NULL;
    }
    result->value = first / second;
    return result;
}

Node *addNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL) {
        return NULL;
    }
    result->type = ADD;
    result->value = ((first != NULL ? first->value : 0) + (second != NULL ? second->value : 0));
    return result;
}

Node *subNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL) {
        return NULL;
    }
    result->type = SUB;
    result->value = ((second != NULL ? second->value : 0) - (first != NULL ? first->value : 0));
    return result;
}

Node *mulNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL) {
        return NULL;
    }
    result->type = MUL;
    result->value = ((first != NULL ? first->value : 0) * (second != NULL ? second->value : 0));
    return result;
}

Node *divdNodes(Node *first, Node *second) {
    Node *result = newNode();
    if(result == NULL){
        return NULL;
    }
    if (second == NULL) {
        second = newNode();
        second->value = 0;
    }
    result->type = DIV;
    result->value = ((first != NULL ? first->value : 0) / (second != NULL ? second->value : 0));
    return result;
}


OpFuncWithNodes getOpFuncNodes(TagType type) {
    return opFuncWithNodes[type];
}

OpFuncWithInts getOpFuncInts(TagType type) {
    return opFuncWithInts[type];
}
