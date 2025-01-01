#include<iostream>
using namespace std;

int knap[10][10];

int max(int a,int b){
    return (a>b)?a:b;
}

int knapsack(int obj,int cap,int w[],int p[]){
    for(int i=1;i<=obj;i++){
        for(int j=1;j<=cap;j++){
            if(w[i]>j){
                //if weight value greater than capacity written the previous value
                knap[i][j]=knap[i-1][j];
            }
            else{
                knap[i][j]=max(knap[i-1][j],p[i]+knap[i-1][j-w[i]]);
            }
        }
    }

    return knap[obj][cap];
}

int main(){
    int obj,cap,p[10],w[10];
    cout<<"enter the number of object:";
    cin>>obj;

    cout<<"enter the capacity:";
    cin>>cap;

    cout<<"enter the weight:";
    for(int i=1;i<=obj;i++){
        cin>>w[i];

    }

    cout<<"enter the profit:";
    for(int i=1;i<=obj;i++){
        cin>>p[i];
    }

   int  max_profit=knapsack(obj,cap,w,p);

   cout<<"maximum profit:"<<max_profit;

   return 0;
}
