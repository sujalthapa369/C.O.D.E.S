//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int t[1001][1001]; // Global for memoization (1001 for max constraints)

    int knapsack(int W, vector<int> &val, vector<int> &wt, int n)
    {
        if (n == 0 || W == 0)
            return 0;

        if (t[n][W] != -1)
            return t[n][W];

        if (wt[n - 1] <= W) {
            return t[n][W] = max(
                val[n - 1] + knapsack(W - wt[n - 1], val, wt, n - 1),
                knapsack(W, val, wt, n - 1)
            );
        } else {
            return t[n][W] = knapsack(W, val, wt, n - 1);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();

        // Initialize memoization table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                t[i][j] = -1;
            }
        }

        return knapsack(W, val, wt, n);
    }
};



//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends