pthread_t ThreadProcessor(void *processor, void *data) {
    pthread_t thread;
    pthread_create(&thread, NULL, processor, data);
    return thread;
}