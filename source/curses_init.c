#include "../include/GV.h"

//ncursesの初期化
void init_ncurses(void){
  	// マルチバイト文字を使う
  	setlocale(LC_ALL,"");

  	//ncurses環境の初期化
  	if(initscr() == NULL){
    	fprintf(stderr, "initscr failure\n");
    	exit(EXIT_FAILURE);
  	}

  	// 入力を受け付けられるように
  	keypad(stdscr,TRUE); 
  
  	// 入力された文字を返さない
  	noecho();

	//カーソルを消す 2以上で再び表示できる。
  	curs_set(0);  
}

//ncursesを終わらせる時の処理
void end_ncurses()
{
  /* cursesを使用した後は必ず最後にこれをやる */
  if(endwin() == ERR){

    fprintf(stderr, "endwin failure");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}

//ncursesで色を使う初期化
void init_mycolor()
{
	/* start_colorは色属性を使用するときは最初に必ず実行する.
	 *      initscrの直後に実行するのがよい習慣らしい. */
	if(has_colors() == FALSE || start_color() == ERR){
		endwin();
		fprintf(stderr, "has_colors or start_color failure\n");
		exit(EXIT_FAILURE);
	}
	/* 色のペアを作る */
	// 黒
	init_pair(PRINT_BLACK, COLOR_BLACK, COLOR_WHITE);
	// 赤
	init_pair(PRINT_RED, COLOR_RED, COLOR_WHITE);
	// 黄色
	init_pair(PRINT_MAGENTA, COLOR_MAGENTA, COLOR_WHITE);
	// 緑
	init_pair(PRINT_GREEN, COLOR_GREEN, COLOR_WHITE);
	// 青
	init_pair(PRINT_BLUE, COLOR_BLUE, COLOR_WHITE);
	// 背景赤、文字黒
	init_pair(BACK_RED, COLOR_WHITE, COLOR_RED);

	// デフォルト色設定
	bkgd(COLOR_PAIR(PRINT_BLACK));
}
