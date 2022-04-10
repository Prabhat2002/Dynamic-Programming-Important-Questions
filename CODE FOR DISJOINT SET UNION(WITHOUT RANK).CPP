#include <bits/stdc++.h>
using namespace std;
vector<int>parent(100);
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj;
    for(int i=0;i<n;i++)
        parent[i]=i;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});
        union_sets(x,y);
    }
    for(int i=0;i<n;i++)
       cout<<parent[i]<<endl;
    return 0;
}
