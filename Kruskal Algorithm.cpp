/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int find(int i,vector<int>&parent)
{
    if(parent[i]==-1)
       return i;
    return parent[i]=find(parent[i],parent);
}
void union_(int i,int j,vector<int>&rank,vector<int>&parent)
{
    i=find(i,parent);
    j=find(j,parent);
    if(i!=j)
    {
        if(rank[i]<rank[j])
        {
            parent[i]=j;
            rank[j]=rank[j]+rank[i];
        }
        else
        {
            parent[j]=i;
            rank[i]=rank[i]+rank[j];
        }
    }
}
int kruskal(vector<vector<int>>&adj,vector<int>&parent,vector<int>&rank)
{
    int ans=0;
    for(auto x:adj)
    {
        int wt=x[0];
        int i=x[1];
        int j=x[2];
        int s1=find(i,parent);
        int s2=find(j,parent);
        cout<<"UNION "<<s1<<" -> "<<s2<<endl;
        if(s1!=s2)
        {
          union_(i,j,rank,parent);
          ans=ans+wt;
        }
        cout<<ans<<endl;
    }
    return ans;
}
int main()
{
   int n,m;
   cin>>n>>m;
   vector<int>parent(n,-1);
   vector<int>rank(n,1);
   vector<vector<int>>adj;
   for(int i=0;i<m;i++)
   {
       int wt,x,y;
       cin>>wt>>x>>y;
       adj.push_back({wt,x,y});
   }
   sort(adj.begin(),adj.end());
   int ans=kruskal(adj,parent,rank);
   cout<<"total : "<<ans;
   return 0;
}
