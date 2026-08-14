class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> counts(26 , 0);
        int left = 0; 
        int max_len = 0;
        for (int right = 0; right < s.length(); right++) {
            counts[s[right] - 'a']++;
            while (counts[s[right] - 'a'] > 2) {
                counts[s[left] - 'a'] -= 1;
                left++;
            }
            max_len = max(max_len , right - left + 1);
        }
        return max_len;
    }
};