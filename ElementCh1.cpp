#include <iostream>
#include <string>
using namespace std;


template <typename T> class ElementCh1{//classe définissant un singleton
    
    //paramètres
    private:
    
    T donnee;
    ElementCh1* suivant;


    public:
    
    //constructeurs
    ElementCh1(){ //constructeur par défaut
        this->donnee = nullptr;
        this->suivant = nullptr;
    };
    
    ElementCh1(T newdonnee, ElementCh1* newsuivant){ //constructeur à 2 paramètres
        donnee = newdonnee;
        suivant = newsuivant;
    };

    //getters
    T getVal(){
        return donnee;
    };

    ElementCh1* getSuivant(){
        return suivant;
    };

    //setters
    void setVal(T newVal){
        donnee = newVal;
    };

    void setSuivant(ElementCh1* newSuiv){
        suivant = newSuiv;
    };

    void afficher(){//inutilisée -sert de vérification-
        std::string s = std::to_string(donnee);
        cout << "[v = " + s + "]" << endl;
    };

};