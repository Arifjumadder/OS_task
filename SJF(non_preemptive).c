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

void findSJF(Process proc[],int n)
{
    int remainingTime[n];
    for(int i=0; i<n; i++)
    {
        remainingTime[i]=proc[i].burst_time;

    }
    int currentTime=0;
    int complete=0;
    int shortest=0;
    int minBurst=9999;
    while(complete<n)
    {

        minBurst=9999;
        for(int i=0; i<n; i++)
        {
            if(proc[i].arrival_time<=currentTime && remainingTime[i]<minBurst && remainingTime[i]>0)
            {
                minBurst=remainingTime[i];
                shortest=i;
            }

        }


        remainingTime[shortest]--;
        if(remainingTime[shortest]==0)
        {
            complete++;
            proc[shortest].completion_time=currentTime+1;
            proc[shortest].turn_around_time=proc[shortest].completion_time-proc[shortest].arrival_time;
            proc[shortest].waiting_time=proc[shortest].turn_around_time-proc[shortest].burst_time;

        }
        currentTime++;
    }
}


void displayprocessdetails(Process proc[],int n)
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
    Process proc[5]= {{1,0,5},{2,2,3},{3,1,8},{4,4,2},{5,3,4}};
    findSJF(proc,n);
    displayprocessdetails(proc,n);
}
