class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;

        for (int i = 1; i < n; i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }

        return mini;
    }
};
