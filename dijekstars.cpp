#include<iostream>
using namespace std;

void dij(int cost[10][10],int dis[10],int visited[10],int n,int source){
    int i,j,min,u,w;//u store the vetex with shortest distance and w to handle the minimum distance

    for(int i=1;i<=n;i++){
        visited[i]=0;//making all vetex as unvisited
        dis[i]=cost[source][i];//finding distance from source to all vertex
    }
    visited[source]=1;//source is visited
    dis[source]=0;//distance of source to itself is 0

    for(j=2;j<=n;j++)//source already visited we have to start from next vertex
    {
        min=999;
        for(i=1;i<=n;i++){
            if(!visited[i]){
                if(dis[i]<min){
                    min=dis[i];
                    u=i;//storing the vertex in u
                }
            }
        }
        visited[u]=1;
        for(w=1;w<=n;w++){
            if(cost[u][w]!=999 && visited[w]==0)/*now source ,u and w are three vertex to find the
            shortest distance from source to w through u..999 means no egde to run this condition first there should be a distance between u and w*/
            {
                if(dis[w]>cost[u][w]+dis[u])
                    //initialy dis of w is infinity
                    dis[w]=cost[u][w]+dis[u];
                
            }
        }
        
    }
}

int main(){
    int cost[10][10],dis[10],visited[10],n,source;

    cout<<"enter the number of vetrices:";
    cin>>n;

    cout<<"enter the cost matrix:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }

    cout<<"enter the source:";
    cin>>source;

    dij(cost,dis,visited,n,source);

    for(int i=1;i<=n;i++){
        if(i!=source)//not printing souce distance to itself
        {
            cout<<"the shortest distance from :"<<source<<"-->"<<i<<" is "<<dis[i]<<endl;
        }
    }

    return 0;

}