/*
BUBBLE SORT
TIME COMPLEXITY - O(N^2) (FOR AVERAGE AND WORST) AND O(N) FOR BEST CASE
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

void modifiedBubbleSort(vector<int>&a)
{
    for(int i = 0; i < a.size()-1; i++)
    {
        int flag = 0;
        for(int j = 0; j < a.size()-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = 1;
                swap(a[j], a[j+1]);
            }
        }
        if(flag == 0)
            break;
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
    modifiedBubbleSort(a);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}