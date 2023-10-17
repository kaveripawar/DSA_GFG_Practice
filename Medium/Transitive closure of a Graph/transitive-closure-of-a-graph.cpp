//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution {
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
        vector<vector<int>> tc(N, vector<int>(N, 0));

        // Initialize the transitive closure matrix with the given graph
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tc[i][j] = graph[i][j];
            }
        }

        // Perform the transitive closure computation
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);
                }
            }
        }

        // Fill in the diagonal with 1s, as there is a path from a vertex to itself
        for (int i = 0; i < N; i++) {
            tc[i][i] = 1;
        }

        return tc;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends