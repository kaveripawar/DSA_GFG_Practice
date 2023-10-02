//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    const int MOD = 1000000007;

int distinctSubsequences(string s) {
    int n = s.length();
    
    // Create a DP array to store the number of distinct subsequences
    vector<long long> dp(n + 1, 0);
    
    // Base case: There is one empty subsequence for an empty string.
    dp[0] = 1;
    
    // Create a map to store the last position of each character
    unordered_map<char, int> lastPos;
    
    // Fill the DP array
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        
        if (lastPos.find(s[i - 1]) != lastPos.end()) {
            // If the character has occurred before, subtract the count of subsequences
            // that end with the previous occurrence of the character.
            dp[i] = (dp[i] - dp[lastPos[s[i - 1]] - 1] + MOD) % MOD;
        }
        
        // Update the last position of the current character
        lastPos[s[i - 1]] = i;
    }
    
    // The result includes the empty subsequence, so return dp[n] as the final answer.
    return (int)dp[n];
}

};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends