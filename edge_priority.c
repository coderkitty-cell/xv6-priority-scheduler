#include "types.h"
#include "stat.h"
#include "user.h"

#define RUNS 3

int main() {
    printf(1, "\n=== PRIORITY SCHEDULING EDGE-CASE TEST ===\n\n");

    int pid;

    // Test 1: Negative priority
    pid = fork();
    if(pid == 0) {
        printf(1, "--- Testing negative priority ---\n");
        if(setpriority(getpid(), -5) < 0)
            printf(1, "Correct: Failed to set negative priority\n");
        else
            printf(1, "ERROR: Negative priority accepted!\n");

        for(int i = 0; i < RUNS; i++) {
            printf(1, "[Iteration %d] Negative-priority child running\n", i+1);
            sleep(1);
        }
        exit();
    }

    // Test 2: Extremely high priority
    pid = fork();
    if(pid == 0) {
        printf(1, "--- Testing extremely high priority ---\n");
        if(setpriority(getpid(), 20) < 0)
            printf(1, "Correct: Failed to set too-high priority\n");
        else
            printf(1, "Extreme-priority child running\n");

        for(int i = 0; i < RUNS; i++) {
            printf(1, "[Iteration %d] Extreme-priority child running\n", i+1);
            sleep(1);
        }
        exit();
    }

    // Wait for both children
    wait();
    wait();

    printf(1, "\n=== EDGE-CASE TEST COMPLETE ===\n");
    exit();
}
