/*
DIJKSTRA
TIME COMPLEXITY - O((V+E)logV) (FOR AVERAGE, WORST AND BEST CASE)
SPACE COMPLEXITY - O(V) - V, E ARE NUMBER OF VERTICES AND EDGES
*/

#include <bits/stdc++.h>
using namespace std;

bool checkIfEdgeExist(vector<pair<int, int>>&E, int y)
{
    for(int i = 0; i < E.size(); i++)
    {
        if(E[i].first == y)
            return true;
    }
    return false;
}

void addEdges(vector<pair<int,int>>&E, int y, int z)
{
    if(!checkIfEdgeExist(E, y)) E.emplace_back(make_pair(y, z));
}

void printGraph(vector<vector<pair<int, int>>>&G)
{
    cout<<endl<<"Printing Graph : "<<endl;
    for(int i = 0; i < G.size(); i++)
    {
        cout<<i<<" : ";
        for(int j = 0; j < G[i].size(); j++)
        {
            cout<<"("<<G[i][j].first<<", "<<G[i][j].second<<"), ";
        }
        cout<<endl;
    }
}

vector<pair<int, int>> dijkstra(vector<vector<pair<int, int>>>&G, int src, int dest)
{
    int vn = G.size();
    vector<bool>vis(vn, false);
    vector<pair<int, pair<int, int>>>dist(vn); // {weight,{from, to}}
    priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    
    for(int i = 0; i < vn; i++)
    {
        dist[i] = {INT_MAX, {i, i}};
    }

    dist[src].first = 0;
    pq.push(dist[src]);

    while(!pq.empty())
    {
        pair<int, pair<int, int>> tp = pq.top();
        int weight = tp.first;
        int to_node = ((tp.second).second);
        pq.pop();
        if(to_node == dest) break;
        if(!vis[to_node])
        {
            vis[to_node] == true;
            for(int i = 0; i < G[to_node].size(); i++)
            {   
                int adjnode = (G[to_node][i].first);
                int wt = G[to_node][i].second;
                if(wt > 0 && !vis[adjnode] && dist[adjnode].first > (weight+ wt))
                {
                    (dist[adjnode].first) = weight + (G[to_node][i].second);
                    ((dist[adjnode].second).first) = to_node;
                    pq.push(dist[adjnode]);
                }
            }
        }
    }

    int s = src;
    int d = dest;
    vector<pair<int, int>> ans;
    do
    {
        ans.emplace_back(make_pair((dist[d].first), (dist[d].second).second));
        d = ((dist[d].second).first);
    }while(s != d);
    return ans;
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

    vector<vector<pair<int, int>>>G(vn);
    for(int i = 0; i < vn; i++)
    {
        addEdges(G[i], i, 0);
    }
    cout<<"Enter the Edges : \n";
    for(int i = 0; i < en; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        addEdges(G[x], y, z);
        if(ch == 1) addEdges(G[y], x, z);
    }

    int startNode;
    cout<<"Enter the Start Node : ";
    cin>>startNode;

    cout<<endl;
    for(int i = 0; i < vn; i++)
    {
        vector<pair<int,int>>ans = dijkstra(G, startNode, i);
        cout<<i<<" : ";
        for(int j = 0; j < ans.size(); j++)
        {
            cout<<ans[j].second<<", ";
        }
        cout<<startNode<<" --> "<<ans[0].first;
        cout<<endl;
    }

    printGraph(G);
    return 0;
}

// Sample Input :
// 1
// 9
// 14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 5 4
// 2 8 2
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7
// 0