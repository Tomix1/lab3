#include "hero.h"

Hero::Hero(const string name, int hp){
	name_=name;
	hp_=hp;
	readiness_=1;
	delta_hp_=0;
	delta_readiness_=0;
	duration_poisoning_=0;
	type_evasion_=type::none;
}

bool Hero::alive() const{
	return hp_ > 0;
}

bool Hero::poisoned() const{
	return duration_poisoning_ > 0;
}

void Hero::set_evasion(type evasion){
	type_evasion_=evasion;
}

bool Hero::damage(int hp, int readiness_damage, type type_attack){
	if(type_evasion_ != type_attack){
		delta_hp_-=hp;
		delta_readiness_-=readiness_damage;
		return true;
	}
	return false;
}

bool Hero::attack(Hero& hero, type type_attack){
	if(get_readiness() == 0)
		return false;

	delta_readiness_--;
	
	switch(type_attack){
		case type::upper:
			return attack_upper(hero);
		case type::middle:
			return attack_middle(hero);
		case type::lower:
			return attack_lower(hero);	
	}
}

bool Hero::poison(int duration_poisoning){
	duration_poisoning_+=duration_poisoning;
}

void Hero::relax(){
	type_evasion_=type::none;
	readiness_=min(readiness_+delta_readiness_+1, 1);
	delta_readiness_=0;
	hp_=max(hp_+delta_hp_, 0);
	delta_hp_=0;
	duration_poisoning_=max(duration_poisoning_-1, 0);
}

int Hero::get_readiness() const{
	return readiness_;
}

int Hero::get_hp() const{
	return hp_;
}

