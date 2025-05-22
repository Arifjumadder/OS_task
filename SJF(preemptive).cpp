#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};


void findSJF(Process proc[], int n)
{
    int remainingTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = proc[i].burst_time;
    }

    int complete = 0, currentTime = 0, minBurst = INT_MAX;
    int shortest = -1;
    bool found = false;

    while (complete != n)
    {
        found = false;
        minBurst = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrival_time <= currentTime && remainingTime[i] > 0 && remainingTime[i] < minBurst)
            {
                minBurst = remainingTime[i];
                shortest = i;
                found = true;
            }
        }

        if (!found)
        {
            currentTime++;
            continue;
        }


        remainingTime[shortest]--;
        currentTime++;


        if (remainingTime[shortest] == 0)
        {
            complete++;
            proc[shortest].completion_time = currentTime;
            proc[shortest].turn_around_time = proc[shortest].completion_time - proc[shortest].arrival_time;
            proc[shortest].waiting_time = proc[shortest].turn_around_time - proc[shortest].burst_time;
        }
    }
}

void displayprocessdetails(Process proc[], int n)
{
    double avg_turnaround_time=0,avg_waiting_time=0;

    cout << "CPU Scheduling (SJF Preemptive - SRTF)" << endl;
    cout << "PID\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n";

    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t"
             << proc[i].arrival_time << "\t"
             << proc[i].burst_time << "\t"
             << proc[i].completion_time << "\t\t"
             << proc[i].turn_around_time << "\t\t"
             << proc[i].waiting_time << endl;
        avg_turnaround_time+=proc[i].turn_around_time;
        avg_waiting_time+=proc[i].waiting_time;
    }
    cout<<"Average turnaround time = "<<avg_turnaround_time/n<<endl;
    cout<<"Average Waiting time = "<<avg_waiting_time/n<<endl;
}

int main()
{
    int n = 4;
    Process proc[4] =
    {
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 9},
        {4, 3, 5},

    };

    findSJF(proc, n);
    displayprocessdetails(proc, n);


}
