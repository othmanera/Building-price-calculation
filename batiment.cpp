#include <iostream>
#include <string>
using namespace std;

//classe batiment
class batiment{

protected:    
    string adresse;
    int superficie;
    float prixM;
public:
//constructeur
batiment(string adresse="",int superficie=0,float prix=0){
    this->adresse = adresse;
    this->superficie = superficie;
    this->prixM = prix;
}
//affichage
virtual void afficherBatiment(){

    cout <<"Adresse: " << adresse << endl;
    cout <<"Superficie: " << superficie << endl;
    cout <<"Prix: " << prixM << endl;
    
}
//prix batiment
virtual float calcPrixBatiment(){
    return superficie*prixM;

}

};//fin de la classe batiment


//classe maison
class maison : public batiment{
    
    int nbrPieces;
    bool existJardin;
    int superficieJardin;

public:

//constructeur
maison(string adresse="",int superficie=0,float prix=0 ,int nbrPieces=0, bool existJardin=0,int superficieJardin=0):
batiment(adresse,superficie,prix) {
    
    
    this->nbrPieces = nbrPieces;
    this->existJardin = existJardin;
    
    if (existJardin == 0)
        superficieJardin = 0;
    else
        this->superficieJardin = superficieJardin;

}

//affichage
void afficherBatiment(){

    
    cout <<"Nombre de pieces: " << nbrPieces << endl;
   if (existJardin == 0){

        cout <<"Jardin: Existant" << endl;
        cout <<"Superficie du Jardin: "<< superficieJardin << endl;
    }

    else
        cout <<"Jardin: Inexistant" << endl;

}

//Calculer le prix du batiment
virtual float calcPrixBatiment(){

    if (existJardin==0)
        return (prixM/2)*superficieJardin ;

    else
        return prixM*superficie;

}


};//fin de la classe maison



//fonction principale
main(){

    batiment M("rabat",600,120);
    M.afficherBatiment();
    maison  ma;
    batiment *B = &ma;
    
    B->afficherBatiment();
}
