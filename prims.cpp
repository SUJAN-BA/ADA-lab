#include<iostream>
using namespace std;


int cost[10][10],n;//importent note size of visited array and cost should be same and array iteration must be i=1;i<=n;i++only ;""

void prims (int cost[10][10] ,int n){
int a=0,b=0,u=0,v=0;
int i,j, min,mincost=0;
int ne=1;
int visited[10]={0};//unvisited vetices is 0
visited[1]=1;//visited vertices is 1

while(ne<n)//run until check every edgesin prims for nvertices there is a n-1 edges
{
    for( i=1,min=999;i<=n;i++){
        for( j=1;j<=n;j++){
            if(cost[i][j]<min){
                if (visited[i]!=0)//extending edges from visited vertex to unvisited vertex
                {
                    min=cost[i][j];
                    a=u=i;//updating the vertex
                    b=v=j;
                }
            }
        }
    }

    if(visited[u]==0||visited[v]==0){//vertex get extend then print the edge and its weight
        cout<<"\nedge-"<<ne++<<"("<<a<<","<<b<<"):"<<min;
        mincost+=min;
        visited[b]=1;//updating the vetrex when edges are connected
    }
    cost[a][b]=cost[b][a]=999;//ensuring the path doest not visit once it already visit
}
cout<<"\nminimum cost:"<<mincost;


}


int main(){
    int i,j;
    
    cout<<"enter the number of vertices:";
    cin>>n;

    cout<<"enter the cost matrix:(999 for no edge and self loop):\n";
    for(i=1;i<=n;i++){
        for( j=1;j<=n;j++){
            cin>>cost[i][j];

        }
    }

    prims(cost,n);
    return 0;
}