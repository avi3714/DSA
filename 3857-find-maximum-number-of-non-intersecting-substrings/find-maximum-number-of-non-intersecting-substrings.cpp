class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<vector<int>> adj(26);
        
        // Step 1: Fill adjacency list for each character
        for (int i = 0; i < n; ++i) {
            adj[word[i] - 'a'].push_back(i);
        }

        vector<pair<int, int>> intervals;

        // Step 2: For each character's position list, find valid start-end pairs
        for (int i = 0; i < 26; ++i) {
            const auto& pos = adj[i];
            int sz = pos.size();
            for (int j = 0; j < sz; ++j) {
                int start = pos[j];
                // Find the first end position ≥ start + 3
                for (int k = j + 1; k < sz; ++k) {
                    if (pos[k] - start >= 3) {
                        intervals.emplace_back(start, pos[k]);
                        break; // Only the first such pair is taken
                    }
                }
            }
        }

        // Step 3: Sort by end index for greedy selection
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // Step 4: Greedy selection of non-overlapping intervals
        int count = 0, lastEnd = -1;
        for (const auto& [start, end] : intervals) {
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        return count;
    }
};
