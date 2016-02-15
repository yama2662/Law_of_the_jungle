#include "GV.h"

// 手番プレイヤーをセットする
player_t* set_player(player_t *now_p)
{
	player_t *p;

	// HPが0以下のプレイヤーは飛ばす
	do{
		p = now_p->next;
	}while(p->hp <= 0);

	return p;
}

// ダイスの乱数シード値設定
void init_dice()
{
	srand((unsigned)time(NULL));
}

// どちら回りにコマを進めるか選択する
// TRUE:時計回り FALSE:反時計回り
char choice_way()
{
	char way = TRUE;
	int cmd;

	print_choice_cursor(0);
	print_choice_way();

	do{
		timeout(-1);
		cmd = getch();

		if(cmd == KEY_UP){
			way = TRUE;
			print_choice_cursor(0);
		}
		else if(cmd == KEY_DOWN){
			way = FALSE;
			print_choice_cursor(1);
		}
	}while(cmd != 'z');

	return way;
}


// ダイスロール処理
int roll_dice()
{
	int dice_num;
	char cmd;

	print_roll_dice();

	do{
		timeout(-1);
		cmd = getch();
	}while(cmd != 'z');

  	dice_num = rand()%DICE_MAX+DICE_MIN;
  	print_roll_result(dice_num);

  	return dice_num;
}

// 手番プレイヤーをダイスの目だけ進める
// この関数の内部で戦闘処理、マスのイベント処理を行う
void move_player(char way, int dice_num, player_t *now_p, player_t *p, board_t *b)
{
	int i, j;
	int cmd;
	char btl=TRUE;

	for(i=dice_num-1; i>=0; i--){

		// コマを１つ先のマスに移動
		now_p->place->player[now_p->playerNo] = NULL;

		// 時計回り
		if(way == TRUE){
			now_p->place = now_p->place->next;
		}
		// 反時計回り
		else{
			now_p->place = now_p->place->prev;
		}
		now_p->place->player[now_p->playerNo] = now_p;

		clear();
		print_game(p, b, now_p);
		print_rest_num(i);
		usleep(SLEEP_TIME*3);

		// マスに他のプレイヤーがいるかチェック
		for(j=0; j<PLAYER_NUM; j++){

			if(j != now_p->playerNo){
				if(now_p->place->player[j] != NULL){
					print_choice_cursor(0);
					print_choice_attack(now_p->place->player[j]->name, i);

			      	do{
						timeout(-1);
						cmd = getch();

						if(cmd == KEY_UP){
							btl = TRUE;
							print_choice_cursor(0);
						}
						else if(cmd == KEY_DOWN){
							btl = FALSE;
							print_choice_cursor(1);
						}
					}while(cmd != 'z');

					clear();
					print_game(p, b, now_p);
					print_rest_num(i);

					if(btl){
						// ここに戦闘処理関数を書く
						mvprintw(MESSAGE_UP, MESSAGE_LEFT, "~~~戦闘開始~~~");
						refresh();
						usleep(SLEEP_TIME*5);
                        battle(now_p, now_p->place->player[j]);
					}

		    	}
		  	}

		}
	}

	// 止まったマスの処理を行う
	change_parameter(now_p);

	// ターン終了
	end_turn();
}

// 出番プレイヤーが止まったマスのイベント処理を行う
void change_parameter(player_t *now_p)
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "しかし何も起こらなかった。");
	refresh();
	usleep(SLEEP_TIME*3);
}

// ターン終了時の処理
void end_turn()
{
	int cmd;

	print_end_turn();
	do{
		timeout(-1);
		cmd = getch();
	}while(cmd != 'z');
}
