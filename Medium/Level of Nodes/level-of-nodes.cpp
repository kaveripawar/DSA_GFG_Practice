//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        // Create a visited array to keep track of visited nodes.
        vector<bool> visited(V, false);

        // Create a queue for BFS.
        queue<int> q;

        // Start the traversal from node 0 (or any other starting node).
        int level = 0;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int current = q.front();
                q.pop();

                // If we found the target node, return the current level.
                if (current == X)
                    return level;

                // Explore all adjacent nodes (neighbors) if they haven't been visited.
                for (int neighbor : adj[current])
                {
                    if (!visited[neighbor])
                    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            // Increment the level after processing all nodes at the current level.
            level++;
        }

        // If the target node X was not found, return -1 (or any other appropriate value).
        return -1;
     // code here
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends