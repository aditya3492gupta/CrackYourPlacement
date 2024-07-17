//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    int dfs(int i, int vis[], int par, vector<int> adj[])
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                if (dfs(it, vis, i, adj))
                    return 1;
            }
            else if (it != par)
                return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (dfs(i, vis, -1, adj))
                    return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends