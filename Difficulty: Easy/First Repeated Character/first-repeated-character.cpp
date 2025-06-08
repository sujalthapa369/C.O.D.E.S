class Solution {
public:
    string firstRepChar(string s) {
        int n = s.size();
        int count[256] = {0};  // ✅ Fixed: size should be 256, not 255

        for (int i = 0; i < n; i++) {
            if (count[s[i]] == 1) {
                // ✅ Return the repeated character as string
                return string(1, s[i]);
            } else {
                count[s[i]]++;
            }
        }

        // ✅ This should be *outside* the loop
        return "-1";
    }
};
