//
// Created by koech on 8/17/2023.
//

#ifndef AGEINTERVIEWQUIZ1_NODE_H
#define AGEINTERVIEWQUIZ1_NODE_H

typedef enum TagType {
    ADD,
    SUB,
    MUL,
    DIV,
}TagType;

typedef struct Node {
    TagType  type;
}Node;

#endif //AGEINTERVIEWQUIZ1_NODE_H
