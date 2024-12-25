#include<iostream>
using namespace std;

int cost[100][100],s,ver;
float opt=999,sum;

void swap(int v[],int i,int j){
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

void tsp(int v[],int n,int i){
    int sum1;
    if(i==n){
        if(v[0]==s){
        
             sum1=0;
            for(int k=0;k<n-1;k++){
                sum1=sum1+cost[v[k]][v[k+1]];
            }
            sum1=sum1+cost[v[n-1]][s];
            if(sum1<opt)
            opt=sum1;
        }
    }
    else{
        for(int j=i;j<n;j++){
            swap(v,i,j);
            tsp(v,n,i+1);
            swap(v,i,j);
        }

    }
}

void approx(int ver){
    int vis[10],min,p,from,sum;
    for(int i=1;i<=ver;i++)
    vis[i]=0;
    vis[s]=1;
     from=s;
     sum=0;
    for(int j=1;j<ver;j++){
        min=999;
        for(int i=1;i<=ver;i++){
         if(vis[i]!=1 && cost[from][i]<min && cost[from][i]!=0){
            min=cost[from][i];
             p=i;
         }
        }
         vis[p]=1;
         from=p;
         sum=sum+min;


        
    }
    sum=sum+cost[from][s];

}

int main(){
    
    int v[100];
    cout<<"enter the number of vertex:";
    cin>>ver;

    for(int i=0;i<ver;i++)
        v[i]=i+1;
    
    

    cout<<"enter the cost matrix:\n";
    for(int i=1;i<=ver;i++)
    for(int j=1;j<=ver;j++)
    cin>>cost[i][j];

    cout<<"enter the source:";
    cin>>s;

    tsp(v,ver,0);

    cout<<"\n optimum soulution:"<<opt;

    approx(ver);
    cout<<"\n approximate solution:"<<sum;

    cout<<"\n spproximation value:"<<((sum/opt)-1)*100<<"%";

    return 0;
}