// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> index(n);  
        for (int i = 0; i < n; i++) {
            index[i] = i;  // store indices 0,1,...,n-1
        }

        // Sort indices by value/weight ratio in descending order
        sort(index.begin(), index.end(), [&](int a, int b) {
            double r1 = (double)val[a] / wt[a];
            double r2 = (double)val[b] / wt[b];
            return r1 > r2;
        });

        double totalValue = 0.0;
        int currentWeight = 0;

        // Pick items greedily
        for (int i = 0; i < n; i++) {
            int idx = index[i];  // get the index of next best item
            if (currentWeight + wt[idx] <= capacity) {
                // Take the full item
                currentWeight += wt[idx];
                totalValue += val[idx];
            } else {
                // Take the fraction that fits
                int remain = capacity - currentWeight;
                totalValue += val[idx] * ((double)remain / wt[idx]);
                break;  // knapsack is full
            }
        }

        return totalValue;
    }
};
