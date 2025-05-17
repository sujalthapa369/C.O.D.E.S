//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

        // code here
        int evaluate(int x, int A, int B, int C) {
    return A * x * x + B * x + C;
}

// Function to transform and sort the array in-place
vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
    int n = arr.size();
    
    vector<int> transformed;
    // Apply the transformation
    for (int i = 0; i < n; i++) {
        transformed.push_back(evaluate(arr[i], A, B, C));
    }

    // Sort the transformed array
    sort(transformed.begin(), transformed.end());

    return transformed;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends