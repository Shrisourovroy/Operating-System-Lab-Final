#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int priority;
    int wt;
    int tat;
};

int main() {
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];


    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        printf("Enter Priority for P%d: ", i + 1);
        scanf("%d", &p[i].priority);
    }


    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {

                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


    p[0].wt = 0;

    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }


    for (i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }


    printf("\nPID\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               p[i].priority,
               p[i].wt,
               p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);


    printf("\nGantt Chart:\n");

    for (i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("|  P%d  ", p[i].pid);
    }
    printf("|\n");

    for (i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n");

    printf("0");

    int time = 0;

    for (i = 0; i < n; i++) {
        time += p[i].bt;
        printf("\t%d", time);
    }

    printf("\n");

    return 0;
}
