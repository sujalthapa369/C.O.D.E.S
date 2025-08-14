#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1;
        
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        int maxi = sum;
        
        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k]; 
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};
