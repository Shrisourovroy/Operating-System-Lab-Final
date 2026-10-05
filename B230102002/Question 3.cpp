#include<iostream>
using namespace std;
int main()
{
    int frames,n,i,j,k;
    cout<<"Enter Number of Frames : ";
    cin>>frames;
    cout<<"Enter Number of Pages : ";
    cin>>n;
    int page[100], framearr[100];
    cout<<"Enter Page Reference : \n";
    for(i=0; i<n; i++)
    {
        cin>>page[i];
    }
    int hits = 0;
    int misses = 0;
    int index = 0;
    int count = 0;
    cout<<"\nPages\tFrames\tResult\n";
    for(i=0; i<n; i++)
    {
        bool hit = false;
        for(j=0; j<count; j++)
        {
            if(framearr[j] == page[i])
            {
                hit = true;
                break;
            }
        }
        if(hit)
        {
            hits++;
        }
        else
        {
            misses++;
            if(count<frames)
            {
                framearr[count] = page[i];
                count++;
            }
            else
            {
                framearr[index] = page[i];
                index = (index + 1) % frames;
            }
        }
        cout<< page[i] << "\t";
        for(k=0; k<count; k++)
        {
            cout<<framearr[k]<<" ";
        }
        if(hit)
        {
            cout<<"\tHit";
        }
        else
        {
            cout<<"\tMisses";
        }
        cout<<endl;
    }
    cout<<"Number of Total Hit = "<<hits<<endl;
    cout<<"Number of Total Misses = "<<misses<<endl;
    cout<<"Hit Ratio = "<<(float)hits/n;

    cout<<endl;

    return 0;
}
