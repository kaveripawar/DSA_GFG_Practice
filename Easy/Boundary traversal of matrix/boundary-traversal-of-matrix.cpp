//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        if(row==1)
        {
            for(int i=0;i<col;i++)
            {
                ans.push_back(matrix[0][i]);
            }
        }
        else if(col==1)
        {
            for(int i=0;i<row;i++)
            {
                ans.push_back(matrix[i][0]);
            }
        }
        else
        {
        for(int i=0;i<col;i++)
        {
            ans.push_back(matrix[0][i]);
        }
        for(int i=1;i<row;i++)
        {
            ans.push_back(matrix[i][col-1]);
        }
        for(int i=col-2;i>=0;i--)
        {
            ans.push_back(matrix[row-1][i]);
        }
        for(int i=row-2;i>0;i--)
        {
            ans.push_back(matrix[i][0]);
        }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends