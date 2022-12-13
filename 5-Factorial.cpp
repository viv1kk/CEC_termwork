/*
FACTORIAL
TIME COMPLEXITY - 0(N) (FOR BEST CASE, AVERAGE AND WORST)
SPACE COMPLEXITY - 0(N)
*/

#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n == 1)
        return 1;
    return n*fact(n-1);
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int f = fact(n);
    cout<<"The factorial of "<<n<<" is "<<f<<endl;
    return 0;
}