/*
    This handles the main terminals' options
*/

#ifndef LIBCLI
#define LIBCLI

#define box_char_top_bottom L"─"
#define box_char_left_right L"│"
#define box_char_top_left_corner L"┌"
#define box_char_top_right_corner L"┐"
#define box_char_bottom_left_corner L"└"
#define box_char_bottom_right_corner L"┘"
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

#include "main.c"
#endif