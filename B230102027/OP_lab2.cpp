#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], p[n], remaining[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Enter the AT, BT and priority of " << pid[i] << ": ";
        cin >> at[i] >> bt[i] >> p[i];

        remaining[i] = bt[i];
    }

    int time = 0;
    int done = 0;

    int total_tat = 0;
    int total_wt = 0;

    cout << "\nGantt Chart:\n";

    int last = -1;
    int start = 0;

    while (done < n)
    {
        int index = -1;
        int max_priority = -1;


        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && remaining[i] > 0)
            {
                if (p[i] > max_priority)
                {
                    max_priority = p[i];
                    index = i;
                }
            }
        }


        if (index == -1)
        {
            if (last != -2)
            {

                if (last != -1)
                {
                    cout << start << " | P" << pid[last] << " | " << time << "    ";
                }

                start = time;
                last = -2;
            }

            time++;
        }


        else
        {

            if (last != index)
            {

                if (last != -1 && last != -2)
                {
                    cout << start << " | P" << pid[last] << " | " << time << "    ";
                }


                start = time;
                last = index;
            }


            remaining[index]--;
            time++;


            if (remaining[index] == 0)
            {
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];

                total_tat += tat[index];
                total_wt += wt[index];

                done++;
            }
        }
    }


    if (last >= 0)
    {
        cout << start << " | P" << pid[last] << " | " << time;
    }

    cout << "\n\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++)
    {
       cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << p[i] << "\t\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    cout << "\nAvg TAT: " << (float)total_tat / n << endl;
    cout << "Avg WT: " << (float)total_wt / n << endl;

    return 0;
}
