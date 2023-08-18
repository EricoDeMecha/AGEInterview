#include <stdio.h>
#include "node/node.h"


int main() {
    Node* add = (*getOpFuncInts(ADD))(10, 6);
    Node* mul = (*getOpFuncInts(MUL))(5, 4);
    Node* sub = (*getOpFuncNodes(SUB))(mul, add);
    Node* fibo = (*getOpFuncNodes(SUB))(sub, NULL);

    printf("Result: %d\n", fibo->value);

    free(add);
    free(mul);
    free(sub);
    free(fibo);
    return 0;
}
