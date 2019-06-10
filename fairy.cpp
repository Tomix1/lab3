#include "fairy.h"

Fairy::Fairy():Hero("Fairy", 30){
}
/*
bool Fairy::attack(Hero& hero, int type){
	if(get_readiness() > 0){
		delta_readiness_--;
		if(type == upper)
			return hero.damage(0, 1, 1);
		else if(type == middle)
			if(hero.poisoned())
				return hero.damage(20, 0, 0);
			else
				return hero.damage(2, 0, 0);
		else if(type == lower){
			if(hero.damage(0, 0, -1)){
				hero.poison(10);
				return true;
			}
			return false;
		}
		else
			return true;				
	}
	else
		return false;
}
*/
bool Fairy::attack_upper(Hero& hero){
	return hero.damage(0, 1, type::upper);
}

bool Fairy::attack_middle(Hero& hero){
	if(hero.poisoned())
		return hero.damage(20, 0, type::middle);
	else
		return hero.damage(2, 0, type::middle);
}

bool Fairy::attack_lower(Hero& hero){
	if(hero.damage(0, 0, type::lower)){
		hero.poison(10);
		return true;
	}
	return false;
}
