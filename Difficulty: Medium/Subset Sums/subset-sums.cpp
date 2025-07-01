class Solution {
public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> dp = {0};  // Start with sum = 0 (empty subset)

        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            int sz = dp.size();
            for (int j = 0; j < sz; j++) {
                dp.push_back(dp[j] + curr);  // Add current element to all previous sums
            }
        }

        sort(dp.begin(), dp.end());  // Required by GFG
        return dp;
    }
};
