#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include <ncurses.h>
#include <locale.h>

#include "data.h" // データ構造関連
#include "curses_init.h" // ncurses関連
#include "print.h" // 表示と入力受付関連
#include "control.h" // 操作関連
#include "battle.h" //戦闘関連
#include "change_data.h" //プレイヤー反映関連
#include "import_event.h" // イベントデータ読み込み関連
#include "result.h" //結果表示関連


#define TRUE 1
#define FALSE 0

#define INIT_POWER 3
#define INIT_HP 10
#define INIT_DEFENSE 0
#define INIT_RANK 0

#define MAX_POWER 6
#define MAX_HP 20
#define MAX_DEFENSE 3

#define DICE_MAX 6
#define DICE_MIN 1

#define BOARD_MAX 24
#define EVENT_MAX 10
