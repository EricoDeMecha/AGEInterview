//
// Created by erickoech on 8/18/23.
//
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <stdint.h>

#include <cmocka.h>
#include "../../src/piecewise-recurrence/recurrence.h"


static void test_recursive_recurrence(void **state) {
    (void)state;
    assert_int_equal(recursiveRecurrence(0), 0);
    assert_int_equal(recursiveRecurrence(1), 1);
    assert_int_equal(recursiveRecurrence(2), 2);
    assert_int_equal(recursiveRecurrence(3), 1);
    assert_int_equal(recursiveRecurrence(4), 3);
    assert_int_equal(recursiveRecurrence(5), 3);
    assert_int_equal(recursiveRecurrence(6), 4);
}

static void test_iterative_recurrence(void **state) {
    (void)state;
    assert_int_equal(iterativeRecurrence(0), 0);
    assert_int_equal(iterativeRecurrence(1), 1);
    assert_int_equal(iterativeRecurrence(2), 2);
    assert_int_equal(iterativeRecurrence(3), 1);
    assert_int_equal(iterativeRecurrence(4), 3);
    assert_int_equal(iterativeRecurrence(5), 3);
    assert_int_equal(iterativeRecurrence(6), 4);
}

static void test_memoized_recurrence(void **state) {
    (void)state;

    long long int memo[7];
    for (int i = 0; i < 7; i++) {
        memo[i] = -1;
    }

    assert_int_equal(memoizedRecurrence(0, memo), 0);
    assert_int_equal(memoizedRecurrence(1, memo), 1);
    assert_int_equal(memoizedRecurrence(2, memo), 2);
    assert_int_equal(memoizedRecurrence(3, memo), 1);
    assert_int_equal(memoizedRecurrence(4, memo), 3);
    assert_int_equal(memoizedRecurrence(5, memo), 3);
    assert_int_equal(memoizedRecurrence(6, memo), 4);
}

int main(void){
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_recursive_recurrence),
            cmocka_unit_test(test_iterative_recurrence),
            cmocka_unit_test(test_memoized_recurrence),
    };
    return  cmocka_run_group_tests(tests, NULL, NULL);
}
