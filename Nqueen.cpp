#include<iostream>
using namespace std;
#define max 10

int board[max];//it store the column position of each row

bool issafe(int row,int col){//this function give the safe position to place queen which is not attacked by another queen
    for(int i=0;i<row;i++){
        if((board[i]==col) || (board[i]-col) == (i-row) || (board[i]-col)==(row-i) )//it is the position where quen already present
        return false;
    }
    return true;
}

void print(int n){//n is the board size
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i]==j){// it is the position where q is present hence we print
                cout<<" Q ";
            }
            else{
                cout<<" - ";//empty sapce
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void nqueen(int row ,int n){
    if(row==n){//every queen  is check then print the solution
    print(n);
    return;

    }
    
        for(int col=0;col<n;col++){
            if(issafe(row,col)){
                board[row]=col;
                nqueen(row+1,n);//checking next row
            }
        }
    
}

int main(){
    int n;
    cout<<"enter the number of queen:";
    cin>>n;

    nqueen(0,n);
}
