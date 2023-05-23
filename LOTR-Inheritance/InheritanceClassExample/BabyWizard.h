#include "Wizard.h"

class BabyWizard : public Wizard{
    public:
    BabyWizard(std::string n, int d){
        setName(n);
        setDamage(d);
    };
    void performSpell(){
        std::cout << "You're almost cursed!" << std::endl;
    }
};