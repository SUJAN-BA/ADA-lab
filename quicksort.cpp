#include<iostream>
#include<ctime>
using namespace std;

int partition(int ary[] ,int si,int ei ){
    int pivot=ary[ei];
    int i=si-1;

    for(int j=si;j<ei;j++){
        
        if(ary[j]<pivot){
            i++;
        int temp=ary[i];
        ary[i]=ary[j];
        ary[j]=temp;
        }
    }

    i++;
    int temp=ary[i];
    ary[i]=ary[ei];
    ary[ei]=temp;

    return i;
}

void quicksort(int ary[],int si,int ei){
    if(si<ei){
        int pivotidx=partition(ary,si,ei);
        quicksort(ary,si,pivotidx-1);
        quicksort(ary,pivotidx+1,ei);

    }
}

int main(){
    int n,ary[100];
    cout<<"enter the number of element to be inserted:";
    cin>>n;

    cout<<"random number are : ";
    for(int i=0;i<n;i++){
        ary[i]=rand()%100;
        cout<<ary[i]<<" ";
    }cout<<"\n";

    clock_t start=clock();

    quicksort(ary,0,n-1);

    clock_t end=clock();

    double duration=((double(end-start)/CLOCKS_PER_SEC)*1000);

   cout<<"sorted array:";
    for(int i=0;i<n;i++){
        cout<<ary[i]<<" ";
    }

    cout<<"\ntime taken to sort:"<<duration<<" seconds "<<endl;

    return 0;
}


