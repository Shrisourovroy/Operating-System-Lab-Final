#include<iostream>
using namespace std;
int main()
{
    int frames,n;
    cout<<"Enter The frames number:";
    cin>>frames;
    cout<<"Enter the number of pages:";
    cin>>n;
    cout<<"Enter page reference:";
    int pages[100],framesarr[100];
    for(int i=0;i<n;i++)
        cin>>pages[i];
    int count=0,pagehit=0,pagemiss=0,index=0;
    cout<<"\nPage\tFrame\n";
    for(int i=0;i<n;i++)
    {
        bool hit=false;
        for(int j=0;j<count;j++)
        {
            if(framesarr[j]==pages[i])
            {
                hit=true;
                break;
            }
        }
        if(hit)
        {
            pagehit++;
        }
        else
        {
            pagemiss++;
            if(count<frames)
            {
                framesarr[count++]=pages[i];
            }
            else
            {
                framesarr[index]=pages[i];
                index=(index+1)%frames;
            }
        }
        cout<<pages[i]<<"\t";
        for(int k=0;k<count;k++) cout<<framesarr[k]<<" ";
            cout<<(hit?"HIT":"MISS")<<"\n";
    }
    cout << "\nTotal Page Hits: " << pagehit << "\n";
    cout << "Total Page Misses: " << pagemiss << "\n";
    cout<<"Hit ratio:"<<(float) pagehit /n<<"\n";
    cout<<"Miss ratio:"<<(float) pagemiss /n<<"\n";
    return 0;
}
