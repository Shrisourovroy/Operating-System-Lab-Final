#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
   cout<<"Enter number of Process:";
   cin>>n;
   int pid[n],at[n],bt[n],wt[n],tat[n],ct[n],completed[n]={0};
   for(int i=0;i<n;i++)
   {
       pid[i]=i+1;
       cout<<"Enter AT and BT of process "<<pid[i]<<":";
       cin>>at[i]>>bt[i];
   }
   int time=0;
   int done=0;
   int total_wt=0;
   int total_tat=0;
   int total_bt=0;
   cout<<"\nGantt chart:\n"<<endl;
   while(done<n)
   {
       int index=-1;
       int min_bit=INT_MAX;
       for(int i=0;i<n;i++)
       {
           if(completed[i]==0 && at[i]<=time && bt[i]<min_bit)
           {
               min_bit=bt[i];
               index=i;
           }
       }
       if(index==-1)
       {
           int next_at=INT_MAX;
           for(int i=0;i<n ;i++)
           {
               if(completed[i]==0 && at[i]<next_at)
               {
                   next_at=at[i];
               }
           }
           cout<<" "<<time<<"|IDLE|"<<next_at<<" ";
           time=next_at;
       }
       else
       {
           int start=time;
       time = time +bt[index];
       ct[index]=time;
       tat[index] =ct[index]-at[index];
       wt[index]=tat[index]-bt[index];
      total_tat+=tat[index];
      total_bt+=bt[index];
      total_wt+=wt[index];
      completed[index]=1;
      done++;
      cout<<" "<<start<<"|P"<<pid[index]<<"|"<<ct[index]<<" ";
       }
   }
   cout<<endl;
   int total_time = time;

    cout<<"\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
for(int i=0;i<n;i++)
    {
        cout<<"P"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
    cout<<"Avg TAT:"<<(float)total_tat/n<<endl;
    cout<<"Avg WT:"<<(float)total_wt/n<<endl;

    return 0;
}
