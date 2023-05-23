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
#include <termios.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <sys/ioctl.h>
#include <errno.h>

#include "definitions.h"
#include "libs/libs.h"

//stdio stuff
typedef struct Terminal {
    unsigned short int width;
    unsigned short int height;
} Terminal;
Terminal terminal;

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
}

#define initialize init_defaults();


#include "win.c"

#endif