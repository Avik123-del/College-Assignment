/*
Find the number of binary strings of length n, 
such that ‘0’ must be a neighbor of ‘1’ and ‘1’ must be a neighbor of ‘0’. 
Take n (2n1000) as user input. Print the answer in ‘modulo 109+7’ format.
*/

#include<iostream>
#include<cmath>
using namespace std;

long T(long n){
    long t1=2,t2=4;
    if(n<=2) return 2;
    if(n==3) return 4;
    for(int i=4;i<=n;i++){
        t2=t1+t2;
        t1=t2-t1;
        t2%=(int)pow(10,9)+7;
        t1%=(int)pow(10,9)+7;
    }
    return t2;
}

int main(){
    int n;
    cin>>n;
    cout<<T(n-1)<<endl;
    return 0;
}