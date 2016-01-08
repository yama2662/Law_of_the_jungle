#ifndef CURSES_INIT_H
#define CURSES_INIT_H

// ncursesの設定

//ncursesの初期化
void init_ncurses(void);

//ncursesを終わらせる時の処理
void end_ncurses(void);

//ncursesで色を使う初期化
void init_mycolor(void);



#endif