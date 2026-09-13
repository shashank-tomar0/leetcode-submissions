class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> ones1;
        std::vector<std::pair<int, int>> ones2;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        std::map<std::pair<int, int>, int> shiftCounts;
        int maxOverlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                std::pair<int, int> shift = {r2 - r1, c2 - c1};
                shiftCounts[shift]++;
                maxOverlap = std::max(maxOverlap, shiftCounts[shift]);
            }
        }

        return maxOverlap;
    }
};