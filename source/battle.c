#include "battle.h"

/* 戦闘処理 ()*/
void battle(player_t *attack, player_t *defense)
{
    int attack_offense;
    int pip;

    /* 自分の攻撃力計算 */
    attack_offense = attack->power - defense->defense;
	
	/*メッセージ*/
	print_battle_message(attack->name, defense->name, attack_offense);

    /* サイコロ */
    pip = roll_dice();

    if(pip <= attack_offense){
        /* 出た目の数だけ相手のhpを削る */
		print_battle_success(defense->name, defense->hp, defense->hp-pip);
        defense->hp -= pip;
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
    counterattack = defense->hp / COUNTER_CONF;
	
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

/* 攻撃時のメッセージ */
void print_battle_message(char a_name[], char d_name[], int a_offence)
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃力 %d で %s は %s に攻撃を仕掛けた!!", a_offence, a_name, d_name);
	refresh();
	usleep(SLEEP_TIME*3);	
}

/* 攻撃成功時 */
void print_battle_success(char d_name[], int before_hp, int after_hp)
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃は成功した!! ");
	mvprintw(MESSAGE_UP+1, MESSAGE_LEFT, "%s のHP: %2d -> %2d ", d_name, before_hp, after_hp);
	refresh();
	usleep(SLEEP_TIME*3);	

}

/* 攻撃失敗時 */
void print_battle_failure()
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃は失敗した...");
	refresh();
	usleep(SLEEP_TIME*3);	

}

/* 反撃時 */
void print_counter_message(char a_name[], char d_name[], int d_counter)
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "攻撃力 %d で %s は %s に反撃を仕掛けた!!", d_counter, d_name, a_name);
	refresh();
	usleep(SLEEP_TIME*3);	

}

/* 反撃成功時 */
void print_counter_success(char a_name[], int before_pow)
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "反撃は成功した!");
	if(before_pow-1 <= 0){
		mvprintw(MESSAGE_UP+1, MESSAGE_LEFT, "%s は抗った!", a_name);
	}else{
		mvprintw(MESSAGE_UP+1, MESSAGE_LEFT, "%s のPOW: %2d -> %2d", a_name, before_pow, before_pow-1);
	}
	refresh();
	usleep(SLEEP_TIME*3);	
}

/* 反撃失敗時 */
void print_counter_failure()
{
	mvprintw(MESSAGE_UP, MESSAGE_LEFT, "反撃は失敗した");
	refresh();
	usleep(SLEEP_TIME*3);	

}
