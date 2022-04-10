#include <bits/stdc++.h>
using namespace std;

vector<int>parent(100);
int find_set(int v)
{
    if(parent[v]==-1)
        return v;
    return find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
bool print_cycle(vector<pair<int,int>>&graph)
{
    for(int i=0;i<graph.size();++i)
    {
        int x=graph[i].first;
        int y=graph[i].second;
        // int x = find_set(graph[i].first);
        // int y = find_set(graph[i].second);
        if (parent[x]==parent[y])
            return 1;
        // union_sets(x, y);
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj;
    for(int i=0;i<n;i++)
        parent[i]=-1;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});
        // union_sets(x,y);
    }
    for(auto i:adj)
    {
        int x=find_set(i.first);
        int y=find_set(i.second);
        union_sets(x,y);
    }
    bool f=print_cycle(adj);
    if(f)
      cout<<"CYCLE_DETECT"<<endl;
    for(int i=0;i<n;i++)
      cout<<parent[i]<<endl;
    return 0;
}
