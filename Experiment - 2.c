#include <stdio.h>

int main() {
    int n, totalWaiting = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	int arrival[n], burst[n], waiting[n], arr[n];
	for (int i=0; i<n; i++) {
	    printf("Arrival time of P%d: ", i);
	    scanf("%d", &arrival[i]);
	    printf("Burst time of P%d: ", i);
	    scanf("%d", &burst[i]);
		arr[i] = arrival[i];
	}
    int temp = 0;
	for (int i=0; i<n; i++) {
	    int j = 0;
	    for (int k=0; k<n; k++)
            if (arr[k] < arr[j]) j = k;
        arr[j] = 9999;
	    if (temp > arrival[j]) waiting[j] = temp - arrival[j];
	    temp += burst[j];
	}
	for (int i=0; i<n; i++) {
	    totalWaiting+=waiting[i];
	    printf("Waiting time of P%d: %d\n", i, waiting[i]);
	    printf("Turnaround time of P%d: %d\n", i, waiting[i] + burst[i]);
	}
	printf("Average waiting time: %.2f\n", (float)totalWaiting / n);
	return 0;
}