//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> islandSizes;  // Map to store island sizes
        int maxIslandSize = 0;
        int islandId = 2;  // Start with 2 as 0 and 1 are used for water and land respectively

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = markIsland(grid, i, j, islandId);
                    islandSizes[islandId] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    islandId++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    if (i > 0) neighboringIslands.insert(grid[i - 1][j]);
                    if (i < n - 1) neighboringIslands.insert(grid[i + 1][j]);
                    if (j > 0) neighboringIslands.insert(grid[i][j - 1]);
                    if (j < m - 1) neighboringIslands.insert(grid[i][j + 1]);

                    int combinedSize = 1;  // Current cell is water

                    for (int island : neighboringIslands) {
                        combinedSize += islandSizes[island];
                    }

                    maxIslandSize = max(maxIslandSize, combinedSize);
                }
            }
        }

        return maxIslandSize;
    }

private:
    int markIsland(vector<vector<int>>& grid, int i, int j, int islandId) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = islandId;  // Mark the current cell as part of the island
        int size = 1;
        size += markIsland(grid, i - 1, j, islandId);  // Up
        size += markIsland(grid, i + 1, j, islandId);  // Down
        size += markIsland(grid, i, j - 1, islandId);  // Left
        size += markIsland(grid, i, j + 1, islandId);  // Right

        return size;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends