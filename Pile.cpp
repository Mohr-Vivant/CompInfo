#include "SuiteCh1.cpp"

template <typename T> class Pile : private SuiteCh1{

    public:

    void ajout() const{
        SuiteCh1::ajoutEnTete(T val);
    };

    void retrait() const{
        SuiteCh1::effacerEnQueue();
    };

    void afficher() const{
        SuiteCh1::afficherComplet();
    };
};