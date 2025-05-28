class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int cumsum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
        cumsum += arr[i];
            maxi = max(maxi, cumsum);

            if (cumsum < 0) {
                cumsum = 0;
            }
        }
        return maxi;
        
    }
};