#include "vampire.h"

Vampire::Vampire():Hero("Vampire", 100){
}
/*
bool Vampire::attack(Hero& hero, int type){
	if(get_readiness() > 0){
		delta_readiness_--;
		if(type == 1){
			if(hero.damage(15, 0, 1)){
				delta_hp_+=15;
				return true;
			}
			return false;
		}
		else if(type == 0)
			return hero.damage(0.8*(100-get_hp()), 0, 0);
		else if(type == -1)
			return hero.damage(0.5*get_hp(), 0, -1);
		else
			return true;				
	}
	else
		return false;
}*/

bool Vampire::attack_upper(Hero& hero){
	if(hero.damage(15, 0, type::upper)){
		delta_hp_+=15;
		return true;
	}
	return false;
}

bool Vampire::attack_middle(Hero& hero){
	return hero.damage(0.8*(100-get_hp()), 0, type::middle);
}

bool Vampire::attack_lower(Hero& hero){
	return hero.damage(0.5*get_hp(), 0, type::lower);
}
