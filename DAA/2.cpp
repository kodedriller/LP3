#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Job {
    int id;
    int profit;
    int deadline;
};

bool comparator(Job a, Job b) {
    return a.profit > b.profit;
}

void schedule(vector<Job> jobs) {
    int n = jobs.size();
    vector<int> sequence = {0};
    vector<bool> filled = {false};

    cout << "  ID: Profit (Deadline)\n\n";
    for (Job j : jobs) {
        cout << "  J" << j.id << ": " << j.profit << " (" << j.deadline << ")\n";
    }

    sort(jobs.begin(), jobs.end(), comparator);

    for (int i = 0; i < n; i++) filled[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (filled[j] == false) {
                sequence[j] = i;
                filled[j] = true;
                break;
            }
        }
    }

    int profit = 0;
    cout << "\n  Solution: ";
    for (int i = 0; i < n; i++) {
        if (filled[i]) {
            cout << "J" << jobs[sequence[i]].id << " ";
            profit += jobs[sequence[i]].profit;
        }
    }
    cout << "\n\n  Total Profit = " << profit;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    for (int i = 1; i <= n; i++) {
        Job job;
        job.id = i;
        cout << "Enter profit for job J" << i << ": ";
        cin >> job.profit;
        cout << "Enter deadline for job J" << i << ": ";
        cin >> job.deadline;
        jobs.push_back(job);
    }

    schedule(jobs);
}