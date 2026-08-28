#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string lexPalindromicPermutation(std::string s, std::string target) {
        int n = s.length();
        int half_len = n / 2;
        std::vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        int odd_count = 0;
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        if (odd_count > 1) {
            return "";
        }
        std::vector<int> freq(26, 0);
        for (int i = 0; i < 26; ++i) {
            freq[i] = counts[i] / 2;
        }

        auto build_palindrome = [&](const std::string& left) {
            std::string right = left;
            std::reverse(right.begin(), right.end());
            if (mid_char != '\0') {
                return left + mid_char + right;
            }
            return left + right;
        };

        std::string first_half = "";
        int pos = 0;

        while (pos < half_len) {
            int t_char = target[pos] - 'a';
            if (freq[t_char] > 0) {
                first_half.push_back(target[pos]);
                freq[t_char]--;
                pos++;
            } else {
                break;
            }
        }

        if (pos == half_len) {
            std::string candidate = build_palindrome(first_half);
            if (candidate > target) {
                return candidate;
            }
        }

        while (pos >= 0) {
            if (pos < half_len) {
                int t_char = target[pos] - 'a';

                for (int c = t_char + 1; c < 26; ++c) {
                    if (freq[c] > 0) {
                        std::string res_half = first_half.substr(0, pos);
                        res_half.push_back('a' + c);
                        freq[c]--;

                        for (int i = 0; i < 26; ++i) {
                            res_half.append(freq[i], 'a' + i);
                        }

                        return build_palindrome(res_half);
                    }
                }
            }
            if (pos > 0) {
                pos--;
                int reclaimed = first_half.back() - 'a';
                first_half.pop_back();
                freq[reclaimed]++;
            } else {
                break;
            }
        }

        return "";
    }
};