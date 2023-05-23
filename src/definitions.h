#ifndef definitions
#define definitions
#define cpulen get_nprocs()
#define DEBUG_BUFFER_LEN 2048

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct MainWinArgs {
    int x;
    int y;
    int width;
    int height;
} MainWinArgs;

#endif
