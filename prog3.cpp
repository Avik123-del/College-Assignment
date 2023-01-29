/*
A traveler has to climb to the top of the hill with the least possible cost. The hill climbing process and the corresponding cost are described below.
The hill is represented by a 2-D binary matrix of order m×n (1m,n50) in which 1 means the traveler can go to that spot (cell), 0 means the traveler cannot go to the spot. The traveler can directly go to its neighbor spot in the right or left direction with cost 2, upper direction with cost 4, lower direction with cost 1. He cannot move diagonally. Starting from the bottom-left corner, the traveler has to reach the maximum reachable height with the least possible cost.
Print the maximum reachable height of the hill and the least possible cost to reach there. [10 marks]

Sample Runtime Environment:
Enter the dimension of the hill matrix: 9 8 (i.e. m=9 & n=8)
Enter the hill matrix:
0 0 0 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 1 1 1
1 1 1 1 1 0 1 0
1 0 1 0 1 1 1 1
1 0 1 0 0 1 1 0
0 1 1 1 1 0 1 0
0 0 0 1 1 1 0 1
1 1 1 1 1 1 1 1 (user input up to this)

Maximum reachable height: 7
Minimum cost to reach the maximum reachable height: 42
*/


#include<iostream>
using namespace std;

void rec(int *mat,int *cost,int m,int n,int i,int j,int val,int prev){
    if(i>=m || i<0 || j<0 || j>=n)  return;
    if(*(mat+i*n+j)==0) return;
    if(*(cost+i*n+j)==-1 || val<*(cost+i*n+j)){
        *(cost+i*n+j)=val;
        val = *(cost+i*n+j);
    }else{
        return;
    }
    if(prev!=4) rec(mat,cost,m,n,i,j+1,val+2,2);
    if(prev!=2) rec(mat,cost,m,n,i,j-1,val+2,4);
    if(prev!=3) rec(mat,cost,m,n,i-1,j,val+4,1);
    if(prev!=1) rec(mat,cost,m,n,i+1,j,val+1,3);
}


int main(){
    int m,n,i,j;
    cout<<"Enter the dimension of the hill matrix: ";
    cin>>m>>n;
    int *matrix= (int *)malloc(sizeof(int)*n*m);
    int *cost= (int *)malloc(sizeof(int)*n*m);
    cout<<"Enter the hill matrix:\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>*(matrix+i*n+j);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            *(cost+i*n+j)=-1;
        }
    }

    rec(matrix,cost,m,n,m-1,0,0,0);
    int val;
    bool flag=true;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(*(cost+i*n+j)!=-1){
                if(flag){
                    val = *(cost+i*n+j);
                    flag=false;
                }else if(val>*(cost+i*n+j)){
                    val=*(cost+i*n+j);
                }
            }
        }
        if(!flag) break;
    }
    cout<<"Maximum reachable height: "<<m-i-1<<endl;
    cout<<"Minimum cost to reach the maximum reachable height: "<<val<<endl;
    return 0;
}