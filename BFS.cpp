#include<iostream>
using namespace std;

void BFS(int cost[10][10],int visited[10],int source,int n){
    int queue[10],u,v;
    int f=0,r=-1;

    queue[++r]=source;

    while(f<=r){//until queue get empty
    u=queue[f++];

    for(v=1;v<=n;v++){
        if(cost[u][v]==1 && visited[v]==0){
            queue[++r]=v;
            visited[v]=1;
        }
    }

    }
}

int main(){
    int cost[10][10],visited[10],n,source;

    cout<<"enter the number of node:";
    cin>>n;

    cout<<"enter the coost matrix:\n";
    for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
        cin>>cost[i][j];
     }
    }

    cout<<"enter the source:";
    cin>>source;

    for(int i=1;i<=n;i++){
        visited[i]=0;
    
    }

    visited[source]=1;

    BFS(cost,visited,source,n);

    for(int i=1;i<=n;i++){
        if(visited[i]!=0)
        cout<<"node "<<i<<" is "<< " reachable \n";
        else
        cout<<" node "<<i<<" is "<<" not reachable \n";
    }

    return 0;
}