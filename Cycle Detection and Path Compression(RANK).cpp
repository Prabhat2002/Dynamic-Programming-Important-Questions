#include <bits/stdc++.h>
using namespace std;

int find_set(int v,vector<int>&parent)
{
    if(parent[v]==-1)
        return v;
    return parent[v]=find_set(parent[v],parent);
}
void union_sets(int a, int b,vector<int>&rank,vector<int>&parent)
{
    a = find_set(a,parent);
    b = find_set(b,parent);
    if (a != b)
    {
        if(rank[a]<rank[b])
        {
            parent[a]=b;
            rank[b]+=rank[a];
        }
        else
        {
            parent[b]=a;
            rank[a]+=rank[b];
        }
    }
}
bool print_cycle(vector<pair<int,int>>&graph,vector<int>&rank,vector<int>&parent)
{
    for(int i=0;i<graph.size();++i)
    {
        int x = find_set(graph[i].first,parent);
        int y = find_set(graph[i].second,parent);
        if(x!=y)
           union_sets(x, y,rank,parent);
        else
            return 1;
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj;
    vector<int>rank(n);
    vector<int>parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
        rank[i]=1;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});
        // union_sets(x,y);
    }
    // for(auto i:adj)
    // {
    //     int x=find_set(i.first);
    //     int y=find_set(i.second);
    //     union_sets(x,y,rank);
    // }
    bool f=print_cycle(adj,rank,parent);
    if(f)
      cout<<"CYCLE_DETECT"<<endl;
    for(int i=0;i<n;i++)
      cout<<parent[i]<<" "<<rank[i]<<endl;
    return 0;
}
