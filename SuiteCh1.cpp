#include "ElementCh1.cpp"

template <typename T> class SuiteCh1{//classe définissant les Suites -sert de base pour les classes suivantes-

    //paramètre
    private:

    ElementCh1<T>* pPremier;

    public:

    //constructeurs
    SuiteCh1(){//constructeur par défaut
        pPremier = nullptr;
    };

    //getters
    ElementCh1<T>* getVal(){
        return pPremier;
    };

    //fonctions de manipulation des Chaines
    //fonctions d'ajout
    void ajoutEnTete(T val){
        ElementCh1<T>* e = new ElementCh1<T>(val, pPremier);
        pPremier = e;
    };

    /* Information à noter :
    Même s'il est réalisé à l'interieur d'une fonction, le code
        pPremier = pPremier->getSuivant();
    modifie la valeur de pPremier pour le reste du main. Ce qui signifie que
    parcourir la chaine avec cette fonction modifie la chaine de départ, en
    perdant l'élément en tête à chaque appel. C'est pourquoi on utilise
        ElementCh1<T>* memoire = pPremier;
    On peut ainsi utiliser memoire comme un substitut pour parcourir la chaine
    sans la modifier. */
    void ajoutEnQueue(T val){
        ElementCh1<T>* e = new ElementCh1<T>(val, nullptr);
        ElementCh1<T>* memoire = pPremier;
        if (memoire == nullptr){
            pPremier = e;
        }else{
            do{
                memoire = memoire->getSuivant();
            }while(memoire->getSuivant() != nullptr);
            memoire->setSuivant(e);
        };
    };

    //fonctions de retrait
    void effacerEnTete(){
        if (pPremier == nullptr){
            cout << "La chaîne est déjà vide !" << endl;
        }else{
            ElementCh1<T>* memoire = pPremier;
            pPremier = pPremier->getSuivant();
            delete memoire;
        };
    };

    /* A changer plus tard :
    Pour une raison inconnue, la fonction delete laisse un résidut qui
    apparaît dans la fonction afficherComplet, il faudra trouver un moyen
    de corriger ça. */
    void effacerEnQueue(){// Attention /!\ à changer !
        ElementCh1<T>* memoire = pPremier;
        if (pPremier == nullptr){
            cout << "La chaîne est déjà vide !" << endl;
        }else if (memoire->getSuivant() == nullptr){
            delete pPremier;
            pPremier = nullptr;
        }else{
            do{
                pPremier = pPremier->getSuivant();
            }while(pPremier->getSuivant() != nullptr);
            delete pPremier;
            pPremier = nullptr;
            pPremier = memoire;
        };
    }
    
    //fonction d'affichage
    void afficherComplet(){
        ElementCh1<T>* memoire = pPremier;
        if (memoire == nullptr){
            cout << "La chaîne est vide !" << endl;
        }else{
            cout << "{ ";
            do{
                cout << memoire->getVal() << " ";
                memoire = memoire->getSuivant();
            }while(memoire != nullptr);
            cout << "}";
        };
    };
};