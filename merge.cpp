#include<iostream>
#include<ctime>
using namespace std;

void conquare(int ary[],int si,int mid,int ei){
    int merge[ei-si+1];
    int x=0;
    int idx1=si;
    int idx2=mid+1;

    while( idx1 <= mid && idx2<=ei){
        if(ary[idx1]<=ary[idx2]){
            merge[x++] = ary[idx1++];
        }
        else{
            merge[x++] = ary[idx2++];
        }
    }

        while(idx1<=mid){
            merge[x++]=ary[idx1++];
        }

        while(idx2<=ei){
            merge[x++]=ary[idx2++];
        }

    

    for(int i=0,j=si;i<(ei-si+1);i++,j++){
        ary[j]=merge[i];
    }
}

void divide(int ary[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=(si+ei)/2;
    divide(ary,si,mid);
    divide(ary,mid+1,ei);
    conquare(ary,si,mid,ei);
}

int main(){
    int n,ary[100];
    cout<<"enter the number of element to be inserted:";
    cin>>n;

  cout<<"random elements are:";
    for(int i=0;i<n;i++){
        ary[i]=rand()%100;
        cout<<ary[i]<<" ";
    }cout<<"\n";
  
clock_t start=clock();

    divide(ary,0,n-1);

    cout<<"sorted array:";
    for(int i=0;i<n;i++){
      cout<<ary[i]<<" ";
    }

    clock_t end=clock();

    double duration=((double(end-start)/CLOCKS_PER_SEC)*1000);

    cout<<"\n time taken to sort:"<<duration<<" second "<<endl;

    return 0;
}