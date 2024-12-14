#include<iostream>
using namespace std;

int cost[10][10],parent[10];

int find(int i){
    while(parent[i]>0)//finding the root(minum postive number)
    i=parent[i];
    return i;
}

int Union(int i,int j){//joining the two vetex and U is cap in union ite is one of the functio  used in cpp
    parent[j]=i;
}

void krushkal(int cost[10][10],int n){
    int a=0,b=0,u=0,v=0;
    int i,j,min,mincost=0;
    int ne=1;

    while(ne<n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;

                }
            }
        }

        u=find(u);
        v=find(v);

        if(u!=v)//if close loop is not from then only join the vertices
        {
            Union(u,v);//join the vertices;
            cout<<"\negde-"<<ne++<<"("<<a<<","<<b<<"):"<<min;
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;

    }
    cout<<"\nminimum cost:"<<mincost;
}

int main(){
    int n,i,j;
   cout<<"enter the number of vetices:";
   cin>>n;

   cout<<"enter the cost matrix(999 for no egdge and self loop:):\n";
   for( i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        cin>>cost[i][j];
    }
   }

   krushkal(cost,n);
}