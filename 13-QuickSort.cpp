/*
QUICK SORT
TIME COMPLEXITY - O(NlogN) (FOR AVERAGE AND BEST) AND O(N^2) FOR WORST CASE
SPACE COMPLEXITY - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void getInput(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cin>>a[i];
    }
}

int partition(vector<int>&a, int lb, int ub)
{
    int p = lb;
    int piv = a[ub];

    for(int i = lb; i < ub; i++)
    {
        if(a[i] < piv)
        {
            swap(a[i], a[p]);
            p++;
        }
    }
    swap(a[ub], a[p]);
    return p;
}

void quickSort(vector<int>&a, int lb, int ub)
{
    if(lb >= ub) return;
    int p = partition(a, lb, ub);
    quickSort(a, lb, p-1);
    quickSort(a, p+1, ub);
}

void printArray(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<endl;
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<int>a(n);
    getInput(a);
    quickSort(a, 0, a.size()-1);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}