#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight: public Hero{
	private:
		int armor_;
		int max_armor_;
	protected:
		int delta_armor_;	
	public:
		Knight();
		
		virtual bool attack_upper(Hero&) override;
		virtual bool attack_middle(Hero&) override;
		virtual bool attack_lower(Hero&) override;

		//virtual bool attack(Hero& hero, int type) override;
		virtual void relax() override;
		virtual bool damage(int hp, int readiness_damage, type type_attack) override;
};

#endif
