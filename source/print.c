#include "../include/GV.h"

// タイトル画面を表示
void print_title()
{

  	attrset(COLOR_PAIR(1));

  	mvprintw(8 , 20, "弱肉強食");

  	mvprintw(10,  21, "はじめる");
	mvprintw(11,  21, "やめる");

	refresh();
}

// タイトル画面のメニュー表示と入力
char title_menu(int *cmd)
{
  	int ch;
  	int last;
	  
	last = *cmd;

	// タイトルメニュー表示
	print_title();	


	// 一定時間入力がなかった場合入力待ちを飛ばす
	timeout(50);
	ch = getch();
	  
	if(ch == KEY_DOWN){
		(*cmd)++;
	}
	else if(ch == KEY_UP){
	    (*cmd)--;
	}

	if(*cmd > TITLE_MENU_MAX){
	    *cmd = TITLE_MENU_MAX;
	}
	else if(*cmd < TITLE_MENU_MIN){
	    *cmd = TITLE_MENU_MIN;  
	}

	if(last != *cmd)
	   	clear();

	mvprintw(9+(*cmd), 19,">");    

	refresh(); 
	 
	// 決定ボタンが押されたらタイトルを閉じる
	if(ch == 'z'){
		return FALSE;
	}
	  
	return TRUE;
}

// ボードの表示
void print_board(board_t *b)
{
	// 正方形のマップを表示する
	
	int i;

	for(i=0; i<BOARD_MAX; i++){

		if(0 <= i && i <= 6){
			print_place(BOARD_UP, BOARD_LEFT+(i*BOARD_WIDTH), *(b+i));
		}
		else if(7 <= i && i <= 12){

		}
		else if(13 <= i && i <= 18){

		}
		else{

		}

		//mvprintw(5+i, 10, "No:%d POW:%d, HP:%d, DEF:%d", (b+i)->boardNo, (b+i)->event->powerVar, (b+i)->event->hpVar, (b+i)->event->defenseVar);
	}
	refresh(); 
}

// マスの表示
void print_place(int y, int x, board_t b)
{
	// 戦闘力増加マスは赤
	if(b.event->powerVar >= 1){
		attrset(COLOR_PAIR(PRINT_RED));	
		mvprintw(y, x, "◆");
	}
	// HP増加マスは黄
	else if(b.event->hpVar >= 1){
		attrset(COLOR_PAIR(PRINT_YELLOW));	
		mvprintw(y, x, "◆");
	}
	// 防御力増加マスは緑
	else if(b.event->defenseVar >= 1){
		attrset(COLOR_PAIR(PRINT_GREEN));	
		mvprintw(y, x, "■");
	}
	// ランダムイベントマスは青
	else if(b.randEvend == TRUE){
		attrset(COLOR_PAIR(PRINT_BLUE));	
		mvprintw(y, x, "■");
	}
}
