class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> count;
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique;
            for (int j = i; j < i + k; j++) {
                unique.insert(nums[j]);
            }
            for (int val : unique) {
                count[val]++;
            }
        }
        int res = -1;
        for (const auto& [val , cont] : count) {
            if (cont == 1) {
                res = max(res , val);
            }
        }
        return res;
    }
};