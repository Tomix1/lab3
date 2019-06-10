#include <iostream>
#include <string>

using namespace std;

#ifndef HERO_H
#define HERO_H

enum class type{
	upper,
	middle,
	lower,
	none
};

class Hero{
	private:
		int hp_;
		int readiness_;
	protected:
		string name_;
		int delta_hp_;
		int delta_readiness_;
		int duration_poisoning_;
		type type_evasion_;	
	public:
		Hero(const string name, int hp);
		
		bool alive() const;
		bool poisoned() const;
		void set_evasion(type);
		int get_readiness() const;
		int get_hp() const;
		bool attack(Hero&, type);
		
		virtual bool attack_upper(Hero&)=0;
		virtual bool attack_middle(Hero&)=0;
		virtual bool attack_lower(Hero&)=0;
		
		//virtual bool attack(Hero&, int type) = 0;
		virtual bool damage(int hp, int readiness_damage, type);
		virtual bool poison(int duration_poisoning);
		virtual void relax();
};

#endif
