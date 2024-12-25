#include<iostream>
using namespace std;
#define max 10

void creat_graph(int cost[max][max],int n){
cout<<"enter the matrix:\n";
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>cost[i][j];
    }
}
}

void warshalls (int cost[max][max],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cost[i][j]=cost[i][j] || cost[i][k]&&cost[k][j];
            } 
        }
    }
}

void print(int cost[max][max],int n){
    cout<<"after allpying warshall's\n";
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<cost[i][j]<<" ";
    }
    cout<<"\n";
}
}

int main(){
    int n,cost[max][max];
    cout<<"enter the number of nodes:";
    cin>>n;
    creat_graph(cost,n);
    warshalls(cost,n);
    print(cost,n);

    return 0;
}