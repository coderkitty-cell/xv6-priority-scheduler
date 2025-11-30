#include "types.h"
#include "stat.h"
#include "user.h"

#define HIGH       8
#define MED        5
#define LOW        2

#define RUNS       5
#define PROCS_PER_LEVEL 5

int main() {
    printf(1, "\n=== PRIORITY SCHEDULING STRESS TEST ===\n");
    printf(1, "Spawning %d High, %d Medium, %d Low priority processes\n\n",
           PROCS_PER_LEVEL, PROCS_PER_LEVEL, PROCS_PER_LEVEL);

    int priorities[3] = {HIGH, MED, LOW};
    char *labels[3]   = {"HIGH", "MEDIUM", "LOW"};

    int total = 3 * PROCS_PER_LEVEL;

    for (int level = 0; level < 3; level++) {
        for (int i = 0; i < PROCS_PER_LEVEL; i++) {

            int pid = fork();
            if (pid == 0) {
                setpriority(getpid(), priorities[level]);

                for (int iter = 0; iter < RUNS; iter++) {
                    int t = uptime();
                    printf(1,
                           "[tick %d] %s | Process %d | Iter %d | PID=%d\n",
                           t, labels[level], i + 1, iter + 1, getpid());
                    sleep(1);
                }
                exit();
            }
        }
    }

    for (int i = 0; i < total; i++)
        wait();

    printf(1, "\n=== TEST COMPLETE ===\n");
    exit();
}
