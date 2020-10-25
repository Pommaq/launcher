#include <iostream>
#include "../includes/backend.h"
#include <thread>
#include <ncurses.h>

#define TOP_ROW 1
#define NAME_TEXT 2
#define BACKGROUND 3

#define PROG_NAME "ProgLauncher Ver.0.1 Alpha"
#define PROG_NAME_SIZE sizeof(PROG_NAME)



void printBackgrd(int row, int col){
    // Prepares a background for us

    attron(COLOR_PAIR(TOP_ROW));
    // Printing top two rows
    int toiter = col*2;

    for (unsigned int i = 0; i < toiter/4 - PROG_NAME_SIZE/2; i++){
        printw(" ");
    }
    attroff(COLOR_PAIR(TOP_ROW));
    attron(COLOR_PAIR(NAME_TEXT));

    addstr(PROG_NAME);

    attroff(COLOR_PAIR(NAME_TEXT));
    attron(COLOR_PAIR(TOP_ROW));

    toiter = toiter - toiter/4 - PROG_NAME_SIZE/2;

    for (; toiter > 0; toiter--){
        printw(" ");
    }

    int x,y;
    getyx(stdscr,y,x); // We could figure this out using simple math, but this is more readable and flexible
    attron(COLOR_PAIR(BACKGROUND));
    for (unsigned int i = 0; i < ((row - 2) * col); i++){
        printw(" "); // Makes everything else black.
    }
    attroff(COLOR_PAIR(BACKGROUND));
    move(y,x);

}

int main() {

    initscr(); // initializes ncurses terminal. Default window is stdscr
    noecho(); // removes echo when user types stuff
    if (!has_colors()){
        endwin();
        reporterr("Terminal doesnt support color.");
    }
    else{
        start_color();
        init_pair(TOP_ROW, COLOR_RED, COLOR_RED);
        init_pair(NAME_TEXT, COLOR_BLACK, COLOR_RED);
        init_pair(BACKGROUND, COLOR_BLACK, COLOR_BLACK);
    }


    int row, col;
    //getyx(WINDOW* win, int y, int x) // Gets current position of cursor in specified window
    getmaxyx(stdscr,row,col);
    printBackgrd(row,col);

    // mvprintw(y,x,string); // Move cursor to y,x and print string
    // wprintw(win,string) print on window at present cursor position in the window
    // mwprintw(win,y,x,string) // Move to (y,x) relative to window coordinates and then print
    refresh();
    getch();
    attroff(COLOR_PAIR(TOP_ROW));

    printw(" This is more text");
    getch();
    endwin();
    return 0;
}
