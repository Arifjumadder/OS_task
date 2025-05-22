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

void calculateTime(Process proc[],int n,int quantum)
{
    int remainingTime[n];
    for(int i=0; i<n; i++)
    {
        remainingTime[i]=proc[i].burst_time;

    }
    int currentTime=0;
    bool allDone=false;

    while(!allDone)
    {
        allDone=true;

        for(int i=0; i<n; i++)
        {
            if(remainingTime[i]>0)
            {
                allDone=false;

                if(remainingTime[i]>quantum)
                {
                    currentTime=currentTime+quantum;
                    remainingTime[i]=remainingTime[i]-quantum;
                }
                else
                {
                    currentTime=currentTime+remainingTime[i];
                    proc[i].completion_time=currentTime;
                    remainingTime[i]=0;
                }
            }
        }
    }
}


void calculateturnaroundTime(Process proc[],int n)
{
    for(int i=0; i<n; i++)
    {
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}

void calculatewaitingTime(Process proc[],int n)
{


    for(int i=0; i<n; i++)
    {
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}


void printTable(Process proc[],int n)
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
    int n=4,quantum=2;
    
    Process proc[4]= {{1,0,4},{2,1,3},{3,2,5},{4,3,2}};
    calculateTime(proc,n,quantum);
    calculateturnaroundTime(proc,n);
    calculatewaitingTime(proc,n);
    printTable(proc,n);
}
