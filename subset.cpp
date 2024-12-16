#include<iostream>
using namespace std;

int s[10],set[10],n,d;//a s[] to store the number of element ,set[] to store temprorary subset,count to keep track the current subset
int flag=0,count=0;

int display(int count){
    cout<<"{";
    for(int i=0;i<count;i++){
        cout<<" "<<set[i]<<" ";
    }
    cout<<"}\n";
}

void subset(int sum,int i){
    if(sum==d){
        flag=1;
        display(count);
        return;
    }
    if(sum>d||i>=n){
        return;
    }
    else{
        set[count]=s[i];
        count++;
        subset(sum+s[i],i+1);
        count--;
        subset(sum,i+1);
    }
}

int main(){
    cout<<"enter the number of element:";
    cin>>n;

    cout<<"enter the value:";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    cout<<"enter the sum:";
    cin>>d;

    cout<<"solution:";
    subset(0,0);

    if(flag==0){
        cout<<"no solution:";
    }
}