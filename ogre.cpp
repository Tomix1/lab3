#include "ogre.h"

Ogre::Ogre():Hero("Ogre", 200){
}
/*
bool Ogre::attack(Hero& hero, int type){
	if(get_readiness() > 0){
		delta_readiness_--;
		if(type == 1)
			return hero.damage(40, 0, 1);
		else if(type == 0)
			return hero.damage(40, 0, 0);
		else if(type == -1)
			return true;
		else
			return true;				
	}
	else
		return false;
}*/

bool Ogre::attack_upper(Hero& hero){
	return hero.damage(40, 0, type::upper);
}

bool Ogre::attack_middle(Hero& hero){
	return hero.damage(40, 0, type::middle);
}

bool Ogre::attack_lower(Hero& hero){
	return true;
}
