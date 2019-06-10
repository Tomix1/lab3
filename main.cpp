#include "hero.h"
#include "fairy.h"
#include "ogre.h"
#include "vampire.h"
#include "knight.h"
#include <memory>

using namespace std;

unique_ptr<Hero> hero1, hero2;

unique_ptr<Hero> choice_hero(){
	string name;
	while(1){
		cout << "Enter the name of the hero:" << endl;
		cin >> name;
		if(name=="Fairy")
			return unique_ptr<Fairy>();
		else if(name=="Ogre")
			return unique_ptr<Ogre>();
		else if(name=="Vampire")
			return unique_ptr<Vampire>();
		else if(name=="Knight")
			return unique_ptr<Knight>();		
	}
}

bool play(){
	type attack1, attack2, evasion1, evasion2;
	int at1, at2, ev1, ev2;
	
	if(hero1->get_readiness() > 0){
		cout << "Enter attack and evasion type for hero1" << endl;
		cin >> at1 >> ev1;
		attack1=static_cast<type>(at1);
		evasion1=static_cast<type>(ev1);
	}
	hero1->set_evasion(evasion1);
	if(hero2->get_readiness() > 0){
		cout << "Enter attack and evasion type for hero2" << endl;
		cin >> at2 >> ev2;
		attack2=static_cast<type>(at2);
		evasion2=static_cast<type>(ev2);
	}
	hero2->set_evasion(evasion2);
	
	hero1->attack(*hero2, attack1);
	hero2->attack(*hero1, attack2);
	
	hero1->relax();
	hero2->relax();
	
	if(!hero1->alive() && !hero2->alive()){
        cout << "draw" << endl;
        return false;
    }
    else if(hero1->alive() && !hero2->alive()){
        cout << "hero1 won" << endl;
        return false;
    }
    else if(!hero1->alive() && hero2->alive()){
        cout << "hero2 won" << endl;
        return false;
    }
    return true;
}

int main(int argc, char** argv){
	hero1=choice_hero();
	hero2=choice_hero();
	while(play()) cout << endl;
	return 0;
}
