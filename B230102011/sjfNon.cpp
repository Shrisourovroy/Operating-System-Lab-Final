#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of Processes: ";
    cin>>n;
     int pid[n], at[n], bt[n], wt[n], tat[n], ct[n];
    bool complete={false};
     for(int i=0; i<n; i++)
     {
         pid[i]=i;
         cout<<"Enter the numbers of Arrival Time and Burst Time: "<<pid[i]<<" : ";
         cin>>at[i]>>bt[i]>>pid[i];

     }
     float tTAT=0;
     float tWT=0;
     int total_wt=0;
     int completeCount=0;
     float tCT=0;

     int ganttpid[n];
     int k=0;

     while(completeCount<n)
     {

         int idx=-1, min_rt=9999;
   for(int i=0; i<n; i++)
   {
       if(complete[i] && at[i] <= total_wt)
       {
           if(bt[i]<min_rt){
            min_rt=bt[i];
           }
       }
   }
   if(idx== -1)
   {
       total_wt++;
   }
   else{
    wt[i]= total_wt- at[i];
    total_wt += bt[idx];
    ct[idx]= total_wt;
   }
     }


}
