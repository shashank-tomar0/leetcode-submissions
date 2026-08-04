class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minNum = *std::min_element(nums.begin(), nums.end());
        int maxNum = *std::max_element(nums.begin(), nums.end());
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        std::vector<int> missingNums;
        for (int i = minNum; i <= maxNum; i++) {
            if (numSet.find(i) == numSet.end()) {
                missingNums.push_back(i);
            }
        }
        
        return missingNums;
    }
};