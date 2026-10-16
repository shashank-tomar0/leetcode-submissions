class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int currEnd = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            farthest = max(farthest , i + nums[i]);
            if(currEnd == i){
                jumps++;
                currEnd = farthest;
                if(currEnd >= n - 1)
                    return jumps;
            }

        }
        return jumps;
    }
};