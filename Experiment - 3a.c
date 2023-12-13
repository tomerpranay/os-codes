#include <stdio.h>

#define INF 9999

int minIndex(int arr[], int n) {
    int result = 0;
    for (int i=0; i<n; i++)
        if (arr[i] < arr[result]) result = i;
    arr[result] = INF;
    return result;
}

int main() {
    int n, totalWaiting = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	int burst[n], arr[n], waiting[n];
	for (int i=0; i<n; i++) {
	    printf("Burst time of P%d: ", i);
	    scanf("%d", &burst[i]);
	    arr[i] = burst[i];
	}
	int temp = 0;
	for (int i=0; i<n; i++) {
	    int j = minIndex(arr, n);
	    totalWaiting += temp;
	    waiting[j] = temp;
	    temp += burst[j];
	}
	for (int i=0; i<n; i++) {
	    printf("Waiting time of P%d: %d\n", i, waiting[i]);
	    printf("Turnaround time of P%d: %d\n", i, waiting[i] + burst[i]);
	}
	printf("Average waiting time: %.2f\n", (float)totalWaiting / n);
	return 0;
}