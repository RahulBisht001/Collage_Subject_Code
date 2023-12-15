#include <stdio.h>

void displayFrames(int frames[], int n) {
    printf("Current Frames: |");
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf(" - |");
        else
            printf(" %d |", frames[i]);
    }
    printf("\n");
}

void lruPageReplacement(int referenceString[], int size, int frameCount) {
    int frame[frameCount];
    int indices[frameCount];
    int pageFaults = 0;
    int hits = 0;

    for (int i = 0; i < frameCount; i++) {
        frame[i] = -1;
        indices[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        displayFrames(frame, frameCount);

        int pageExists = 0;

        for (int j = 0; j < frameCount; j++) {
            if (frame[j] == referenceString[i]) {
                pageExists = 1;
                hits++;
                indices[j] = i;
                break;
            }
        }

        if (!pageExists) {
            int leastUsed = 0;
            for (int j = 0; j < frameCount; j++) {
                if (indices[j] < indices[leastUsed])
                    leastUsed = j;
            }
            printf("Page %d: Page Fault ", referenceString[i]);
            frame[leastUsed] = referenceString[i];
            indices[leastUsed] = i;
            pageFaults++;
        } else {
            printf("Page %d: Page Hit ", referenceString[i]);
        }
    }

    printf("\nTotal Page Faults using LRU: %d\n", pageFaults);
    printf("Total Page Hits using LRU: %d\n", hits);
    printf("Hit Ratio using LRU: %.2f\n", (float)hits / size);
    printf("Miss Ratio using LRU: %.2f\n", (float)pageFaults / size);
}

int main() {
    int size;
    printf("Enter the size of the reference string: ");
    scanf("%d", &size);

    int referenceString[size];
    printf("Enter the reference string: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &referenceString[i]);

    int frameCount;
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    printf("\n\n");
    lruPageReplacement(referenceString, size, frameCount);

    return 0;
}
