
bool is_simulation_running;
void MainMenuAction(unsigned char index) {
    switch(index) {
        case 0:
            switch(is_simulation_running) {
                case false:
                for(int i=0;i<cpulen;i++) {
                    int win_x = (i*256)%1024;
                    int win_y = floor(i/4)*256;
                    int xgap = max(1, win_x)/128;
                    int ygap = max(1, win_y)/128;
                    SimulationWindow(win_x+xgap, win_y+ygap, 256, 256, i);
                    // wprintf(L"\x1b[%d;2H%d", 15+i, win_x);
                    sleep(0);
                }
                is_simulation_running = true;
                break;

                case true:
                    for(int i=0;i<cpulen;i++) {
                        closeWin(i);
                    }
                    is_simulation_running = false;
                break;
            }
        break;
        case 1:
            closeApp(1);
        break;
    }
}

void *MainWin(void *vargp) {
    mainMenu = MainMenu();
    mainMenu.action = MainMenuAction;
    MainWinArgs args = *(MainWinArgs *)vargp;
    Brain *tbrain;
    NeuralStructure tneuron = newNeuron(16, 14, 1, &tbrain); 
    // tneuron.brain = *(struct Brain*)&tbrain;
    // tneuron.brain->v = 5;
    Screen *screen = getDisplayInfo(0);
    // wprintf(L"Creating a test lifeform...\nNeural Structure: %s\n", randfb(0, .025), tneuron.created ? "true" : "false");
    //Defining and drawing the blinking cursor
    while(1) {
        drawMenu(&mainMenu, 2, 2, 24);
        usleep(16666.000);
    }
    return (NULL);
}
