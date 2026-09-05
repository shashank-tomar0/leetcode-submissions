class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_suffix(n);
        min_suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            min_suffix[i] = min(min_suffix[i+1] ,nums[i]);
        }
        int current_max = nums[0];
        for (int i = 0; i < n; i++) {
            current_max = max(current_max , nums[i]);
            int score = current_max - min_suffix[i];
            if(score <= k) return i;
        }
        return -1;
    }
};