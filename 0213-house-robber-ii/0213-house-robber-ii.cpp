class Solution {
public:
    int t[101];

    int solve(vector<int>& nums, int end, int idx) {
        if (idx > end) return 0;
        if (t[idx] != -1) return t[idx];

        int steal = nums[idx] + solve(nums, end, idx + 2);
        int skip = solve(nums, end, idx + 1);

        return t[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int takeFrom0 = solve(nums, n - 2, 0);

        memset(t, -1, sizeof(t));
        int takeFrom1 = solve(nums, n - 1, 1);

        return max(takeFrom0, takeFrom1);
    }
};
