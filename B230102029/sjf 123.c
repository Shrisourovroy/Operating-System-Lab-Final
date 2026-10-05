#include <stdio.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int done;
};

int main()
{
    int n, i, completed = 0, time = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];


    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        p[i].done = 0;
    }

    printf("\n\nGantt Chart:\n");

    while(completed < n)
    {
        int index = -1;
        int shortest = 9999;


        for(i = 0; i < n; i++)
        {
            if(p[i].done == 0 && p[i].at <= time)
            {
                if(p[i].bt < shortest)
                {
                    shortest = p[i].bt;
                    index = i;
                }
            }
        }


        if(index == -1)
        {
            time++;
        }
        else
        {
            printf("| P%d ", p[index].pid);

            time = time + p[index].bt;

            p[index].ct = time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;

            p[index].done = 1;
            completed++;

            avgWT += p[index].wt;
            avgTAT += p[index].tat
            avg CT+=p[index].CT
        }
    }

    printf("|\n");
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n
    printf("\nAverage completion  Time = %.2f\n", avgTAT / n



    return 0;
}
