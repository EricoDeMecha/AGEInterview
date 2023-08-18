//
// Created by erickoech on 8/18/23.
//

#include "recurrence.h"

#define MAX_N 100 // arbitrary number

int recursiveRecurrence(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return recursiveRecurrence(n - 3) + recursiveRecurrence(n - 2);
}

int iterativeRecurrence(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    return dp[n];
}

static int memo[MAX_N] = {-1};

int memoizedRecurrence(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (memo[n] != -1) return memo[n];

    memo[n] = memoizedRecurrence(n - 3) + memoizedRecurrence(n - 2);
    return memo[n];
}

