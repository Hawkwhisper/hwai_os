float randf() {
    float v;
    unsigned long int mv = 0xffffffff;
    v = ((float)(rand()%mv)/mv);
    return v;
}

float randfb(float MIN, float MAX) {
    float v;
    unsigned long int mv = 0xffffffff;
    v = min(max(MIN, MIN+(2*((float)(rand()%mv)/mv)*(MAX-MIN))), MAX);
    return v;
}