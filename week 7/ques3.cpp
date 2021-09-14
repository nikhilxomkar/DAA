#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int sc, ds;
int n;
int ans = 1e5;

bool DFS(int node, int k, int wt) {
    if(k < 0) {
        return false;
    }
    if(k == 0) {
        if(node == ds) {
            ans = min(ans, wt);
            return true;
        }
        return false;
    }
    bool f = false;
    for(int i=1;i<n;i++)
    {
        if(adj[node][i] and DFS(i, k - 1, wt + adj[node][i]))
            f = true;
    }
    if(f) 
        return true;
    return false;
}
int main() 
{
    cin >> n;
    n++;
    adj = vector<vector<int>>(n, vector<int>(n));
    int edge = 0;
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++)
            cin >> adj[i][j];
    }
    cin >> sc >> ds;
    int k; 
    cin >> k;
    if(DFS(sc, k, 0))
        cout << "Weight of shortest path from (" << sc << ", " << ds << ") with " << k << " edges : " << ans << endl;
    else 
        cout << "no path of length " << k << " is available." << endl;
    
    return 0;
}
