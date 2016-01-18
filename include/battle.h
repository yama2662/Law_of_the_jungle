#ifndef BATTLE_H
#define BATTLE_H

/* 反撃係数 */
#define COUNTER_CONF 5

/* 戦闘処理 (攻撃する側,攻撃される側) */
void battle(player_t *attack, player_t *defense);

/* 反撃処理 (反撃される側, 反撃する側)*/
void counter(player_t *attack, player_t *defense);

#endif
