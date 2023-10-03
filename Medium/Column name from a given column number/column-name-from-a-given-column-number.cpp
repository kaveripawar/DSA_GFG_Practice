//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string result = "";
        while (n > 0) {
            // Subtract 1 from n to account for 1-based indexing (A = 1, B = 2, ..., Z = 26).
            n--;

            // Calculate the remainder when divided by 26.
            int remainder = n % 26;

            // Convert the remainder to a character ('A' to 'Z') and prepend it to the result.
            result = char('A' + remainder) + result;

            // Update n to the integer division by 26.
            n /= 26;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends