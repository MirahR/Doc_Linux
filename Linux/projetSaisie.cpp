#include<iostream>
#include<string>
#include <vector>
#include <iomanip> 




std::string ajoutNomClasse(){

    std::string nomClasse;
    std::cout <<"Merci de saisir le nom de votre Classe\n";
    std::cin>> nomClasse;



    return nomClasse;
} 

void affichageAttribut(std::vector<std::string> attributs, std::string nomClasse){

    std::cout<<"NOM DE LA CLASSE : "<<nomClasse<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Listes des attributs"<<std::endl;
    for (std::string attribut : attributs){

        std::cout<<attribut<<std::endl;
    }

    


}
   

    

int main(){

    std::string nomClasse;
    std::string attribut;
    std::vector<std::string> attributs;


    std::cout <<"Merci de saisir le nom de votre Classe\n";
    std::cin>> nomClasse;

    bool ajouter=true;

    while( ajouter){
        int choix;
        std:: cout <<"1. Ajouter un attribut de classe\n";
        std:: cout <<"2. afficher la liste des attributs de la classe\n";
        std:: cout <<"3. Terminer\n";
        std::cin>> choix;
            
      switch (choix)
      {
      case 1:
        std::cout << "Nom de l'attribut: \n";
        std::cin.ignore(); 
        std::cin>> attribut;
        attributs.push_back(attribut);
            
        break;

      case 3:
        ajouter= false;
        break;
      
      case 2:
        affichageAttribut(attributs,nomClasse);
        break;

      default:
        std::cout<<" Erreur de saisie!!\n";
        break;
      }
  
    }
}










