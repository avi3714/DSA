class Solution {
public:
    string longestCommonSubstr(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int maxi = 0;
        int row = -1, column = -1;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    // Fix: only update if indices mirror properly
                    if ((n1 - i) == (j - dp[i][j])) {
                        if (dp[i][j] > maxi) {
                            maxi = dp[i][j];
                            row = i;
                            column = j;
                        }
                    }
                }
            }
        }

        cout << maxi << endl;
        string finalans = "";
        if (maxi == 0) return finalans;

        // Correct substring from s2 (original string)
        for (int i = column - maxi; i < column; i++) {
            finalans.push_back(s2[i]);
        }

        return finalans;
    }

    string longestPalindrome(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return longestCommonSubstr(s, t);
    }
};
