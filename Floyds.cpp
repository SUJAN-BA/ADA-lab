#include<iostream>
using namespace std;
#define max 10
#define INF 999

int min(int a,int b){
    return (a<b)?a:b;

}

int creat_graph(int cost[max][max],int n){
    cout<<"enter the cost matrix:";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cin>>cost[i][j];
        }
    }
}

int floyd(int cost[max][max],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
}

int print(int cost[max][max],int n){
    cout<<"after applying a floyd warshall's\n";
    for(int i=1 ;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cost[i][j]==INF)
            cout<<"INF";
            else{
                cout<<cost[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    int n,cost[max][max];
    cout<<"enter the number of nodes:";
    cin>>n;

    creat_graph(cost,n);
    floyd(cost,n);
    print(cost,n);

    return 0;
}