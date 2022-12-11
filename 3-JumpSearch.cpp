#include <bits/stdc++.h>
using namespace std;


void getInput(vector<pair<int, int>>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
}

int jumpSearch(vector<pair<int,int>>a, int x)
{
    int step = sqrt(a.size());
    int i = 0;
    while(i < a.size())
    {
        if(a[i].first == x) break;
        else if(a[i].first  < x)
        {
            i+=step;
            if(i > a.size())
            {
                i = i-step+1;
                break;
            }
        } 
        else
        {
            i -=step;
            break;
        }
    }

    if(i == -1){
        return -1;
    }
    else{
        int j = 0;
        while(j < step && i < a.size()) // linear Search
        {
            if(a[i].first == x)
                return i;
            i++, j++;
        }
        return -1;
    }
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<pair<int, int>>a(n);
    getInput(a);
    cout<<"Enter the element to be searched : ";
    cin>>x;
    sort(a.begin(), a.end());
    int ind = jumpSearch(a, x);

    if(ind != -1)
        cout<<"Element Found at Index "<<a[ind].second<<endl;
    else
        cout<<"Element not Found!";
    return 0;
}