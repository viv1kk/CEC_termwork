/*
FIBONACCI
TIME COMPLEXITY - 0(1.6^N) (FOR BEST CASE, AVERAGE AND WORST)
SPACE COMPLEXITY - 0(1.6^N)
*/

#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if(n == 0 || n == 1) return n;
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int f = fibo(n);
    cout<<n<<"th fibonacci number is "<<f<<endl;
    return 0;
}