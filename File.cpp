#include "SuiteCh1.cpp"

template <typename T> class File : private SuiteCh1{

    public:

    void ajout() const{
        SuiteCh1::ajoutEnQueue(T val);
    };

    void retrait() const{
        SuiteCh1::effacerEnTete();
    };

    void afficher() const{
        SuiteCh1::afficherComplet();
    };
};