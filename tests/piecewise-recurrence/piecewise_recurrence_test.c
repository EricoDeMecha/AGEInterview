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
/*    assert_int_equal(recursiveRecurrence(3), 3);
    assert_int_equal(recursiveRecurrence(4), 4);*/
}

static void test_iterative_recurrence(void **state) {
    (void)state;
    assert_int_equal(iterativeRecurrence(0), 0);
    assert_int_equal(iterativeRecurrence(1), 1);
    assert_int_equal(iterativeRecurrence(2), 2);
/*    assert_int_equal(iterativeRecurrence(3), 3);
    assert_int_equal(iterativeRecurrence(4), 4);*/
}

static void test_memoized_recurrence(void **state) {
    (void)state;
    assert_int_equal(memoizedRecurrence(0), 0);
    assert_int_equal(memoizedRecurrence(1), 1);
    assert_int_equal(memoizedRecurrence(2), 2);
 /*   assert_int_equal(memoizedRecurrence(3), 3);
    assert_int_equal(memoizedRecurrence(4), 4);*/
}

int main(void){
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_recursive_recurrence),
            cmocka_unit_test(test_iterative_recurrence),
            cmocka_unit_test(test_memoized_recurrence),
    };
    return  cmocka_run_group_tests(tests, NULL, NULL);
}
