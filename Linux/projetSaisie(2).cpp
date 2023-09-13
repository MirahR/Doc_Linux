#include<iostream>
#include<string>
#include <vector>
#include <iomanip> 




std::string ajoutNomClasse(){

    std::string nomClasse;
    std::cout <<"Merci de saisir le nom de votre Classe\n";
    std::cin>> nomClasse;
    
    nomClasse[0]= toupper(nomClasse[0]);

    return nomClasse;
} 

std::vector<std::string> ajouterAttribut(std::vector<std::string> attributs){
        std::string attribut;
        std::cout << "Nom de l'attribut: \n";
        std::cin.ignore(); 
        std::cin>> attribut;
        
        attributs.push_back(attribut);

return attributs;


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
   
    std::vector<std::string> attributs;
    nomClasse = ajoutNomClasse();
    
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
        attributs=ajouterAttribut(attributs);
            
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



