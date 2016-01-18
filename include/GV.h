#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <ncurses.h>
#include <locale.h>

#include "data.h" // データ構造関連
#include "dice.h" // 六面ダイス関連
#include "curses_init.h" // ncurses関連
#include "print.h" // 表示と入力受付関連
#include "change_data.h" //プレイヤー反映関係
//#include "control.h" // 操作関連


#define TRUE 1
#define FALSE 0

#define INIT_POWER 3
#define INIT_HP 10
#define INIT_DEFENSE 0
#define INIT_RANK 0

#define MAX_POWER 6
#define MAX_HP 30
#define MAX_DEFENSE 3

#define DICE_MAX 6
#define DICE_MIN 1

#define BOARD_MAX 24

#define EVENT_MAX 10
