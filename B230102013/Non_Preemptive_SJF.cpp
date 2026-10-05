#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the number of Process: ";
cin>>n;
int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
bool complet[n] = {false};

for(int i=0;i<n;i++){
        pid[i]= i+1;
    cout<<"Enter the Arrival_Time and Burst_Time for p"<<pid[i]<<" :";
    cin>>at[i]>>bt[i];
}
for(int i=1;i<n-1;i++){
            for(int j=1;j<n-i;j++){
                if(bt[j]>bt[j+1]){
                    swap(at[j],at[j+1]);
                    swap(bt[j], bt[j+1]);
                    swap (pid[j], pid[j+1]);
                }
            }
        }

       int currentTime =0;
int completed =0;
while(completed<n){
        if(!complet){
            complet[completed]= true;
        }
        currentTime+=bt[completed];
        ct[completed] = currentTime+bt[completed];
        completed++;
}

for(int i=0;i<n;i++){
    tat[i] = ct[i]- at[i];
    wt[i] = tat[i] - bt[i];
}

double totalwt=0, totaltat=0;
for(int i=0;i<n;i++){
    totalwt+=wt[i];
    totaltat+=tat[i];
}
double avgWt = totalwt/n;
double avgTat = totaltat/n;

cout<<"SJF Scheduling: "<<endl;
cout<<"\tPID\tAT\tBT\tCT\tTdT\tWT\n";
for(int i=0;i<n;i++){
        cout<<"\t"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<< endl;
}
cout<<"Avarage Waiting Time is: "<<avgWt<<endl;
cout<<"Avarage Turnaround Time: "<<avgTat<<endl;

}
