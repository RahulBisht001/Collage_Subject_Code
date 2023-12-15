#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek_time = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Calculate seek time
    for (i = 0; i < n; i++) {
        seek_time += abs(head - requests[i]);
        printf("Moved from %d to %d\n", head, requests[i]);
        head = requests[i];
    }

    printf("Total seek time: %d\n", seek_time);

    return 0;
}
