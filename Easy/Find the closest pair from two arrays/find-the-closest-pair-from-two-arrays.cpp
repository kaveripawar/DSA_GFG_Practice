//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
                int closestSum = INT_MAX;
        std::pair<int, int> closestPair;

        // Sort the second array (brr) in ascending order.
        std::sort(brr, brr + m);

        // Traverse the first array (arr) and find the closest pair.
        for (int i = 0; i < n; i++) {
            int target = x - arr[i];
            int* ptr = std::lower_bound(brr, brr + m, target);

            // Check the element at ptr and the element before it (if any).
            if (ptr != brr + m) {
                int sum = arr[i] + *ptr;
                if (std::abs(x - sum) < std::abs(x - closestSum)) {
                    closestSum = sum;
                    closestPair = std::make_pair(arr[i], *ptr);
                }
            }

            if (ptr != brr) {
                ptr--;
                int sum = arr[i] + *ptr;
                if (std::abs(x - sum) < std::abs(x - closestSum)) {
                    closestSum = sum;
                    closestPair = std::make_pair(arr[i], *ptr);
                }
            }
        }

        // Create a vector to store the closest pair and return it.
        std::vector<int> result;
        result.push_back(closestPair.first);
        result.push_back(closestPair.second);
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends