/*
BELLMANFORD
TIME COMPLEXITY - O((V*E) (FOR AVERAGE, WORST AND BEST CASE)
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

vector<pair<int, int>> bellmanford(vector<vector<pair<int, int>>>&G, int src, int dest)
{
    int vn = G.size();
    vector<pair<int, pair<int, int>>>dist(vn);

    for(int i = 0; i < vn; i++)
    {
        dist[i] = {INT_MAX,{i, i}};
    }
    dist[src].first = 0;

    int k = vn;

    while(k--)
    {
        for(int i = 0; i < vn; i++)
        {
            for(int  j = 0; j < G[i].size(); j++)
            {
                int adjnode = G[i][j].first;
                int wt = G[i][j].second;
                if(wt != 0 && (dist[i].first + wt) < (dist[adjnode].first))
                {
                    dist[adjnode].first = dist[i].first + wt;
                    (dist[adjnode].second).first = i;
                }
            }
        }
    }

int f = 0;
  for(int i = 0; i < vn; i++)
  {
    for(int j = 0; j < G[i].size(); j++)
    {
      if(G[i][j].second != 0 && dist[i].first + G[i][j].second < dist[(G[i][j].first)].first)
      {
        cout<<"NEGATIVE CYCLE DETECTED\n";
        f = 1;
        break;
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
        vector<pair<int,int>>ans = bellmanford(G, startNode, i);
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