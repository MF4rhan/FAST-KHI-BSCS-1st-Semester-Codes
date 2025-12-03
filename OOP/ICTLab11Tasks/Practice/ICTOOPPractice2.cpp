#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
	string name;
	int health;
	int baseDamage;
	virtual void Characterinfo(string a, int b, int c)
	{
		name = a;
		health = b;
		baseDamage = c;
	}
	virtual void attack()
	{
		cout << name << "attacked with bare hands: " << baseDamage<<endl;
	}
	void heal()
	{
		cout << "10 HP Restored!" <<endl;
	}
	void heal(int potionStrength)
	{
		cout << "Potion Dranked! "<< potionStrength << "HP restored!" << endl;
	}
};

class Warrior : public Character
{
public:
	void attack()
	{
		cout << name << " attacked with a greatsword! Damage: " << baseDamage+20<< endl;
	}
};

class Mage : public Character
{
public:
	int mana;
	void Characterinfo(string a, int b, int c, int d)
	{
		name = a;
		health = b;
		baseDamage = c;
		mana = d;
	}
	void attack()
	{
		cout << name << " casts Fireball! Damage: " << baseDamage*2 << endl;	
	}
};

int main()
{
	Character* chara;
	Character* chara2;
	Mage mago;
	Warrior warro;
	warro.Characterinfo("Bastion", 120, 40);
	mago.Characterinfo("Gandalf", 100, 50, 200);
	chara = &mago;
	chara2 = &warro;
	chara->attack();
	chara->heal(50);

	chara2->attack();
	return 0;
}