#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], ct[20];
    int i, j, temp, n;
    int totalwt = 0, totaltat = 0, totalct = 0;
    float avgwt, avgtat, avgct;

    // Input number of processes
    printf("Enter Number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;  // Process ID
    }

    // Sorting processes by Burst Time using Bubble Sort (Shortest Job First Scheduling)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculating Waiting Time, Turnaround Time, and Completion Time
    printf("Process \tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        // Waiting Time calculation
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }

        // Turnaround Time = Waiting Time + Burst Time
        tat[i] = wt[i] + bt[i];

        // Completion Time = Turnaround Time (as processes execute sequentially)
        ct[i] = tat[i];

        // Accumulate totals for averages
        totalwt += wt[i];
        totaltat += tat[i];
        totalct += ct[i];

        // Print process details
        printf("%d \t\t%d \t\t%d \t\t%d \t\t%d\n", p[i], bt[i], wt[i], tat[i], ct[i]);
    }

    // Compute averages
    avgwt = (float)totalwt / n;
    avgtat = (float)totaltat / n;
    avgct = (float)totalct / n;

    // Display averages
    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);
    printf("Average Completion Time: %.2f\n", avgct);

    return 0;
}

