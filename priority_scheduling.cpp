#include <bits/stdc++.h>
using namespace std;

struct Process {
    string id;
    int burst;
    int remaining;
    int priority;
    int arrival;
    int waiting;
    int turnaround;
    int completion;
    bool finished = false;
};

bool sortByArrival(const Process& a, const Process& b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cin >> n;
    vector<Process> proc(n);

    for (int i = 0; i < n; i++) {
        cin >> proc[i].id >> proc[i].arrival >> proc[i].burst >> proc[i].priority;
        proc[i].remaining = proc[i].burst;
    }

    sort(proc.begin(), proc.end(), sortByArrival);

    int completed = 0, time = 0;
    double total_waiting = 0, total_turnaround = 0;
    vector<pair<string, int>> timeline;

    string last_id = "";
    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;


        for (int i = 0; i < n; i++) {
            if (proc[i].arrival <= time && proc[i].remaining > 0 && proc[i].priority < highest_priority) {
                highest_priority = proc[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            proc[idx].remaining--;

            if (proc[idx].id != last_id) {
                timeline.push_back({proc[idx].id, time});
                last_id = proc[idx].id;
            }

            if (proc[idx].remaining == 0) {
                proc[idx].completion = time + 1;
                proc[idx].turnaround = proc[idx].completion - proc[idx].arrival;
                proc[idx].waiting = proc[idx].turnaround - proc[idx].burst;
                total_waiting += proc[idx].waiting;
                total_turnaround += proc[idx].turnaround;
                proc[idx].finished = true;
                completed++;
            }
        } else {
            if (last_id != "idle") {
                timeline.push_back({"idle", time});
                last_id = "idle";
            }
        }

        time++;
    }
    timeline.push_back({last_id, time});
    string gantt = "|", border = "-";
    for (size_t i = 0; i < timeline.size() - 1; i++) {
        gantt += "  " + timeline[i].first + "  |";
        border += "-------";
    }

    cout << "Gantt Chart:\n" << border << "\n"
         << gantt << "\n"
         << border << "\n"
         << timeline[0].second;

    for (size_t i = 1; i < timeline.size(); i++) {
        int gap = timeline[i].second - timeline[i - 1].second;
        cout << setw(7) << timeline[i].second;
    }


    cout << "\n\nAverage waiting time = " << total_waiting / n << "\n";
    cout << "Average turnaround time = " << total_turnaround / n << "\n\n";


    cout << "Process   | Arrival | Burst | Priority | Waiting | Turnaround\n";
    cout << "-------------------------------------------------------------\n";
    for (const auto& p : proc) {
        cout << setw(8) << p.id << " | "
             << setw(7) << p.arrival << " | "
             << setw(5) << p.burst << " | "
             << setw(8) << p.priority << " | "
             << setw(7) << p.waiting << " | "
             << setw(10) << p.turnaround << "\n";
    }

    return 0;
}
