#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of pages: ";
    cin>>n;

    int page[n];
    cout<<"Enter the number of Reference Strings: ";
    for(int i=0; i<n; i++)
    {
        cin>>page[i];
    }
    int f;
    cout<<"The number of available page frames is: ";
    cin>>f;

    int frame[f];
    for(int j=0; j<f; j++)
    {
        frame[j]=-1;
    }

    int hit=0, fault=0, index=0;

    for(int i=0; i<n; i++)
    {
        int found =0;
        for(int j=0; j<f; j++)
        {
            if(page[i]==frame[j])
            {
                found =1;
                hit++;
                break;
            }

        }
        if(found==0)
        {
            frame[index]=page[i];
            index=(index+1)%f;
            fault++;
        }

 cout<<page[i]<<": ";
    for(int j=0; j<f; j++)
    {
       if(frame[j]== -1)
       {
           cout<<"-";
       }
       else {
        cout<<frame[j]<<" ";
       }
    }
    if(found==1)
    {
      cout<<"Hit";
    }
    else cout<<"Fault";
    cout<<endl;
    }

    cout<<"Number of Hit: "<<hit<<endl;
    cout<<"Number of Fault: "<<fault<<endl;
    return 0;

}
