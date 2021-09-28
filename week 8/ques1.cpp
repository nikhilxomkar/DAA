#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9;

int n, sc;
vector<vector<int>> adj;

int solve() 
{
    vector<bool> vis(n + 1, 0);
    multiset<pair<int,int>> s;

    vector<int> dis(n + 1, N);

    dis[1] = 0;
    vis[1] = 1;
    for(int i=1;i<n + 1;i++) 
    {
        if(adj[1][i] && !vis[i] && adj[1][i] < dis[i]) 
        {
            s.insert(make_pair(adj[1][i], i));
            dis[i] = adj[1][i];
        }
    }

    int roads = n - 1;
    int cost = 0;

    while(roads--) 
    {
        pair<int,int> p = *(s.begin());
        s.erase(p);
        vis[p.second] = 1;
        cost += p.first;
        for(int i=1;i<n + 1;i++) 
        {
            if(adj[p.second][i] && !vis[i] && adj[p.second][i] < dis[i]) 
            {
                s.erase({dis[i], i});
                s.insert(make_pair(adj[p.second][i], i));
                dis[i] = adj[p.second][i];
            }
        }
    }
    return cost;
}
int main() 
{
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for(int i=1;i<n + 1;i++) 
    {
        for(int j=1;j<n + 1;j++) 
            cin >> adj[i][j];
    }
    cout << "Minimum Spanning Weight: " << solve() << endl;
    return 0;
}
