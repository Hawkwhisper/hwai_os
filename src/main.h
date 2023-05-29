#ifndef main_header
#define main_header
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <locale.h>
#include <wchar.h>
#include <termio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <signal.h>

#include "definitions.h"


//stdio stuff
typedef struct Terminal {
    unsigned short int width;
    unsigned short int height;
} Terminal;
Terminal terminal;

int inp;
int _presses[256];
static struct termios oldt, newt;

void closeApp() {
    /*restore the old settings*/
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    wprintf(L"\x1b[?25h\n");
    exit(1);
}
void *initInput() {
    tcgetattr( STDIN_FILENO, &oldt);
    signal(SIGINT, closeApp);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);          
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    while(1) {
        inp=getchar();
        if(_presses[inp]==0) _presses[inp]=1;
        // wprintf(L"\x1b[20;0H%i\nwhat...\n", inp);
    }  
}

void *updateInput() {
    while(1) {
        if(_presses[inp]>0) _presses[inp]++;
        sleep(0);
    }
}

bool KeyTap(char key) {
    if(_presses[key]>0) {
        _presses[key] = 0;
        return true;
    }
    return false;
}



#include "libs/libs.h"
//screen stuff
Screen *getDisplayInfo(int index) {
    Display *display;
    Screen *screen;
    display = XOpenDisplay((char *)0);
    screen = ScreenOfDisplay(display, index);
    return screen;
}

//init defaults
void init_defaults() {
    time_t t;
    srand((unsigned) time(&t));
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    terminal.width = w.ws_col;
    terminal.height = w.ws_row;
    setlocale(LC_ALL, "");
    
    pthread_t inputhandler = ThreadProcessor(&initInput, NULL);
    pthread_t inputupdater = ThreadProcessor(&updateInput, NULL);

    wprintf(L"\x1b[?25l\n");
}

#define initialize init_defaults();

#include "workers/simulation.h"
#include "win.c"

#endif