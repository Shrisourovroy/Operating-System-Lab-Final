#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int pid[n], at[n], bt[n], wt[n], tat[n], ct[n], completed[n] = {0};

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time for P" << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    int time = 0, done = 0;
    float total_wt = 0, total_tat = 0;
    cout << "\nGantt Chart: ";

    while (done < n) {
        int idx = -1, min_bt = 9999;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
        } else {
        
            wt[idx] = time - at[idx];
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = wt[idx] + bt[idx];
            completed[idx] = 1;
            total_wt += wt[idx];
            total_tat += tat[idx];
            cout << "| P" << pid[idx] << " ";
            done++;
        }
    }
    cout << "|\n";

    cout << "\nProcess\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "Average Waiting Time = " << total_wt / n << endl;
    cout << "Average Turnaround Time = " << total_tat / n << endl;
    return 0;
}