#include<bits/stdc++.h>
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

void findcompletionTime(Process proc[],int n)
{
    proc[0].completion_time=proc[0].burst_time;
    for(int i=1; i<n; i++)
    {
        proc[i].completion_time=proc[i-1].completion_time+proc[i].burst_time;
    }
}

void findturnaroundTime(Process proc[],int n)
{
    for(int i=0; i<n; i++)
    {
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}

void findwaitingTime(Process proc[],int n)
{
    proc[0].waiting_time=0;

    for(int i=1; i<n; i++)
    {
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}

void findFCFS(Process proc[],int n)
{
    findcompletionTime(proc,n);
    findturnaroundTime(proc,n);
    findwaitingTime(proc,n);

}
void printFCFS(Process proc[],int n)
{
    double avg_turnaround_time=0,avg_waiting_time=0;

    cout<<"CPU Scheduling"<<endl;

    cout<<"PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<proc[i].pid<<"\t\t"<<proc[i].arrival_time<<"\t\t"<<proc[i].burst_time<<"\t\t"<<proc[i].completion_time<<"\t\t"<<proc[i].turn_around_time<<"\t\t"<<proc[i].waiting_time<<endl;
        avg_turnaround_time+=proc[i].turn_around_time;
        avg_waiting_time+=proc[i].waiting_time;
    }
    cout<<"Average turnaround time = "<<avg_turnaround_time/n<<endl;
    cout<<"Average Waiting time = "<<avg_waiting_time/n<<endl;
}
int main()
{
    int n=5;
    Process proc[5]= {{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    findFCFS(proc,n);
    printFCFS(proc,n);
}
