#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n; cin >> n;
    n++;
    vector<vector<int>> adj(n, vector<int>(n));
    int edge = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++) {
            cin >> adj[i][j];
            if(adj[i][j]) edge++;
        }
    }
    int sc; cin >> sc;
    
    vector<int> dis(n, 1e5);
    vector<int> par(n);
    dis[sc] = 0;

    edge--;
    while(edge--) 
    {
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++) 
            {
                if(adj[i][j] and dis[j] > dis[i] + adj[i][j]) 
                {
                    dis[j] = dis[i] + adj[i][j];
                    par[j] = i;
                }
            }
        }
    }

    vector<vector<int>> ans(n);
    for(int i=1;i<n;i++) 
    {
        ans[i].push_back(i);
        int tmp = i;
        while(tmp != sc) {
            ans[i].push_back(par[tmp]);
            tmp = par[tmp];
        }
    }
    for(int i=1;i<n;i++) 
    {
        for(auto it: ans[i]) {
            cout << it <<" ";
        }cout << ": " << dis[i] << endl;
    }
    return 0;
}
