#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire: public Hero{
	public:
		Vampire();

		//virtual bool attack(Hero& hero, int type) override;
		
		virtual bool attack_upper(Hero&) override;
		virtual bool attack_middle(Hero&) override;
		virtual bool attack_lower(Hero&) override;
};

#endif
