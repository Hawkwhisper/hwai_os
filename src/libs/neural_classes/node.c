typedef struct Node {
    float quality;
    // ^ Effects how well the signal is sent, used for randomization and increases
    //   chances of an "accident" to happen (set to 1 for perfect performance)
} Node;