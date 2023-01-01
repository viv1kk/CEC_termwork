/*
COUNTING SORT
TIME COMPLEXITY - O(V.E) (FOR AVERAGE, WORST AND BEST CASE)
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

void bfs(vector<vector<int>>&G, vector<int>&ans, int s)
{
    vector<bool>visited(G.size(), false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        s = q.front();
        ans.push_back(s);
        q.pop();

        for(int i = 0; i < G[s].size(); i++)
        {
            if(!visited[G[s][i]])
            {
                visited[G[s][i]] = true;
                q.push(G[s][i]);
            }
        }
    }
}

void undirectedGraph()
{
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
        addEdges(G[y], x);
    }
    vector<int>ans;
    int startNode;
    cout<<"Start BFS from Start Node : ";
    cin>>startNode;
    bfs(G, ans, startNode-1);
    cout<<"BFS traversal : "<<endl;
    cout<<startNode<<" : ";
    for(int i = 0 ; i < ans.size(); i++)
    {
        cout<<ans[i]+1<<" --> ";
    }
    cout<<"EOL"<<endl;
    cout<<"**************************"<<endl;
    printGraph(G);
}

void directedGraph()
{
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
    }
    vector<int>ans;
    int startNode;
    cout<<"Start BFS from Start Node : ";
    cin>>startNode;
    bfs(G, ans, startNode-1);
    cout<<"BFS traversal : "<<endl;
    cout<<startNode<<" : ";
    for(int i = 0 ; i < ans.size(); i++)
    {
        cout<<ans[i]+1<<" --> ";
    }
    cout<<"EOL"<<endl;
    cout<<"**************************"<<endl;
    printGraph(G);
}

int main()
{
    int ch;
    cout<<"1 : Undirected Graph\n";
    cout<<"2 : Directed Graph\n";
    cin>>ch;
    switch(ch)
    {
    case 1: undirectedGraph();
        break;
    case 2: directedGraph();
        break;
    default:
        cout<<"Invalid Option!!\n";
        return 0;
    }
    return 0;
}