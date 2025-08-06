class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        vector<int>ne;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]== 0)
            {
                zeroes++;
            }
            if(nums[i]!=0)
            {
                ne.push_back(nums[i]);
            }
        }
        while(zeroes--)
        {
            ne.push_back(0);
        }

        for(int i=0;i<nums.size();i++)
        {
            nums[i] = ne[i];
        }
    }
};