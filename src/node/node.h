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

typedef Node *(*OpFunc)(Node *, Node *);

typedef Node *(*OpFuncInts)(int, int);


#define add(first, second) _Generic( (first) \
 Node*: addNodes, \
 int: addInts \
)(first, second)


#define sub(first, second) _Generic( (first) \
 Node*: subNodes, \
 int: subInts \
)(first, second)

#define mul(first, second) _Generic( (first) \
 Node*: mulNodes, \
 int: mulInts \
)(first, second)

#define divd(first, second) _Generic( (first) \
 Node*: divdNodes, \
 int: divdInts \
)(first, second)

OpFunc opFunc[] = {
        add,
        sub,
        mul,
        divd,
};

OpFunc makeFunc(TagType type) {
    return opFunc[type];
}
#endif //AGEINTERVIEWQUIZ1_NODE_H
