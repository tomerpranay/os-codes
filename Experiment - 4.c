#include <stdio.h>

int main() {
    int n, total=0, totalWaiting = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	int arrival[n], burst[n], arr[n], waiting[n], last[n], priority[n];
	for (int i=0; i<n; i++) {
	    printf("Arrival time of P%d: ", i);
	    scanf("%d", &arrival[i]);
	    printf("Burst time of P%d: ", i);
	    scanf("%d", &burst[i]);
	    printf("Priority of P%d: ", i);
	    scanf("%d", &priority[i]);
		total+=burst[i];
	    arr[i] = burst[i];
	    last[i] = arrival[i];
	}
	for (int i=0; i<total; i++) {
	    int j = -1;
		for (int k=0; k<n; k++)
			if (arrival[k] <= i && arr[k] > 0 && (j < 0 || priority[k] < priority[j])) j = k;
		if (j == -1) continue;
        if (i > last[j]) waiting[j] += i - last[j];
        last[j] = i + 1;
		arr[j]--;
	}
	for (int i=0; i<n; i++) {
	    totalWaiting+=waiting[i];
	    printf("Waiting time of P%d: %d\n", i, waiting[i]);
	    printf("Turnaround time of P%d: %d\n", i, waiting[i] + burst[i]);
	}
	printf("Average waiting time: %.2f\n", (float)totalWaiting / n);
	return 0;
}