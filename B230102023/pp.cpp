#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of Process:";
    cin>>n;

    int pid[n],at[n],bt[n],priority[n],wt[n],tat[n],ct[n],remaining[n];

    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;

        cout<<"Enter AT, BT and Priority of process "<<pid[i]<<":";
        cin>>at[i]>>bt[i]>>priority[i];

        remaining[i]=bt[i];
    }

    int time=0;
    int done=0;
    int total_tat=0;
    int total_wt=0;
    int total_bt=0;

    cout<<"\nGantt Chart:\n"<<endl;

    int last=-1;
    int start=0;

    while(done<n)
    {
        int index=-1;
        int max_priority=-1;

        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && remaining[i]>0 &&
               priority[i]>max_priority)
            {
                max_priority=priority[i];
                index=i;
            }
        }

        if(index==-1)
        {
            if(last!=-2)
            {
                if(last!=-1)
                {
                    cout<<" "<<start<<"|P"<<pid[last]<<"|"<<time<<" ";
                }

                start=time;
                last=-2;
            }

            time++;
        }
        else
        {
            if(last!=index)
            {
                if(last!=-1 && last!=-2)
                {
                    cout<<" "<<start<<"|P"<<pid[last]<<"|"<<time<<" ";
                }

