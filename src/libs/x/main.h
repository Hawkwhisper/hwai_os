
Display *displays[1024];
int screen[1024];
Window xwindows[1024];
GC gc[1024];
unsigned long int WindowColors[1024][2];

void redraw(int index);
void NewXWindow(unsigned short int index, int width, int height, int x, int y, char *title1, char *title2, bool transparent);
void setDrawColor(int index, unsigned long fg, unsigned long bg);
void pixel(int index, int x, int y, unsigned long color);