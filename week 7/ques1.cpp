#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n; 
    cin >> n;
    n++;
    vector<vector<int>> adj(n, vector<int>(1e5));
    for(int i = 1; i < n; i++)
    {
        for(int j=1;j<n;j++)
            cin>>adj[i][j];
    }
    int sc; 
    cin >> sc;
    vector<int> dis(n, 1e5);
    vector<int> par(n);

    multiset<pair<int, int>> s;
    s.insert(make_pair(0, sc));
    dis[sc] = 0;

    while(!s.empty()) 
    {
    	auto p = *(s.begin());
    	s.erase(p);

    	for(int i=1;i<n;i++) 
    	{
    		if(adj[p.second][i]) 
    		{
	    		if(dis[i] > dis[p.second] + adj[p.second][i]) 
	    		{
	    			par[i] = p.second;
	    			s.erase({dis[i], i});
	    			dis[i] = dis[p.second] + adj[p.second][i];
	    			s.insert({dis[i], i});
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
