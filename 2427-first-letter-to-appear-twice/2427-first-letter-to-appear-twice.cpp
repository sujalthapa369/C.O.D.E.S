class Solution {
public:
    char repeatedCharacter(string s) {
        int count[256] = {0};  

        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
            if (count[s[i]] == 2) {
                return s[i];  
            }
        }

        return '-1'; }
};
