#include "../include/GV.h"

int main(void)
{
	int loop = TRUE;
	int game_loop = FALSE;
	int cmd = 0; // メニューなどの入力

	player_t player[PLAYER_NUM];
	board_t board[BOARD_MAX];
	event_t event[EVENT_MAX];


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
  			initPlayer(player);
  			initBoard(board);
  			initEvent(event);

  			setEvent(board, event);
  			game_loop = TRUE;
  			break;

  		default:
  			break;
  	}

  	while(game_loop){

  		clear();
  		print_board(board);
  		
  		timeout(50);
		cmd = getch();

		if(cmd == 'z'){
			game_loop = FALSE;
		}
  	}



  	end_ncurses();  	
}