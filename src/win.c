typedef struct MainWinArgs {
    int width;
    int height;
} MainWinArgs;

char *outputString;
void *MainWin(void *vargp) {
    MainWinArgs args = *(MainWinArgs *)vargp;
    NewXWindow(0, args.width, args.height, 0, 0, "Test", "Win", true);
    int x=0;
    outputString="Initialized";
    while(1) {
        text(0, 32, 32, outputString, 0xffffff);
        usleep(6400);
    }
    return (NULL);
}
