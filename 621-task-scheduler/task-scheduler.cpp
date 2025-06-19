class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks)
            freq[task - 'A']++;

        priority_queue<int> pq;
        for (int f : freq)
            if (f > 0)
                pq.push(f);

        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            // Move back all tasks whose cooldown has ended
            while (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                if (freq > 1)
                    cooldown.push({freq - 1, time + n + 1});
            }

            time++;
        }

        return time;
    }
};
