class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();
        std::vector<int> sortedScore = score; // Keep a copy to sort
        std::sort(sortedScore.rbegin(), sortedScore.rend()); // Sort in descending order

        std::unordered_map<int, std::string> rankMap;

        for (int i = 0; i < n; ++i) {
            if (i == 0)
                rankMap[sortedScore[i]] = "Gold Medal";
            else if (i == 1)
                rankMap[sortedScore[i]] = "Silver Medal";
            else if (i == 2)
                rankMap[sortedScore[i]] = "Bronze Medal";
            else
                rankMap[sortedScore[i]] = std::to_string(i + 1);
        }

        std::vector<std::string> result;
        for (int i = 0; i < n; ++i) {
            result.push_back(rankMap[score[i]]);
        }

        return result;
    }
};
