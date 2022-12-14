/*
BUBBLE SORT
TIME COMPLEXITY - O(N^2) (FOR BEST CASE, AVERAGE AND WORST)
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

void bubbleSort(vector<int>&a)
{
    for(int i = 0; i < a.size()-1; i++)
    {
        for(int j = 0; j < a.size()-i-1; j++)
        {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
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
    bubbleSort(a);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}