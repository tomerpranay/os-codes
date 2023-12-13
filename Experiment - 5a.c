#include <stdio.h>

int main() {
    int n, q, total=0, totalWaiting = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter time quantum: ");
	scanf("%d", &q);
	int burst[n], arr[n], waiting[n], last[n];
	for (int i=0; i<n; i++) {
	    printf("Burst time of P%d: ", i);
	    scanf("%d", &burst[i]);
		total+=burst[i];
	    arr[i] = burst[i];
	    last[i] = 0;
	}
	int temp = 0, j = -1;
	for (int i=0; i<total; i++) {
	    while (temp == q || j < 0 || arr[j] == 0) {
	        do { j = (j + 1) % n; } while (arr[j] == 0);
	        temp = 0;
	    }
        if (i > last[j]) waiting[j] += i - last[j];
        last[j] = i + 1;
		arr[j]--;
		temp++;
	}
	for (int i=0; i<n; i++) {
	    totalWaiting+=waiting[i];
	    printf("Waiting time of P%d: %d\n", i, waiting[i]);
	    printf("Turnaround time of P%d: %d\n", i, waiting[i] + burst[i]);
	}
	printf("Average waiting time: %.2f\n", (float)totalWaiting / n);
	return 0;
}