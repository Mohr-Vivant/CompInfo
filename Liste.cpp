#include "SuiteCh1.cpp"

template <typename T> class Liste{
    
    //paramètres
    private:

    SuiteCh1<T>* valeur;
    Liste* suivant;

    public:

    //constructeurs
    Liste(){
        valeur = nullptr;
        suivant = nullptr;
    };

    Liste(SuiteCh1<T>* newValeur, Liste* newSuivant){
        valeur = newValeur;
        suivant = newSuivant;
    };

    //getters
    SuiteCh1<T>* getVal(){
        return valeur;
    };

    Liste* getSuivant(){
        return suivant;
    };

    //fonctions de manipulation des Chaines
    //fonction d'ajout
    Liste* ajoutListe(SuiteCh1<T>* val){
        Liste* base = new Liste(valeur, suivant);
        Liste* L = new Liste(val, base);
        return L;
    };

    //fonctions de retrait
    void effacerListe(){
        if (valeur == nullptr){
            cout << "La chaîne est déjà vide !" << endl;
        }else{
            SuiteCh1<T>* memoire = valeur;
            suivant = suivant->getSuivant();
            delete memoire;
        };
    };

    //fonction d'affichage
    void afficherComplet(){
        Liste* memoire = suivant;
        if (valeur == nullptr){
            cout << "La chaîne est vide !" << endl;
        }else{
            int i = 1;
            do{
                cout << "[elem n°" << i << " ; valeur = ";

                /*ElementCh1<T>* mem = valeur->getVal();
                cout << "{ ";
                do{
                    cout << mem->getVal() << " ";
                    mem = mem->getSuivant();
                }while(mem != nullptr);
                cout << "}";*/
                valeur->afficherComplet();
                
                cout << " ]" << endl;
                memoire = memoire->getSuivant();
                i++;
            }while(memoire != nullptr);
        };
    };
};