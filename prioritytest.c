#include "types.h"
#include "stat.h"
#include "user.h"

#define HIGH 8
#define MED  5
#define LOW  2
#define RUNS 10

int main() {
    int pid[3];
    int priorities[3] = {HIGH, MED, LOW};
    char *names[3] = {"HIGH", "MEDIUM", "LOW"};

    printf(1, "\n=== PRIORITY SCHEDULING TEST ===\n");
    printf(1, "Starting 3 processes: HIGH=%d  MEDIUM=%d  LOW=%d\n\n",
           HIGH, MED, LOW);

    for (int i = 0; i < 3; i++) {

        pid[i] = fork();
        if (pid[i] == 0) {

            setpriority(getpid(), priorities[i]);

            for (int j = 0; j < RUNS; j++) {

                int t = uptime();

                printf(1,
                    "[tick %d] %s priority | iter %d | pid %d\n",
                    t, names[i], j+1, getpid());

                sleep(1);
            }
            exit();
        }
    }

    for (int i = 0; i < 3; i++)
        wait();

    printf(1, "\n=== TEST COMPLETE ===\n");
    exit();
}
