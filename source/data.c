#include "GV.h"

// データ構造関連ファイル

// プレイヤー情報初期化
void init_player(player_t *p)
{
  int i, j;

  for(i=0; i<PLAYER_NUM; i++){
    strcpy((p+i)->name, "Player");
    (p+i)->name[6] = i + '1';
    (p+i)->name[7] = '\0';
    (p+i)->playerNo = i;
    (p+i)->power =   INIT_POWER;
    (p+i)->hp =      INIT_HP;
    (p+i)->defense = INIT_DEFENSE;
    (p+i)->rank =    INIT_RANK;

    //プレイヤの順番はリング構造 最後プレイヤの次は最初プレイヤ
    if(i < PLAYER_NUM-1)
    (p+i)->next = (p+i+1);
    else
    (p+i)->next = p;
  }
}

// ボード情報初期化
void init_board(board_t *b)
{
  int i,j;

  for(i=0; i<BOARD_MAX; i++){
    (b+i)->boardNo = i;
    //ランダムイベント判定
    (b+i)->event = FALSE;
    for(j=0; j<PLAYER_NUM; j++)
    (b+i)->player[j] = NULL;

    //マップは双方向リング構造 最後マスの次は最初マス
    if(i < BOARD_MAX-1)
    (b+i)->next = (b+i+1);
    else
    (b+i)->next = b;
    //逆向きも然り
    if(i == 0)
    (b+i)->prev = (b+BOARD_MAX-1);
    else
    (b+i)->prev = (b+i-1);

  }
}

// ボードの各マスにイベントを設定
void set_event(board_t *b, event_data *e, int mapdata[])
{
  int i;

  // イベントを設定
  //mapdataの番号を元にマップデータを指定．
  for(i=0; i<BOARD_MAX; i++){
    //mapdataが4以下(固定イベント)用,固定イベントデータを設定
    if(mapdata[i] < 4){
      (b+i)->event = &e->fixed_event[mapdata[i]];
      (b+i)->randEvent = FALSE;
    }
    //mapdataが4(ランダムイベント)，ランダムイベントを設定
    //ランダムイベントはrandom_listから毎度参照するので，ここではイベントのポインタを渡さない
    //その代わりにrandEventをTRUEに設定
    else if(mapdata[i] == 4){
      (b+i)->event = NULL;
      (b+i)->randEvent = TRUE;
    }
    //エラー用
    else{
      printf("mapdata is fail\n");
      exit(1);
    }
  }
}

// ゲームの初期化
// 各プレイヤーをボードの初期位置に配置する
void init_game(player_t *p, board_t *b)
{
  int i, j;

  for(i=0; i<PLAYER_NUM; i++){
    b->player[i] = p;
    p->place = b;

    p = p->next;
    for(j=0; j<BOARD_LENGTH; j++){
      b = b->next;
    }
  }
}

//マップ種類を外部ファイルから読み込む
//引数:マップデータ格納配列
//マップの内容をコンパイル無しで変更できる
void import_mapdata(int mapdata[]){
  char dmy[256];
  int i=0;
  const int n = 256;
  FILE *fp;

  //ファイルオープン
  if((fp=fopen("source/map.txt","r"))==NULL){
    printf("map.txt can not open");
    exit(1);
  }
  else{
    //1行分飛ばす(マップデータ編集用のコメントがファイル内に書いてあるので)
    fgets(dmy,n,fp);
    //データ読み込み 通常であれば0~4が読み込まれる
    for(i=0;i<BOARD_MAX;i++){
      fscanf(fp,"%d",&mapdata[i]);
    }
    fclose(fp);
  }
}
