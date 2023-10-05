#include <stdio.h>
struct process {
    int pid;
    int at;
    int bt;
    int remaining_bt; 
    int ct;
    int tat;
    int wt;
    int priority;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process arr[n];
    int total_tat = 0, total_wt = 0, curr_time = 0;

    for (int i = 0; i < n; i++) {
        arr[i].pid = i + 1;
        printf("Enter the arrival time, burst time, and priority of %d process: ", arr[i].pid);
        scanf("%d %d %d", &arr[i].at, &arr[i].bt, &arr[i].priority);
        arr[i].remaining_bt = arr[i].bt;
    }

    int completed = 0, idle_time = 0;

    while (completed != n) {
        int idx = -1;
        int min_priority = 1e9;
        
        for (int i = 0; i < n; i++) {
            if (arr[i].at <= curr_time && arr[i].remaining_bt > 0) {
                if (arr[i].priority < min_priority || 
                    (arr[i].priority == min_priority && arr[i].at < arr[idx].at)) {
                    min_priority = arr[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            arr[idx].remaining_bt--;
            if (arr[idx].remaining_bt == 0) {
                completed++;
                arr[idx].ct = curr_time + 1;
                arr[idx].tat = arr[idx].ct - arr[idx].at;
                arr[idx].wt = arr[idx].tat - arr[idx].bt;
                total_tat += arr[idx].tat;
                total_wt += arr[idx].wt;
            }
            curr_time++;
        } else {
            curr_time++;
            idle_time++;
        }
    }

    printf("%.2f is the average Turnaround time\n", (float)total_tat / n);
    printf("%.2f is the average Waiting time\n", (float)total_wt / n);
    printf("CPU Utilization = %.2f\n", (float)(curr_time - idle_time) / curr_time);

    printf("-----------------------------------------------------------------\n");
    printf("| Process | BT  | Priority | CT    | TAT   | WT    |\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)    
        printf("| %d\t  | %d\t| %d\t   | %d\t   | %d\t   | %d\t   |\n", arr[i].pid, arr[i].bt, arr[i].priority, arr[i].ct, arr[i].tat, arr[i].wt);
    printf("-----------------------------------------------------------------\n");

    return 0;
}
