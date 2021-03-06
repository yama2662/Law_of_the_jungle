#include "GV.h"

/* 戦闘処理 ()*/
void battle(player_t *attack, player_t *defense)
{
  int attack_offense;
  int pip;
  int after_hp;

  /* 自分の攻撃力計算 */
  attack_offense = attack->power - defense->defense;

  /*メッセージ*/
  print_battle_message(attack->name, defense->name, attack_offense);

  /* サイコロ */
  pip = roll_dice();

  if(pip <= attack_offense){
    /* 出た目の数だけ相手のhpを削る */
    after_hp = defense->hp - pip;
    if(after_hp < 0) after_hp = 0;

    print_battle_success(defense->name, defense->hp, after_hp);

    defense->hp = after_hp;

    /* 相手のHPを0にした場合撃破メッセージを表示 */
    /* さらにゲームから除外する */
    if(defense->hp == 0){
      print_defeat(defense->name);

      defense->place->player[defense->playerNo] = NULL;
    }

  }else{
    /* 襲撃失敗. 反撃 */
    print_battle_failure();
    counter(attack,defense);
  }

}

/* 反撃処理 */
void counter(player_t *attack, player_t *defense)
{
  int counterattack;
  int pip;

  /* 反撃する側の攻撃力の計算 */
  counterattack = defense->hp / COUNTER_CONF + 1;

  print_counter_message(attack->name, defense->name, counterattack);

  /* サイコロ */
  pip = roll_dice();

  if(pip <= counterattack){
    /* 反撃される側のPOWを-1 */
    print_counter_success(attack->name,attack->power);
    (attack->power)--;
    if(attack->power <= 0) attack->power = 1; //0にはならない
  }else{
    print_counter_failure();
  }
}
