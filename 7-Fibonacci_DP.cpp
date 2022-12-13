/*
FIBONACCI
TIME COMPLEXITY - θ(N) (FOR BEST CASE, AVERAGE AND WORST)
SPACE COMPLEXITY - θ(N)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1000] = {0};

int fibo(int n)
{
    if(n == 0 || n == 1) return n;
    if(dp[n] != 0)
        return dp[n];
    return dp[n] = (fibo(n-1)+fibo(n-2));
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