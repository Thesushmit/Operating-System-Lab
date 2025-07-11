#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) 
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) 
        tat[i] = bt[i] + wt[i];
}

void findCompletionTime(int n, int tat[], int ct[]) {
    for (int i = 0; i < n; i++)
        ct[i] = tat[i];
}

void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], ct[n], total_wt = 0, total_tat = 0, total_ct = 0;
    
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    findCompletionTime(n, tat, ct);
    
    printf("Processes   Burst time   Waiting time   Turn around time   Completion time\n");
    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        total_ct += ct[i];
        printf("   %d          %d             %d               %d              %d\n", (i + 1), bt[i], wt[i], tat[i], ct[i]);
    }
    
    printf("Average waiting time = %f\n", (float)total_wt / n);
    printf("Average turn around time = %f\n", (float)total_tat / n);
    printf("Average completion time = %f\n", (float)total_ct / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {10, 5, 8};
    
    findavgTime(processes, n, burst_time);
    return 0;
}

