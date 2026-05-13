#include <bits/stdc++.h>
using namespace std;

int main() 
{
    cout << "FCFS Scheduling\n\n";

    int n = 4; // total number of processes

    int pid[] = {1, 2, 3, 4}; // Process IDs

    int AT[] = {0, 1, 5, 6}; // Arrival Time

    int BT[] = {4, 3, 2, 1}; // Burst Time

    int CT[n], TAT[n], WT[n]; 
    // Completion Time, Turn Around Time, Waiting Time

    int currentTime = 0;

    // FCFS Calculation
    for(int i = 0; i < n; i++)
    {
        // If CPU is idle
        if(currentTime < AT[i])
        {
            currentTime = AT[i];
        }

        // Completion Time
        CT[i] = currentTime + BT[i];

        // Update current time
        currentTime = CT[i];

        // Turn Around Time
        TAT[i] = CT[i] - AT[i];

        // Waiting Time
        WT[i] = TAT[i] - BT[i];
    }

    // Display Table
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << pid[i] << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << endl;
    }

    // Average TAT and WT
    float avgTAT = 0, avgWT = 0;

    for(int i = 0; i < n; i++)
    {
        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    avgTAT /= n;
    avgWT /= n;

    cout << "\nAverage Turn Around Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;

    return 0;
}