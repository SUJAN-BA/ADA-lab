#include<iostream>
using namespace std;


int cost[10][10],visited[10],n,count=0;

void DFS(int source){
 
 visited[source]=1;
 count++;

 for(int  i=1;i<=n;i++){
    if(cost[source][i]==1 && visited[i]==0){
        DFS(i);
    }
 }

}

int main(){
    int source;
    cout<<"enter the number of node:";
    cin>>n;

    cout<<"enter the cost matrix:\n";

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }

    cout<<"enter the source:";
    cin>>source;

    for(int  i=1;i<=n;i++){
        visited[i]=0;
    }

    
    DFS(source);

    if(count==n){
        cout<<"graph is connected";
    }
    else{
        cout<<" graph is disconnected ";
    }

    return 0;
}