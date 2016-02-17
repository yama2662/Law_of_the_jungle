#include "GV.h"

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

  mvprintw(9+(*cmd), 19,"→");

  refresh();

  // 決定ボタンが押されたらタイトルを閉じる
  if(ch == 'z'){
    return FALSE;
  }

  return TRUE;
}

// ゲームに必要な情報を表示
void print_game(player_t *p, board_t *b, player_t *now_p)
{
  print_board(b, now_p); 			  // ボード表示
  print_parameter(p);  // 全プレイヤーのパラメータを表示
  print_now_mark(now_p); // 現在のプレイヤーに印をつける
}

// ボードの表示
void print_board(board_t *b, player_t *now_p)
{
  // 正方形のマップを表示する

  int i;

  for(i=0; i<BOARD_MAX; i++){

    if(0 <= i && i <= 6){
      print_place(BOARD_UP, BOARD_LEFT+(i*BOARD_WIDTH), *(b+i), now_p);
    }
    else if(7 <= i && i <= 12){
      print_place(BOARD_UP+((i - BOARD_LENGTH)*BOARD_HEIGHT), BOARD_LEFT+(BOARD_LENGTH*BOARD_WIDTH), *(b+i), now_p);
    }
    else if(13 <= i && i <= 18){
      print_place(BOARD_UP+(BOARD_LENGTH*BOARD_HEIGHT), BOARD_LEFT+(BOARD_LENGTH*BOARD_WIDTH)-((i-BOARD_LENGTH*2)*BOARD_WIDTH), *(b+i), now_p);
    }
    else{
      print_place(BOARD_UP+(BOARD_LENGTH*BOARD_HEIGHT) - (i-BOARD_LENGTH*3)*BOARD_HEIGHT, BOARD_LEFT, *(b+i), now_p);
    }

  }
  refresh();
}

// マスの表示
void print_place(int y, int x, board_t b, player_t *now_p)
{
  int i;

  // ランダムイベントマスは青
  if(b.randEvent == TRUE){
    attrset(COLOR_PAIR(PRINT_BLUE));
    mvprintw(y, x, "? ?");
    mvprintw(y+1, x, "? ?");
  }
  // 戦闘力増加マスは赤
  else if(b.event->powerVar >= 1){
    attrset(COLOR_PAIR(PRINT_RED));
    mvprintw(y, x, "◆ ◆");
    mvprintw(y+1, x, "◆ ◆");
  }
  // HP増加マスは黄
  else if(b.event->hpVar >= 1){
    attrset(COLOR_PAIR(PRINT_MAGENTA));
    mvprintw(y, x, "● ●");
    mvprintw(y+1, x, "● ●");
  }
  // 防御力増加マスは緑
  else if(b.event->defenseVar >= 1){
    attrset(COLOR_PAIR(PRINT_GREEN));
    mvprintw(y, x, "■ ■");
    mvprintw(y+1, x, "■ ■");
  }//何もないマス 要色変更
  else{
    attrset(COLOR_PAIR(PRINT_CYAN));
    mvprintw(y, x, "▲ ▲");
    mvprintw(y+1, x, "▲ ▲");
  }

  // プレイヤーがこのマスにいる場合,
  // マスにプレイヤーを表示する
  for(i=0; i<PLAYER_NUM; i++){
    if(b.player[i] == now_p){
      attrset(COLOR_PAIR(BACK_RED));
    }
    else{
      attrset(COLOR_PAIR(PRINT_BLACK));
    }

    if(b.player[i] != NULL){
      if(i==0) mvprintw(y, x, "1");
      if(i==1) mvprintw(y, x+2, "2");
      if(i==2) mvprintw(y+1, x+2, "3");
      if(i==3) mvprintw(y+1, x, "4");
    }
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

// 手番プレイヤーに印をつける
void print_now_mark(player_t *now_p)
{
  mvprintw(PARAMETER_UP, PARAMETER_LEFT-2+(now_p->playerNo)*PARAMETER_WIDTH, "★");
}

// ルート選択時のメッセージを表示する
void print_choice_way(player_t *now_p)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "どちらに進む？");
  mvprintw(CURSOR_UP, CURSOR_LEFT+2, "時計回り");
  mvprintw(CURSOR_UP+1, CURSOR_LEFT+2, "反時計回り");
}

