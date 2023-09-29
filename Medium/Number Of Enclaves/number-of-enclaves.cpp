//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(vector<vector<int>>&grid ,int i,int j)
    {
        int rows=grid.size();
        int cols=grid[0].size();
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]!=1)
        {
            return ;
        }
        grid[i][j]=0;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0||i==grid.size()-1||j==0||j==grid[0].size()-1)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(grid,i,j);
                    }
                }
            }
        }
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends