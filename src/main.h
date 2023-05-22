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

#define max_particles 9000

#include "libs/libs.h"

#define cpulen get_nprocs()
bool threadfin_counter[96];

bool all_threads_finished() {
    bool tf=false;
    int count=0;
    for(int i=0;i<cpulen;i++) {
        if(threadfin_counter[i]==true) {
            count++;
        }
        if(count>=cpulen-1) {
            tf=true;
        }
    }
  
    return tf;
}

bool flush_threads() {
    for(int i=0;i<cpulen;i++) {
        threadfin_counter[i]=false;
    }
}


typedef struct Terminal {
    unsigned short int width;
    unsigned short int height;
} Terminal;
Terminal terminal;
void init_defaults() {
    time_t t;
    srand((unsigned) time(&t));
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    terminal.width = w.ws_col;
    terminal.height = w.ws_row;
    setlocale(LC_ALL, "utf-8");
}
#define initialize init_defaults();


#include "win.c"

#endif