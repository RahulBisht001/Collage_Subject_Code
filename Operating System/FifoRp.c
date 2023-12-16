#include <stdio.h>

void displayFrames(int numFrames, int frames[numFrames]) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

void fifoPageReplacement(int pages[], int n, int numFrames) {
    int frames[numFrames];
    int pageFaults = 0;
    int hits = 0;
    int currentIndex = 0;

    for (int i = 0; i < numFrames; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int pageExists = 0;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                pageExists = 1;
                hits++;
                break;
            }
        }

        if (!pageExists) {
            frames[currentIndex] = pages[i];
            currentIndex = (currentIndex + 1) % numFrames;
            pageFaults++;
            printf("Page %d: Page Fault ", pages[i]);
        } else {
            printf("Page %d: Page Hit ", pages[i]);
        }

        displayFrames(numFrames, frames);
    }

    printf("Total Page Faults using FIFO: %d\n", pageFaults);
    printf("Total Page Hits using FIFO: %d\n", hits);
    printf("Hit Ratio using FIFO: %f\n", (float)hits / n);
    printf("Miss Ratio using FIFO: %f\n", (float)pageFaults / n);
}

int main() {
    printf("\n\n");
    int n;
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    int frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("\n\n");
    fifoPageReplacement(pages, n, frames);
    return 0;
}
