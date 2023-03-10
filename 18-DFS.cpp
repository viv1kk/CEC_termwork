/*
DFS
TIME COMPLEXITY - O(V+E) (FOR AVERAGE, WORST AND BEST CASE)
SPACE COMPLEXITY - O(V) - V.E IS PRODUCT OF NUMBER OF VERTICES AND EDGES
*/

#include <bits/stdc++.h>
using namespace std;

bool checkIfEdgeExist(vector<int>&E, int y)
{
    for(int i = 0; i < E.size(); i++)
    {
        if(E[i] == y)
            return true;
    }
    return false;
}

void addEdges(vector<int>&E, int y)
{
    if(!checkIfEdgeExist(E, y)) E.emplace_back(y);
}

void printGraph(vector<vector<int>>&G)
{
    cout<<endl;
    for(int i = 0; i < G.size(); i++)
    {
        cout<<i+1<<" : ";
        for(int j = 0; j < G[i].size(); j++)
        {
            cout<<G[i][j]+1<<", ";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int>>&G, vector<int>&ans, int s)
{
    vector<bool>visited(G.size(), false);
    stack<int>stk;

    stk.push(s);
    while(!stk.empty())
    {
        int s = stk.top();
        stk.pop();

        if(!visited[s])
        {
            ans.emplace_back(s);
            visited[s] = true;
        }
        for(int i = 0; i < G[s].size(); i++)
        {
            if(!visited[G[s][i]])
                stk.push(G[s][i]);
        }
    }
}

int main()
{
    int ch;
    cout<<"1 : Undirected Graph\n";
    cout<<"2 : Directed Graph\n";
    cin>>ch;
    
    int vn, en;
    cout<<"Enter the number of Vertices : ";
    cin>>vn;
    cout<<"Enter the number of Edges : ";
    cin>>en;

    vector<vector<int>>G(vn);
    for(int i = 0; i < vn; i++)
    {
        addEdges(G[i], i);
    }
    cout<<"Enter the Edges : \n";
    for(int i = 0; i < en; i++)
    {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        addEdges(G[x], y);
        if(ch == 1) addEdges(G[y], x);
    }
    vector<int>ans;
    int startNode;
    cout<<"Start BFS from Start Node : ";
    cin>>startNode;
    dfs(G, ans, startNode-1);
    cout<<"DFS traversal : "<<endl;
    cout<<startNode<<" : ";
    for(int i = 0 ; i < ans.size(); i++)
    {
        cout<<ans[i]+1<<" --> ";
    }
    cout<<"EOL"<<endl;
    cout<<"**************************"<<endl;
    printGraph(G);
    return 0;
}