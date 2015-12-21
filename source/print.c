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
			print_place(BOARD_UP+((i - BOARD_LENGTH)*BOARD_HEIGHT), BOARD_LEFT+(BOARD_LENGTH*BOARD_WIDTH), *(b+i));
		}
		else if(13 <= i && i <= 18){
			print_place(BOARD_UP+(BOARD_LENGTH*BOARD_HEIGHT), BOARD_LEFT+(BOARD_LENGTH*BOARD_WIDTH)-((i-BOARD_LENGTH*2)*BOARD_WIDTH), *(b+1));
		}
		else{
			print_place(BOARD_UP+(BOARD_LENGTH*BOARD_HEIGHT) - (i-BOARD_LENGTH*3)*BOARD_HEIGHT, BOARD_LEFT, *(b+1));
		}

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
		attrset(COLOR_PAIR(PRINT_MAGENTA));	
		mvprintw(y, x, "●");
	}
	// 防御力増加マスは緑
	else if(b.event->defenseVar >= 1){
		attrset(COLOR_PAIR(PRINT_GREEN));	
		mvprintw(y, x, "■");
	}
	// ランダムイベントマスは青
	else if(b.randEvend == TRUE){
		attrset(COLOR_PAIR(PRINT_BLUE));	
		mvprintw(y, x, "？");
	}
}

// 各プレイヤーのパラメータを表示
void print_parameter(player_t *p)
{
	int i;
	player_t *put;

	put = p;

	attrset(COLOR_PAIR(PRINT_BLACK));

	for(i=0; i<PLAYER_NUM; i++){
		print_one_player(PARAMETER_UP, PARAMETER_LEFT+(i*PARAMETER_WIDTH), put);
		put = put->next;
	}
	
	refresh(); 
}

//　１プレイヤーの	パラメータを表示
void print_one_player(int y, int x, player_t *p)
{
	mvprintw(y, x, "%s", p->name);
	mvprintw(y+1, x, "POW:%1d", p->power);
	mvprintw(y+2, x, "HP :%2d", p->hp);
	mvprintw(y+3, x, "DEF:%1d", p->defense);
	mvprintw(y+4, x, "rank:%1d", p->rank);
}