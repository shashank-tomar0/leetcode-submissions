class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1 , 0);
        for (int i = n - 1; i >= 0; i--){
            int max_diff = INT_MIN;
            int curr = 0;
            for (int k = 1; k <= 3 && i + k <= n; k++){
                curr += stoneValue[i + k - 1];
                max_diff = max(max_diff , curr - dp[i + k]);
            }
            dp[i] = max_diff;
        }
        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};