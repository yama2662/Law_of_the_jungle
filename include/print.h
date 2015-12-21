#ifndef PRINT_H
#define PRINT_H

#define TITLE_MENU_MAX 2
#define TITLE_MENU_MIN 1

#define BOARD_UP 5
#define BOARD_LEFT 5
#define BOARD_LENGTH 6
#define BOARD_WIDTH 2

#define PRINT_BLACK 1
#define PRINT_RED 2
#define PRINT_GREEN 3
#define PRINT_YELLOW 4
#define PRINT_BLUE 5
#define BACK_WHITE 6


/* 表示と入力受付関連 */

// タイトル画面を表示
void print_title();

// タイトル画面のメニュー表示と入力
char title_menu(int *cmd);

// ボードの表示
void print_board(board_t *b);

// マスの表示
void print_place(int y, int x, board_t b);

#endif