// 選択時のカーソルを表示する
void print_choice_cursor(int no)
{
  int i;
  mvprintw(CURSOR_UP+0, CURSOR_LEFT, " ");
  mvprintw(CURSOR_UP+1, CURSOR_LEFT, " ");

  mvprintw(CURSOR_UP+no, CURSOR_LEFT, "→");
  refresh();
}

// ダイスロールのメッセージを表示
void print_roll_dice()
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "Zキーを押してダイスを振ろう！");
}

// ダイスロールの結果を表示
void print_roll_result(int dice_num)
{
  int i;

  for(i=0; i<3; i++){
    mvprintw(CURSOR_UP, CURSOR_LEFT+(i*2), "・");
    refresh();
    usleep(SLEEP_TIME);
  }

  mvprintw(CURSOR_UP, CURSOR_LEFT+(i*2), "%d", dice_num);
  refresh();
  usleep(SLEEP_TIME*3);
}

// 残り何マス進むかを表示
void print_rest_num(int num)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "残り %d マス", num);
  refresh();
}

// 攻撃選択時のメッセージを表示
void print_choice_attack(char name[], int left)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "%sがいます！攻撃しますか？ 残り %d マス", name, left);
  mvprintw(CURSOR_UP, CURSOR_LEFT+2, "はい");
  mvprintw(CURSOR_UP+1, CURSOR_LEFT+2, "いいえ");
}

// ターン終了メッセージを表示
void print_end_turn()
{
  mvprintw(CURSOR_UP, CURSOR_LEFT, "Zキーを押してターン終了！");
  refresh();
}

/* 攻撃時のメッセージ */
void print_battle_message(char a_name[], char d_name[], int a_offence)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃力%dで%sは%sに攻撃を仕掛けた!!", a_offence, a_name, d_name);
  refresh();
  usleep(SLEEP_TIME*5);
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                         ");
  refresh();
}

/* 攻撃成功時 */
void print_battle_success(char d_name[], int before_hp, int after_hp)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                   ");
  mvprintw(CURSOR_UP, CURSOR_LEFT, "                                               ");
  refresh();

  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃は成功した!! ");
  mvprintw(MESSAGE_UP+1, MESSAGE_LEFT, "%s のHP: %2d -> %2d ", d_name, before_hp, after_hp);
  refresh();
  usleep(SLEEP_TIME*5);

}

/* 攻撃失敗時 */
void print_battle_failure()
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                   ");
  mvprintw(CURSOR_UP, CURSOR_LEFT, "                                               ");
  refresh();
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃は失敗した...");
  refresh();
  usleep(SLEEP_TIME*5);
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                   ");
  refresh();

}

/* 反撃時 */
void print_counter_message(char a_name[], char d_name[], int d_counter)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃力 %d で %s は %s に反撃を仕掛けた!!", d_counter, d_name, a_name);
  refresh();
  usleep(SLEEP_TIME*5);
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                         ");
  refresh();

}

/* 反撃成功時 */
void print_counter_success(char a_name[], int before_pow)
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                   ");
  mvprintw(CURSOR_UP, CURSOR_LEFT, "                                               ");
  refresh();

  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "反撃は成功した!");
  if(before_pow-1 <= 0){
    mvprintw(MESSAGE_UP+1, MESSAGE_LEFT, "%s は踏ん張った!", a_name);
  }else{
    mvprintw(MESSAGE_UP+1, MESSAGE_LEFT, "%s のPOW: %2d -> %2d", a_name, before_pow, before_pow-1);
  }
  refresh();
  usleep(SLEEP_TIME*5);
}

/* 反撃失敗時 */
void print_counter_failure()
{
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "                                                   ");
  mvprintw(CURSOR_UP, CURSOR_LEFT, "                                               ");
  refresh();
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "反撃は失敗した");
  refresh();
  usleep(SLEEP_TIME*5);
}
