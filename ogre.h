#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

#ifndef OGRE_H
#define OGRE_H

class Ogre: public Hero{
	public:
		Ogre();

		//virtual bool attack(Hero& hero, int type) override;
		
		virtual bool attack_upper(Hero&) override;
		virtual bool attack_middle(Hero&) override;
		virtual bool attack_lower(Hero&) override;
};

#endif
