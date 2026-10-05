#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of process:";
    cin>>n;
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];
    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;
        cout<<"Enter the AT and the BT of "<<pid[i]<<":";
        cin>>at[i]>>bt[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>=at[j+1])
            {
                swap(tat[j],tat[j+1]);
                swap(bt[j],bt[j+1]);
                swap(wt[j],wt[j+1]);
            }
        }
    }
    int time=0;
    int total_tat=0;
    int total_wt=0;
    int total_bt=0;
    cout<<"\nGantt Chart:\n";
    for(int i=0;i<n;i++)
    {

            if(time<at[i])
            {
                cout<<" "<<time<<"|IDLE|"<<at[i]<<" ";
               time=at[i];

            }
            int start=time;
            time= time+bt[i];
            ct[i]=time;
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            total_tat+=tat[i];
            total_wt+=wt[i];
            cout<<" "<<start<<"|P"<<pid[i]<<"|"<<ct[i]<<" ";

    }
    int total_time=time;
     cout<<"\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
  cout<<"Avg TAT:"<<(float)total_tat/n<<endl;
    cout<<"Avg WT:"<<(float)total_wt/n<<endl;
    return 0;
}
