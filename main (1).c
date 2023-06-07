#include <stdio.h>

// Sequence to detect: (1, 0, 1)
#define SEQ_LENGTH 3
int sequence[SEQ_LENGTH] = {1, 0, 1};

// Input data
#define INPUT_LENGTH 14
int inputData[INPUT_LENGTH] = {1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0};

int main() {
    // Determine the number of iterations for sequence detection
    int iterations = INPUT_LENGTH - SEQ_LENGTH + 1;

    // Initialize the output flag
    int sequenceDetected = 0;

    // Perform sequence detection
    for (int i = 0; i < iterations; i++) {
        int match = 1;
        for (int j = 0; j < SEQ_LENGTH; j++) {
            if (inputData[i + j] != sequence[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            sequenceDetected = 1;
            break;
        }
    }

    // Output result
    if (sequenceDetected) {
        printf("Sequence detected.\n");
    } else {
        printf("Sequence not detected.\n");
    }

    return 0;
}
