
void redraw(int index) {
    XFlush(displays[index]);
    XSetBackground(displays[index],gc[index],WindowColors[index][0]);
    XSetForeground(displays[index],gc[index],WindowColors[index][1]);
	XClearWindow(displays[index], xwindows[index]);
};

void NewXWindow(unsigned short int index, int width, int height, int x, int y, char *title1, char *title2, bool transparent) {
    int w = width;
    int h = height;
	unsigned long black,white;
	displays[index]=XOpenDisplay((char *)0);
    
    XVisualInfo vinfo;
    int depth = 24;
    if(transparent==true) depth=32;
    XMatchVisualInfo(displays[index], DefaultScreen(displays[index]), depth, TrueColor, &vinfo);

    XSetWindowAttributes attr;
    attr.colormap = XCreateColormap(displays[index], DefaultRootWindow(displays[index]), vinfo.visual, AllocNone);
    attr.border_pixel = 0;
    attr.background_pixel = 0x111111;
    attr.win_gravity = StaticGravity;
    attr.bit_gravity = StaticGravity;
    attr.override_redirect = true;

   	screen[index]=DefaultScreen(displays[index]);
   	xwindows[index]=XCreateWindow(displays[index],DefaultRootWindow(displays[index]),0,0,	
		w, h, 0,vinfo.depth, InputOutput, vinfo.visual, CWColormap | CWBorderPixel | CWBackPixel, &attr);
	XSetStandardProperties(displays[index],xwindows[index],title1,title2,None,NULL,0,NULL);
	XSelectInput(displays[index], xwindows[index], StructureNotifyMask|NoEventMask|ExposureMask|ButtonPressMask|KeyPressMask);
    gc[index]=XCreateGC(displays[index], xwindows[index], 0,0);        
    XMapRaised(displays[index], xwindows[index]);
    XSetWindowBorder(displays[index], xwindows[index], 0xffaa99);
    setDrawColor(index, 0xffffff, 0x000000);

    sleep(0);
    XMoveWindow(displays[index], xwindows[index], x, y);
    XResizeWindow(displays[index], xwindows[index], width, height);
    redraw(index);
}


void setDrawColor(int index, unsigned long bg, unsigned long fg) {
    WindowColors[index][0]=fg;
    WindowColors[index][1]=bg;
    XSetBackground(displays[index],gc[index],WindowColors[index][0]);
    XSetForeground(displays[index],gc[index],WindowColors[index][1]);
}

void pixel(int index, int x, int y, unsigned long color) {
    setDrawColor(index, color, WindowColors[index][1]);
    XDrawPoint(displays[index], xwindows[index], gc[index], x, y);
}

void rect(int index, int x, int y, int width, int height, unsigned long fill) {
    setDrawColor(index, fill, WindowColors[index][1]);
    XFillRectangle(displays[index], xwindows[index], gc[index], x, y, width, height);
    XDrawRectangle(displays[index], xwindows[index], gc[index], x, y, width, height);
}

void text(int index, int x, int y, char *msg, unsigned long color) {
    setDrawColor(index, color, WindowColors[index][1]);
    XDrawString(displays[index], xwindows[index], gc[index], x, y, msg, strlen(msg));
}

void closeWin(int index) {
    XCloseDisplay(displays[index]);
}