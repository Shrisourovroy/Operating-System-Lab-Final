#include<iostream>
using namespace std;


    struct Process{
        int pid ,arrival_time, burst_time, start_time, completion_time, turnaround_time, waiting_time,resronse_time;

        int completed;

    };
int main(){
    int n;
    cout<<"Enter number of process: ";
    cin>>n;
    Process p[n];
    for(i=0; i<n; i++){
        p[i].pid=i+1;
        cout<<"\nProcessP""<<p[i].pid<<"\n";
      cout << "Arrival Time: ";
     cin>>p[i].arrival_time;
     cout << "Burst Time: ";
     cin>>p[i].burst_time;
     p[i].completed = 0;
    }

    int current_time =0;
    int completed_count =0;
  int cpu_busy_time = 0;

  while(completed_count<0){
    int selected = -1;
    int shortest_burst=999999;

    for(int i=0;i<n;i++){
        if(!p[i].completed && p[i].arrival_time<=cuttrnt_time){
            if(p[i].burst_time<shortest_burst){
                shortest_burst=p[i].burst_time;
                selected = i;
            }
            else if (p[i].burst_time == shortest_burst){
                if(p[i].arrival_time<p[selected].arrival_time){
                    selected=i;
                }
            }
        }
    }
    if(selected==-i){
        int next_arrival =999999;
        for(int i=o;i<n;i++){
        if (!p[i].completed && p[i].arrival_time < next_arrival) {
        next_arrival = p[i].arrival_time;


        }

    }


    float total_wt = 0;
    float total_tat = 0;
    float total_rt = 0;
    for(int i=0;i<n;i++){
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt += p[i].response_time;

    }
    float average_wt = total_wt / n;
    float average_tat = total_tat / n;
    float average_rt = total_rt / n;


    float throughput = (float)n/ current_time;
    float cpu_utilization =((float)cpu_busy_time/current_time)*100;
    cout << "\n\n==== PROCESS TABLE ====\n\n";

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(int i=0;i<n;i++){
        cout << "P" << p[i].pid << "\t"
            << p[i].arrival_time << "\t"
            << p[i].burst_time << "\t"
             << p[i].completion_time << "\t"
             << p[i].turnaround_time << "\t"
             << p[i].waiting_time << "\t"
             << p[i].response_time << "\n";

    }
    cout<<\n=====PERFORMANCE======\N";
    cout << "Average Waiting Time    : "
         << average_wt << "\n";

        cout << "Average Turnarround Time    : "
         << average_tat << "\n";

return 0;
}

