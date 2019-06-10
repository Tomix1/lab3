#include "knight.h"

Knight::Knight():
	Hero("Knight", 150),
	armor_(50),
	max_armor_(90),
	delta_armor_(0){};
/*
bool Knight::attack(Hero& hero, int type){
	if(get_readiness() > 0){
		delta_readiness_--;
		if(type == 1){
			delta_armor_=min(armor_+10, max_armor_);
			return true;
		}
		else if(type == 0){
			delta_armor_-=10;
			return hero.damage(armor_, 0, 0);
		}
		else if(type == -1){
			delta_hp_-=50;
			delta_armor_=max_armor_-armor_;
			return true;
		}
		else
			return true;				
	}
	else
		return false;
}*/

bool Knight::attack_upper(Hero& hero){
	delta_armor_=min(armor_+10, max_armor_);
	return true;
}

bool Knight::attack_middle(Hero& hero){
	delta_armor_-=10;
	return hero.damage(armor_, 0, type::middle);
}

bool Knight::attack_lower(Hero& hero){
	delta_hp_-=50;
	delta_armor_=max_armor_-armor_;
	return true;
}

void Knight::relax(){
	Hero::relax();
	armor_=max(0, min(armor_+delta_armor_, max_armor_));
	delta_armor_=0;
}

bool Knight::damage(int hp, int readiness_damage, type type_attack){
	return Hero::damage(max(hp*(100-armor_)/100, 1), readiness_damage, type_attack);
}
