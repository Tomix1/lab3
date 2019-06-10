#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

#ifndef FAIRY_H
#define FAIRY_H

class Fairy: public Hero{
	public:
		Fairy();

		//virtual bool attack(Hero& hero, int type) override;
		
		virtual bool attack_upper(Hero&) override;
		virtual bool attack_middle(Hero&) override;
		virtual bool attack_lower(Hero&) override;
};

#endif
