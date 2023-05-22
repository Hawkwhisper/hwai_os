#include "main.h"
void main() {
    initialize;
    MainWinArgs args = {640, 360};
    pthread_t mainwin = ThreadProcessor(&MainWin, &args);
    while(1) {
        sleep(1);
    }
}