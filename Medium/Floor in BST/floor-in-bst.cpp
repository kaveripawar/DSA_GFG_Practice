//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
    int ans = INT_MAX; // Initialize floorValue to a very small value
    int val=-1;
    while (root != NULL) {
        if(root->data==x)
        {
            return x;
        }
        if (root->data <= x) {
            // Update floorValue to the current node's data if it's less than or equal to x
            int diff=x-root->data;
            if(ans>diff)
            {
                ans=diff;
                val=root->data;
            }
            root = root->right; // Traverse to the right to potentially find a larger floor value
        } else {
            root = root->left; // Traverse to the left to find a smaller value
        }
    }

    return val;
}

};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends