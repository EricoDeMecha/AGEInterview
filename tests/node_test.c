//
// Created by koech on 8/18/2023.
//

#include <cmocka.h>
#include "../src/node/node.h"

static void test_nodeNotNull(void **state) {
    (void) state;
    Node *node = newNode();
    assert_non_null(node);
    if (node != NULL) {
        free(node);
    }
}

static void test_addInts(void **state) {
    (void) state;
    Node *resultNode = (*getOpFuncInts(ADD))(10, 6);

    assert_int_equal(resultNode->type, ADD);
    assert_int_equal(resultNode->value, 16);
    free(resultNode);
}

static void test_addNodes(void **state) {
    (void) state;
    Node *node1 = newNode();
    assert_non_null(node1);
    node1->value = 10;
    Node *node2 = newNode();
    assert_non_null(node2);
    node2->value = 6;
    Node *resultNode = (*getOpFuncNodes(ADD))(node1, node2);
    assert_non_null(resultNode);
    assert_int_equal(resultNode->type, ADD);
    assert_int_equal(resultNode->value, 16);

    free(node1);
    free(node2);
    free(resultNode);
}

static void test_addNodesNull(void **state) {
    (void) state;
    Node *node1 = newNode();
    assert_non_null(node1);
    node1->value = 10;

    Node *resultNode = (*getOpFuncNodes(ADD))(node1, NULL);
    assert_non_null(resultNode);
    assert_int_equal(resultNode->type, ADD);
    assert_int_equal(resultNode->value, 10);

    free(node1);
    free(resultNode);
}

int main(void) {
    const struct CMUnitTest cmUnitTest[] = {
            cmocka_unit_test(test_nodeNotNull),
            cmocka_unit_test(test_addInts),
            cmocka_unit_test(test_addNodes),
    };

    return cmocka_run_group_tests(cmUnitTest, NULL, NULL);
}