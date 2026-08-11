#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int prefixSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        while (numSet.count(prefixSum)) {
            prefixSum++;
        }
        
        return prefixSum;
    }
};