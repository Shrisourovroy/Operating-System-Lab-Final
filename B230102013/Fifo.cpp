#include<iostream>
using namespace std;
int main(){
int n, f;
cout<<"Enter the number of frame: ";
cin>>f;
cout<<"Enter the number of pages: ";
cin>>n;
int fram[f], page[n];
cout<<"Enter the page reference string: ";
for(int i=0;i<n;i++){
        cin>>page[i];
}
int index = 0;
for(int i=0;i<f;i++){
    fram[i] = -1;
}

for(int i=0;i<n;i++){
        bool found = false;
    if(page[i]==fram[index]){
        found = true;
    }

        fram[index]= page[i];

    cout<<"Page" << page[i]<<" contents is ";
    for(int j=0;j<f;j++){
        cout<<fram[j]<<" ";
    }
    if(!found){
        cout<<" Faoult"<<endl;
        index  = (index+1)%3;
    }
    else{
        cout<<" Hit"<<endl;
    }

}}


