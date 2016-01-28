#ifndef BATTLE_H
#define BATTLE_H

/* 反撃係数 */
#define COUNTER_CONF 5

/* 戦闘処理 (攻撃する側,攻撃される側) */
void battle(player_t *attack, player_t *defense);

/* 反撃処理 (反撃される側, 反撃する側)*/
void counter(player_t *attack, player_t *defense);

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
