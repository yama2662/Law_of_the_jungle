#include "GV.h"


int main(void)
{
	char loop = TRUE;
	char game_loop = FALSE;
	char turn_loop = FALSE;

	int cmd = 0; // メニューなどの入力
  int flow;  // ターンの進行管理
  char way;
  int dice_num;


	player_t player[PLAYER_NUM];
	board_t board[BOARD_MAX];
	event_t event[EVENT_MAX];

  player_t *now_player;


 	/*ncursesの初期化*/
  init_ncurses();
  init_mycolor();


  while(loop){
	  // タイトル画面を表示
    loop = title_menu(&cmd);
  }

  switch(cmd){
	  case 1:
  	  // 初期化処理
  	  init_player(player);
  	  init_board(board);
  	  init_event(event);
  	  init_dice();
  	  
  	  set_event(board, event);
  	  init_game(player, board);
  	  
  	  game_loop = TRUE;
  	  now_player = &player[3];
	    break;
	  
    default:
	    break;
  }

  	while(game_loop){

      now_player = set_player(now_player);  // 次のプレイヤーに手番をセット
      flow = 0;
      turn_loop = TRUE;

      while(turn_loop){

        clear();      // 画面クリア
        print_game(player, board, now_player); // ゲーム情報を表示

        // ターンの流れ
        // どちらに進むか決定 →ダイスを振る →コマを１マスずつ進める
        // →(途中に相手プレイヤーがいた場合は戦闘)
        // →止まったマスの指示に従う →次のプレイヤーへ
        switch(flow){
          case 0: // まずどちらに進むかを選択
            way = choice_way();
            break;

          case 1: // ダイスを振る
            dice_num = roll_dice();
            break;

          case 2: // ダイスの目だけコマを進める
            move_player(way, dice_num, now_player, player, board);
            turn_loop = FALSE;
            break;

          default:
            turn_loop = FALSE;
            break;
        }

        flow++;
      }

      /*
      timeout(-1);
      cmd = getch();
		  if(cmd == 'e'){
			 game_loop = FALSE;
		  }
      */

      game_loop = check_end(now_player);

    }
    disp_result(now_player);
    usleep(SLEEP_TIME*10);

  	end_ncurses();

}
