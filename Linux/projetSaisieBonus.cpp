#include<iostream>
#include<string>
#include <vector>
#include <iomanip> 


std::string selectTypeAttribut(){

  std::string typeAttribut;
  
  bool saisieOk= false;

  std::string type[6] ={"string","int","float","double","bool","char"};
  
    while (!saisieOk)
    {
      int choix;
      std::cout<<" Merci de choisir un type d'attribut\n";
      std::cout<<" 1. string\n";
      std::cout<<" 2.int\n";
      std::cout<<" 3.float\n";
      std::cout<<" 4.double\n";
      std::cout<<" 5.bool\n";
      std::cout<<" 6.char\n";
      std::cin>>choix;

      if (choix>=1 && choix<=6){

           typeAttribut=type[choix-1];
           saisieOk=true;
      }
      else {

        std::cout<<"Erreur de saisie";
      }
    }

  return typeAttribut;
}

std::string ajoutNomClasse(){

    std::string nomClasse;
    std::cout <<"Merci de saisir le nom de votre Classe\n";
    std::cin>> nomClasse;
    
    nomClasse[0]= toupper(nomClasse[0]);

    return nomClasse;
} 



std::vector<std::string> ajouterAttributParDefault(std::vector<std::string> attributs){
        std::string attribut;
        std::string typeDefault;
        
        std::cout << "Nom de l'attribut: \n";
        std::cin.ignore(); 
        std::cin>> attribut;
        
        attributs.push_back(attribut);

return attributs;


} 


std::vector<std::string> ajouterAttributPersonnaliser(std::vector<std::string> attributs){
        attributs.push_back(selectTypeAttribut());
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
        std:: cout <<"1. Ajouter un attribut de classe avec type par défaut\n";
         std:: cout <<"2. Ajouter un attribut de classe avec type personnaliser\n";
        std:: cout <<"3. afficher la liste des attributs de la classe\n";
        std:: cout <<"4. Terminer\n";
        std::cin>> choix;
            
      switch (choix)
      {
      case 1:
       attributs.push_back(selectTypeAttribut());
        attributs=ajouterAttributParDefault(attributs);
            
        break;
      case 2:
       
        attributs=ajouterAttributPersonnaliser(attributs);
            
        break;

      case 4:
        ajouter= false;
        break;
      
      case 3:
        affichageAttribut(attributs,nomClasse);
        break;

      default:
        std::cout<<" Erreur de saisie!!\n";
        break;
      }
  
    }
}



