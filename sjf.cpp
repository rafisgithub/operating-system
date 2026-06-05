#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << "Shortest Job First CPU Scheduling Algorithm\n\n";

    int n = 3;

    int pid[] = {1, 2, 3};
    int AT[] = {0, 2, 4};
    int BT[] = {6, 8, 3};

    int CT[3], TAT[3], WT[3];
    bool done[3] = {false};

    int currentTime = 0, completed = 0;

    float avgTAT = 0, avgWT = 0;

    while (completed < n) {

        int index = -1;
        int minBT = INT_MAX;

        // Step 1: find shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (!done[i] && AT[i] <= currentTime) {
                if (BT[i] < minBT) {
                    minBT = BT[i];
                    index = i;
                }
            }
        }

        // Step 2: if no process is available, CPU is idle
        if (index == -1) {
            currentTime++;
            continue;
        }

        // Step 3: execute selected process
        currentTime += BT[index];
        CT[index] = currentTime;
        done[index] = true;
        completed++;
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    avgTAT /= n;
    avgWT /= n;

    // Output table
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout <<"p" << pid[i] << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << "\n";
    }

    cout << "\nAverage Turn Around Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;

    return 0;
}