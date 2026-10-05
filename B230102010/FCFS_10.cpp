#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100],at[100],bt[100],ct[100],tat[100],wt[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID, Arrival Time, Burst Time: ";
        cin >> pid[i] >> at[i] >> bt[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }
    int time = 0;
    double totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {

        if (time < at[i]) {
            time = at[i];
        }

        time = time + bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
    }


    cout << "\n\nGantt Chart:\n";
    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << "--------";
    }
    cout << "-\n|";
    for (int i = 0; i < n; i++) {
        cout << "  P" << pid[i] << "   |";
    }
    cout << "\n ";
    for (int i = 0; i < n; i++) {
        cout << "--------";
    }
    cout << "-\n";
    cout << "0";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << ct[i];
    }
    cout << "\n\n";
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = "<< totalWT / n << endl;
    cout << "Average Turnaround Time = "<< totalTAT / n <<endl;

    return 0;
}


