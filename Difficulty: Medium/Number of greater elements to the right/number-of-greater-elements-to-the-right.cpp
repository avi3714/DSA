#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit; int n;
    FenwickTree(int n) : n(n), bit(n+1,0) {}
    void update(int idx, int val) {
        for(; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for(; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
    int query_range(int l, int r) {
        return query(r) - query(l-1);
    }
};

class Solution {
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // Coordinate compression
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

        auto getRank = [&](int val) {
            return int(std::lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin()) + 1;
        };

        // Prepare queries sorted by index descending
        vector<pair<int,int>> q;
        for(int i = 0; i < queries; i++)
            q.push_back({indices[i], i});
        sort(q.rbegin(), q.rend());

        FenwickTree fenw((int)sortedArr.size());

        vector<int> ans(queries, 0);
        int j = 0;

        for(int i = n - 1; i >= 0; i--) {
            int rank = getRank(arr[i]);
            fenw.update(rank, 1); // Insert frequency of arr[i]

            while(j < queries && i == q[j].first) {
                int r = getRank(arr[i]);
                // Number of elements strictly greater than arr[i] = total inserted - query(rank)
                ans[q[j].second] = fenw.query((int)sortedArr.size()) - fenw.query(r);
                j++;
            }
            if(j == queries) break;
        }

        return ans;
    }
};
