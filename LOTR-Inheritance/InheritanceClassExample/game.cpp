#include "Orc.h"
#include "Ogre.h"
#include "Wizard.h"
#include "BabyWizard.h"
#include <iostream>
using namespace std;
int main(){

    Orc orc1("Chakub",-6);
    cout << orc1.getName() << endl;
    

    Ogre ogre1("Pantoran", -12);
    ogre1.setDamage(-20);
    cout << ogre1.getName() << " and I make " << ogre1.getDamage() << " of damage." << endl;

    Wizard saruman("Saruman",-35);
    saruman.performSpell();

    BabyWizard babyw("Alatar", -35);
    babyw.performSpell();
    cout << babyw.setDamage(-5);

    return 0;
}