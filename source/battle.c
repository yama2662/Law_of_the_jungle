#include "battle.h"
​
/* 戦闘処理 ()*/
void battle(player_t *attack, player_t *defense)
{
    int attack_offense;
    int pip;

    /* 自分の攻撃力計算 */
    attack_offense = attack->power - defense->defense;
​
    /* サイコロ */
    pip = diceRoll();
​
    if(pip <= attack_offense){
        /* 出た目の数だけ相手のhpを削る */
        defense->hp -= pip;
    }else{
        /* 襲撃失敗. 反撃 */
        counter(attack,defense);
    }
​
}
​
/* 反撃処理 */
void counter(player_t *attack, player_t *defense)
{
    int counterattack;
    int pip;
​
    /* 反撃する側の攻撃力の計算 */
    counterattack = defense->hp / COUNTER_CONF;
​
    /* サイコロ */
    pip = diceRoll();

    if(pip <= counterattack){
        /* 反撃される側のPOWを-1 */
        attack->power --;
        if(attack->power <= 0) attack->power = 1; //0にはならない
    }
}
