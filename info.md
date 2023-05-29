I made this because I'm starting to get confused with stuff I wrote and I need to keep note of it all.

# libs

> cli

The CLI library I wrote holds a basic menu thing...
It's still a wip, but basically the menu classes are as follows:

```c
typedef struct MenuCursor {
   unsigned short int x;
   unsigned short int y;

   wchar_t *blinker;
   int blinker_index;
   int blinker_update_delay;
   int blinker_update_modulo;
   int max_blinker_frames;
}MenuCursor;

typedef struct Menu {
   wchar_t **options;
   MenuCursor cursor;
   void (*action)();
} Menu;
```

In short, a men holds the cursor and the options it uses, you can define the action of a menu by:

```c
mainMenu.action = MainMenuAction;
```

To create a menu and update it...

```c
Menu MainMenu() {
    wchar_t *menulist[] = {
        L"Open Windows",
        L"View Logs",
        L"Exit"
    };

    int Count = sizeof(menulist)/(sizeof(wchar_t*));
    wchar_t *blinker_theme = L"◆◈◇◈";
    /*
    First 2 values are x/y position of the cursor,
    followed by the animation sequence (blinker_theme), the index of the animation to start
    with, then the speed of the animation (lower = faster),
    and then finally, the max number of frames to display.
    Keeping it all variable just in case I wanna do something weird :P
    */
    MenuCursor cursor = {0, 0, blinker_theme, 0, 0, 5, wcslen(blinker_theme)};
    wchar_t **options =  (wchar_t**)malloc(Count * sizeof(wchar_t*));
    for (int i = 0; i < Count; i++) {
        options[i] = (wchar_t*)malloc(BUFSIZ * sizeof(wchar_t));
        options[i] = menulist[i];
    }

    Menu menu = {options, cursor};
    return menu;
}
Menu mainMenu;

void testWin() {
    mainMenu = MainMenu();
    int xpos = 0;
    int ypos = 0;
    int winwidth = 16;
    while(1) {
        drawMenu(&mainMenu, xpos, ypos, winwidth)
        sleep(0);
    }
}
```

 > math

A basic math lib, makes use of stuff like random float generation.
```c
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
```

 > mthread

This library contains a tool to create a worker thread, that's p much it; cleaner than doing the usual pthread_t every time :P
```c
//example
void main() {
    pthread_t calculator = ThreadProcessor(&calc_function, some_args_here);
}
```

 > neural_classes

This is the library that holds classes for the brain, dspace (just a struct with x/y/z), lifeform and neuron functionality.
 * Neuron
    - struct Neuron
    ```c
    typedef struct Neuron {
        __dspace position;
        Node *output_nodes;
        Node *input_nodes;
        float energy;
        int type; 
        float adv_signal;
    } Neuron;
    ```
     <code>__dspace position</code> > 
     
     the position of the neuron in the brain

     <code>Node *output_nodes</code> >
     
     Pointer to store the amount of output nodes

     <code>Node *input_nodes</code> >
     
     Pointer to store the amount of input nodes

     <code>float energy</code> >

     Energy level of the current neuron, once it reaches a certain amount, e.g 1, it fires off and adds a function stack to the brain

     <code>int type</code> >

     The type of functionality it has, will be defined later as a function, currently a placeholder and I keep forgetting to change it lol

     <code>int adv_signal</code> > wip...



