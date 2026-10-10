class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_jumps = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > max_jumps)   
                return false;
            max_jumps = max(max_jumps , i + nums[i]);
        }
        return true;
    }
};