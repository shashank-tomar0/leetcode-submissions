class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int pref = 0;
        unordered_map<int , int> pref_map;
        pref_map[0] = 1;
        for(int num : nums){
            pref += num;
            int tar = pref - k;
            if(pref_map.find(tar) != pref_map.end()){
                count += pref_map[tar];
            }
            pref_map[pref]++;
        }
        return count;
    }
};