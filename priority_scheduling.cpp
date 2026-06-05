#include<bits/stdc++.h>

using namespace std;

int main() {
    cout <<" Premtive Priority Scheduling Algorithm "<<endl;
    int n = 4; /// Total number of processes
    int AT[] = {0, 1, 2, 3}; /// Arrival Time
    int BT[] = {4, 3, 2, 1}; /// Burst Time
    int PR[] = {2, 4, 1, 3}; /// Priority (Higher number means higher priority)

    // Remaining Time, Completion Time, Turnaround Time, Waiting Time

    int RT[4], CT[4], TAT[4], WT[4];

    float totalTAT = 0, totalWT = 0;

    int completed = 0, currentTime = 0;

    for(int i = 0; i < n; i++) {
        RT[i] = BT[i]; /// Initially, remaining time is equal to burst time
    }

    while(completed < n ) {
        int highestPriority = -1;
        // Find process with highest priority that has arrived and is not completed

        for(int i = 0; i < n; i++) {
            if(AT[i] <= currentTime && RT[i] > 0) {
                if(highestPriority == -1 || PR[i] > PR[highestPriority]) {
                    highestPriority = i;
                }
            }
        }
        // If no process is ready, move to the next time unit
        if(highestPriority == -1) {
            currentTime++;
            continue;
        }

        RT[highestPriority]--; /// Execute the process for one time unit
        currentTime++;


        if(RT[highestPriority] == 0) { /// Process is completed
            completed++;
            CT[highestPriority] = currentTime; /// Completion time
            TAT[highestPriority] = CT[highestPriority] - AT[highestPriority]; /// Turnaround time
            WT[highestPriority] = TAT[highestPriority] - BT[highestPriority]; /// Waiting time

            totalTAT += TAT[highestPriority];
            totalWT += WT[highestPriority];
        }
    }
    
    cout << "Average Turnaround Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;

}