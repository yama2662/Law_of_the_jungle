#ifndef PRINT_H
#define PRINT_H

#define TITLE_MENU_MAX 2
#define TITLE_MENU_MIN 1

#define BOARD_UP 10		// ボード表示位置の左上(y座標)
#define BOARD_LEFT 20	// ボード表示位置の左上(x座標)
#define BOARD_LENGTH 6	// ボードの１辺のマス数
#define BOARD_WIDTH 6	// マスの表示間隔(x座標)
#define BOARD_HEIGHT 3	// マスの表示間隔(y座標)

#define PARAMETER_UP 1  	// パラメータ表示の左上(y座標)
#define PARAMETER_LEFT 10 	// パラメータ表示の左上(x座標)
#define PARAMETER_WIDTH 15 	// パラメータ表示の間隔(x座標)

#define MESSAGE_UP 33	// メッセージ表示の左上(y座標)
#define MESSAGE_LEFT 10	// メッセージ表示の左上(x座標)

#define CURSOR_UP 35 	// カーソル表示の左上(y座標)
#define CURSOR_LEFT 15 	// カーソル表示の左上(x座標)

#define PRINT_BLACK 1 	//カラーペア番号
#define PRINT_RED 2
#define PRINT_GREEN 3
#define PRINT_MAGENTA 4
#define PRINT_BLUE 5
#define BACK_RED 6

#define SLEEP_TIME 300000

/* 表示と入力受付関連 */

// タイトル画面を表示
void print_title();

// タイトル画面のメニュー表示と入力
char title_menu(int *cmd);


// ゲームに必要な情報を表示
void print_game(player_t *p, board_t *b, player_t *now_p);

// ボードの表示
void print_board(board_t *b, player_t *now_p);

// マスの表示
void print_place(int y, int x, board_t b, player_t *now_p);

// 各プレイヤーのパラメータを表示
void print_parameter(player_t *p);

//　１プレイヤーの	パラメータを表示
void print_one_player(int y, int x, player_t *p);

// 手番プレイヤーに印をつける
void print_now_mark(player_t *now_p);

// ルート選択時のメッセージを表示する
void print_choice_way();

// 選択時のカーソルを表示する
void print_choice_cursor(int no);

// ダイスロールのメッセージを表示
void print_roll_dice();

// ダイスロールの結果を表示
void print_roll_result(int dice_num);

// 残り何マス進むかを表示
void print_rest_num(int num);

// 攻撃選択時のメッセージを表示
void print_choice_attack(char name[], int left);

// ターン終了メッセージを表示
void print_end_turn();

/* 攻撃時のメッセージ */
void print_battle_message(char a_name[], char d_name[], int a_offence);

/* 攻撃成功時 */
void print_battle_success(char d_name[], int before_hp, int after_hp);

/* 攻撃失敗時 */
void print_battle_failure();

/* 反撃時 */
void print_counter_message(char a_name[], char d_name[], int d_counter);

/* 反撃成功時 */
void print_counter_success(char a_name[], int before_pow);

/* 反撃失敗時 */
void print_counter_failure();

#endif
