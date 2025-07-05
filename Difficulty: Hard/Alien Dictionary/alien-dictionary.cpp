class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> visited(26, 0); // used to track characters that are present in input
        vector<int> indegrees(26, 0);

        // Mark characters that are present
        for (string &word : words) {
            for (char c : word) {
                visited[c - 'a'] = 1;
            }
        }

        // Build adjacency list based on the first differing character
        for (int i = 1; i < n; i++) {
            string s1 = words[i - 1];
            string s2 = words[i];
            int len = min(s1.length(), s2.length());
            int j = 0;
            for (; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegrees[s2[j] - 'a']++;
                    break;
                }
            }
            // If no break happened and s1 is longer, then s2 is invalid prefix
            if (j == len && s1.length() > s2.length()) return "";
        }

        // Topological sort
        queue<int> q;
        string s5 = "";

        for (int i = 0; i < 26; i++) {
            if (visited[i] && indegrees[i] == 0) {
                q.push(i);
            }
        }

        int count2 = 0;
        while (!q.empty()) {
            int r = q.front(); q.pop();
            count2++;
            s5.push_back('a' + r);

            for (int j = 0; j < adj[r].size(); j++) {
                indegrees[adj[r][j]]--;
                if (indegrees[adj[r][j]] == 0) {
                    q.push(adj[r][j]);
                }
            }
        }

        int totalPresent = 0;
        for (int i = 0; i < 26; i++) {
            if (visited[i]) totalPresent++;
        }

        return (count2 == totalPresent) ? s5 : "";
    }
};
