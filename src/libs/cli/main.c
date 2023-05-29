
Menu MainMenu() {
    wchar_t *menulist[] = {
        L"🚀Run Simulation",
        L"Exit"
    };

    int Count = sizeof(menulist)/(sizeof(wchar_t*));
    wchar_t *blinker_theme = L"◆◈◇◈";
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
Menu drawMenu(Menu *menu, unsigned short int x, unsigned short int y, unsigned short int width) {

    int Count = sizeof(menu->options)/(sizeof(wchar_t));
    int height=Count+2;
    //Draw the box frames
    for(char i=0;i<2;i++) {
        for(unsigned short int _x=1;_x<width;_x++) {
            wprintf(L"\x1b[%d;%dH%ls", y+(i*height-i), x+_x, box_char_top_bottom);
        }

        for(unsigned short int _y=1;_y<height-1;_y++) {
            wprintf(L"\x1b[%d;%dH%ls", y+_y, x+(i*width), box_char_left_right);
        }
    }

    //Draw the box corners
    wprintf(L"\x1b[%d;%dH%ls", y, x, box_char_top_left_corner);
    wprintf(L"\x1b[%d;%dH%ls", y, x+width, box_char_top_right_corner);
    wprintf(L"\x1b[%d;%dH%ls", y+height-1, x, box_char_bottom_left_corner);
    wprintf(L"\x1b[%d;%dH%ls", y+height-1, x+width, box_char_bottom_right_corner);

    //Draw the menu items
    for(int i=0;i<Count;i++) {
        if(menu->cursor.y==i) {
            wprintf(L"\x1b[%d;%dH  \x1b[48;2;150;189;255m%ls\x1b[49m\n", 1+y+i, 1+x, menu->options[i]);
        } else {
            wprintf(L"\x1b[%d;%dH  %ls\n", 1+y+i, 1+x, menu->options[i]);
        }
    }

    //Draw the blinking cursor
    wprintf(L"\x1b[%d;%dH%lc\n", 1+y+menu->cursor.y, 1+x+menu->cursor.x, menu->cursor.blinker[menu->cursor.blinker_index]);
    menu->cursor.blinker_update_delay++;
    if(menu->cursor.blinker_update_delay>=menu->cursor.blinker_update_modulo) {
        menu->cursor.blinker_index++;
        menu->cursor.blinker_update_delay=0;
        if(menu->cursor.blinker_index >= menu->cursor.max_blinker_frames) {
            menu->cursor.blinker_index=0;
        }
    }

    //if down
    if(KeyTap(66)) {
        if(menu->cursor.y<Count-1)
        menu->cursor.y++;
    }

    //if up
    if(KeyTap(65)) {
        if(menu->cursor.y>0)
        menu->cursor.y--;
    }

    //select key (enter)
    if(KeyTap(10)) {
        // menu->action_ready=menu->cursor.y;
        menu->action(menu->cursor.y);
    }
}