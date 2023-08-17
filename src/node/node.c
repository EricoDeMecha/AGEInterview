//
// Created by koech on 8/17/2023.
//

#include <stdio.h>
#include "node.h"

Node *newNode();

Node *addInts(int first, int second);

Node *addNodes(Node *first, Node *second);

Node *subInts(int first, int second);

Node *subNodes(Node *first, Node *second);

Node *mulInts(int first, int second);

Node *mulNodes(Node *first, Node *second);

Node *divdInts(int first, int second);

Node *divdNodes(Node *first, Node *second);

Node *newNode() {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("%s: Failed to allocate memory\n", __func__);
        return NULL;
    }
    return newNode;
}

Node *addInts(int first, int second) {
    Node *result = newNode();
    result->type = ADD;
    result->result = first + second;
    return result;
}

Node *subInts(int first, int second) {
    Node *result = newNode();
    result->type = SUB;
    result->result = second - first;
    return result;
}

Node *mulInts(int first, int second) {
    Node *result = newNode();
    result->type = MUL;
    result->result = second * first;
    return result;
}

Node *divdInts(int first, int second) {
    Node *result = newNode();
    result->type = DIV;
    if (second == 0) {
        return NULL;
    }
    result->result = second / first;
    return result;
}

Node *addNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL) {
        return NULL;
    }
    result->type = ADD;
    result->result = ((first != NULL ? first->result : 0) + (second != NULL ? second->result : 0));
    return result;
}

Node *subNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL) {
        return NULL;
    }
    result->type = SUB;
    result->result = ((second != NULL ? second->result : 0) + (first != NULL ? first->result : 0));
    return result;
}

Node *mulNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL) {
        return NULL;
    }
    result->type = MUL;
    result->result = ((first != NULL ? first->result : 0) * (second != NULL ? second->result : 0));
    return result;
}

Node *divdNodes(Node *first, Node *second) {
    Node *result = newNode();
    if (result == NULL || second->result == 0) {
        return NULL;
    }
    result->type = DIV;
    result->result = ((first != NULL ? first->result : 0) / (second != NULL ? second->result : 0));
    return result;
}




