class Solution {
public:
    int t[101];
    int solve(vector<int>&nums,int n,int index)
    {
        if(index>=n) return 0;
        if(t[index]!=-1)
        {
            return t[index];
        }
        int steal = nums[index] + solve(nums,n,index+2);
        int skip = solve(nums,n,index+1);

        return t[index] = max(steal, skip); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,n,0);
    }
};