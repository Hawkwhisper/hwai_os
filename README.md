# About

This is just a fun challenge... It originally started with NodeJS - I'm trying to recreate A.I without any documentation or videos of any kind to show me the way, I'm only allowed to use the limited knowledge I have on Neural Networks in actual brains and whatnot, it's been fun! I've been going ham on C language for the past week or 2 and I'm comfortable enough with it now to really move things along. As such I'm making it open source ^.^

`run.sh` is a shell script that runs this;

Required:
Linux... this uses libx11, so if you're on windows be sure to use WSL with an x window service or windows 11's built in linux gui handler thing...

All reqs: (see src/main.h)

X11/Xlib.h
X11/Xutil.h
X11/Xos.h
stdio.h
stdarg.h
stdlib.h
stdbool.h
string.h
assert.h
pthread.h
locale.h
wchar.h
termios.h
unistd.h
sys/sysinfo.h
sys/resource.h
sys/ioctl.h
errno.h

---

## Neural Algorithm
Variable map:

- bce<hr>Brains current energy levels<br>$Min^|Max\left ( { \frac{0.000000000000000}{1.000000000000000}} \right )$
- nc <hr> Neural Count, how many neurons there are within the brain container thing
- rpi<hr> a random between 0 and 2×π
- e <hr> Effeciency of this neuron (calculated by $ distance $)
- lo <hr> The amount of outputs this neuron currently has
- oe <hr> Output node's effeciency
- d <hr> Distance between the 2 neurons
- ie <hr> The input node's effeciency of the receiving neuron
- sx, sy, sz <hr> Self neuron - the one doing this's x y and z position in the brain
- cx, cy, cz <hr> Connecting neuron - the neuron the current output node is connected to's x, y and z position in the brain


    The above variables are used for this algorithm, which each neuron processes every tick:
<style>.d{zoom:2}</style>
<div class='d'>

$$
\frac{1}{\left(\frac{bce}{\sqrt{nc}}+cos(rpi)\right)\cdot\left(\frac{\frac{e}{lo+oe}}{sin(rpi)}\cdot\frac{ie}{oe}d\right)}
$$

</div>

^ <b>I COULD BE WRONG</b> on this visualization... I suck at irl math, and I had a friend (emi) help me out with this one.

The algorithm in code

```c
//split
float results =
        1 / 
        (
            bce / sqrt(nc) + cos(rpi[0]) *
            (
                (
                    e / 
                    (
                        lo + le
                    ) / sin(rpi[1])
                ) * (
                    d * (ie / oe)
                )
            )
        );

//Compact:
1 / (bce / sqrt(nc) + cos(rpi[0]) *((e / (lo + le) / sin(rpi[1])) * (d * (ie / oe))));
```
### This is likely to change
---


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

--- MORE TO COME SOON