#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the number of Process: ";
cin>>n;
int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

for(int i=0;i<n;i++){
        pid[i]= i+1;
    cout<<"Enter the Arrival_Time and Burst_Time for p"<<pid[i]<<" :";
    cin>>at[i]>>bt[i];
}

cout<<"\tProcess\tArrival_Time\tBurst_Time\n";
for(int i=0;i<n;i++){
        cout<<"\t"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<endl;
}

}

