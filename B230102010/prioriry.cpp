#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100], at[100], bt[100], priority[100];
    int remaining[100], ct[100], tat[100], wt[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter PID, Arrival Time, Burst Time and Priority: ";
        cin >> pid[i] >> at[i] >> bt[i] >> priority[i];

        remaining[i] = bt[i];
    }

    int time = 0;
    int completed = 0;

    cout << "\nGantt Chart:\n";
    while (completed < n) {
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] > 0) {
                if (p == -1 || priority[i] < priority[p]) {
                    p = i;
                }
            }
        }
        if (p == -1) {
            time++;
            continue;
        }

        cout << "| P" << pid[p] << " ";

        remaining[p]--;
        time++;
        if (remaining[p] == 0) {
            ct[p] = time;
            tat[p] = ct[p]-at[p];
            wt[p] = tat[p]-bt[p];
            completed++;
        }
    }

    cout << "|\n";
    double totalWT = 0, totalTAT = 0;

    cout << "\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"<< at[i] << "\t"<< bt[i] << "\t"<< priority[i] << "\t\t"<< ct[i] << "\t"<< tat[i] << "\t"<< wt[i] << endl;

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = "<< totalWT / n<< endl;
    cout << "Average Turnaround Time = "<< totalTAT / n<<endl;

    return 0;
}


