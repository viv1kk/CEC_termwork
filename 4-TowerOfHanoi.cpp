/*
TOWER OF HANOI
TIME COMPLEXITY - 0(2^N) (FOR BEST CASE, AVERAGE AND WORST)
SPACE COMPLEXITY - 0(2^N)
*/

#include <bits/stdc++.h>
using namespace std;

void towerofhanoi(int n, char A, char C, char B)
{
    if(n == 0)
        return;
    towerofhanoi(n-1, A, B, C);
    cout<<"Move Disk "<<n<<" from "<<A<<" to "<<C<<" using "<<B<<endl;
    towerofhanoi(n-1, B, C, A);
}

int main()
{
    int n;
    cout<<"Enter the number of disks : ";
    cin>>n;

    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}