#include <stdio.h>
#include "node/node.h"


int main() {
    Node* add = add(10, 6);
    Node* mul = (*makeFunc(MUL))(5, 4);
    Node* sub = (*makeFunc(SUB))(mul, add);
    Node* fibo = (*makeFunc(SUB))(sub, NULL);

    printf("Result: %d\n", fibo->result);

    // Free dynamically allocated memory
    free(add);
    free(mul);
    free(sub);
    free(fibo);
    return 0;
}
