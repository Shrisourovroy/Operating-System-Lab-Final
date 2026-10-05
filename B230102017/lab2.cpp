#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100], at[100], bt[100], pr[100]; // process id, arrival time, burst time, priority
    int rt[100]; // remaining time
    int complete = 0, t = 0;
    int wt[100], tat[100];
    float totalWT = 0, totalTAT = 0;

    // Input process details
    for (int i = 0; i < n; i++) {
        cout << "\nProcess P" << i + 1 << ":\n";
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority (Lower number = Higher priority): ";
        cin >> pr[i];
        pid[i] = i + 1;
        rt[i] = bt[i]; // initialize remaining time
    }

    // Gantt chart and scheduling
    cout << "\nGantt Chart:\n| ";
    int prev = -1;

    while (complete != n) {
        int highest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                if (highest == -1 || pr[i] < pr[highest]) {
                    highest = i;
                }
            }
        }

        if (highest == -1) {
            t++;
            continue;
        }

        // Print only when process changes
        if (prev != highest) {
            cout << "P" << pid[highest] << " | ";
            prev = highest;
        }

        rt[highest]--;
        t++;

        if (rt[highest] == 0) {
            complete++;
            int finish_time = t;
            tat[highest] = finish_time - at[highest];
            wt[highest] = tat[highest] - bt[highest];
            totalWT += wt[highest];
            totalTAT += tat[highest];
        }
    }

    // Output results
    cout << "\n\nProcess\tAT\tBT\tPR\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i]
             << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    return 0;
}
