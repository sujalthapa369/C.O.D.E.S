class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
     int n = deadline.size();
    vector<int> ans = {0, 0};

    // pair the profit and deadline of
    // all the jos together
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    // sort the jobs based on deadline
    // in ascending order
    sort(jobs.begin(), jobs.end());

    // to maintain the scheduled jobs based on profit
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto &job : jobs) {
        
        // if job can be scheduled within its deadline
        if (job.first > pq.size())
            pq.push(job.second);
        
        // Replace the job with the lowest profit
        else if (!pq.empty() && pq.top() < job.second) {
            pq.pop();
            pq.push(job.second);
        }
    }

    while (!pq.empty()) {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }

    return ans;
}
};