
void *SimulationWorker(void *vargp) {
    win_pos tmp = *(win_pos*)vargp;
                wprintf(L"\x1b[15;2H%d", tmp.x);
    NewXWindow(tmp.index, 256, 256, tmp.x, tmp.y, "Simulation", "hehe", true);
    while(1) {
        usleep(16666.6666);
    }
    return (NULL);
}

void SimulationWindow(int x, int y, int width, int height, int index) {
    win_pos tmp = {x, y, width, height, index};
    pthread_t win_thread = ThreadProcessor(&SimulationWorker, &tmp);
}