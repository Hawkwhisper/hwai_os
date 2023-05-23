
void *MainWin(void *vargp) {
    MainWinArgs args = *(MainWinArgs *)vargp;
    
    Screen *screen = getDisplayInfo(0);
    wprintf(L"A %f Program initialized.\nScreen:  [ %d / %d ] \n", randfb(0, .025), screen->width, screen->height);

    while(1) {
        usleep(16666.000);
    }
    return (NULL);
}
