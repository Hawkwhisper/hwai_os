#include "main.h"

//Since my window manager see's 2 monitors as one, the size is combined, so I use this
int _dp[2][4];
// ^ x,y width and height of the display location~ left monitor is 1080p and right one is 1440p

void main() {
    initialize;
    int _dptmp[2][4] = {{0,0,1920,1080}, {1920,0,2560,1440}};
    memcpy(_dp, _dptmp, sizeof(_dp));
    MainWinArgs mainwin_args = {_dp[1][0]+_dp[1][2]-640, _dp[1][3]-360, 640, 360}; //bottom right corner
    pthread_t mainwin = ThreadProcessor(&MainWin, &mainwin_args);
    pthread_join(mainwin, NULL);
    system ("/bin/stty cooked");
}