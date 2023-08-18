//
// Created by koech on 8/18/2023.
//
// required for cmocka
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <stdint.h>

#include <cmocka.h>
#include "../../src/node/node.h"

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

static void test_subInts(void **state) {
    (void) state;
    Node *resultNode = (*getOpFuncInts(SUB))(6, 10);

    assert_int_equal(resultNode->type, SUB);
    assert_int_equal(resultNode->value, 4);
    free(resultNode);
}

static void test_subNodes(void **state) {
    (void) state;
    Node *node1 = newNode();
    assert_non_null(node1);
    node1->value = 6;
    Node *node2 = newNode();
    assert_non_null(node2);
    node2->value = 10;
    Node *resultNode = (*getOpFuncNodes(SUB))(node1, node2);
    assert_non_null(resultNode);
    assert_int_equal(resultNode->type, SUB);
    assert_int_equal(resultNode->value, 4);

    free(node1);
    free(node2);
    free(resultNode);
}

static void test_mulInts(void **state) {
    (void) state;
    Node *resultNode = (*getOpFuncInts(MUL))(6, 10);

    assert_int_equal(resultNode->value, 60);
    assert_int_equal(resultNode->type, MUL);

    free(resultNode);
}

static void test_mulNodes(void **state) {
    (void) state;
    Node *node1 = newNode();
    node1->value = 6;
    Node *node2 = newNode();
    node2->value = 10;
    Node *resultNode = (*getOpFuncNodes(MUL))(node1, node2);
    assert_non_null(resultNode);
    assert_int_equal(resultNode->type, MUL);
    assert_int_equal(resultNode->value, 60);

    free(node1);
    free(node2);
    free(resultNode);
}

static void test_divInts(void **state) {
    (void) state;
    Node *resultNode = (*getOpFuncInts(DIV))(60, 6);

    assert_int_equal(resultNode->value, 10);
    assert_int_equal(resultNode->type, DIV);

    free(resultNode);
}

static void test_divNodes(void **state) {
    (void) state;
    Node *node1 = newNode();
    node1->value = 60;
    Node *node2 = newNode();
    node2->value = 6;
    Node *resultNode = (*getOpFuncNodes(DIV))(node1, node2);
    assert_non_null(resultNode);
    assert_int_equal(resultNode->type, DIV);
    assert_int_equal(resultNode->value, 10);

    free(node1);
    free(node2);
    free(resultNode);
}

static void test_divNodesNull(void **state) {
    (void) state;
    Node *node1 = newNode();
    node1->value = 60;
    Node *resultNode = (*getOpFuncNodes(MUL))(node1, NULL);
    assert_int_equal(resultNode->value, 0);
    free(resultNode);
}

int main(void) {
    const struct CMUnitTest cmUnitTest[] = {
            cmocka_unit_test(test_nodeNotNull),
            cmocka_unit_test(test_addInts),
            cmocka_unit_test(test_addNodes),
            cmocka_unit_test(test_addNodesNull),
            cmocka_unit_test(test_subInts),
            cmocka_unit_test(test_subNodes),
            cmocka_unit_test(test_mulInts),
            cmocka_unit_test(test_mulNodes),
            cmocka_unit_test(test_divInts),
            cmocka_unit_test(test_divNodes),
            cmocka_unit_test(test_divNodesNull),
    };

    return cmocka_run_group_tests(cmUnitTest, NULL, NULL);
}