class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> arr(m,vector<int>(n));
        if(m*n != size)
        {
            return {};
        }
        int index = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j] = original[index];
                index++;
            }
        }
        return arr;
    }
};