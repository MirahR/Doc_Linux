#include <fstream>
#include<iostream>
using namespace std;

/*

CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: myprogram

myprogram: MyClass.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o myprogram MyClass.cpp main.cpp

clean:
	rm -f myprogram
	rm -f MyClass.h
	rm -f MyClass.cpp
	rm -f main.cpp

*/






string texteMakefile(string nomDuProgram,  string nomClass){

    string monTexte;
     monTexte="CXX = g++\n";
    monTexte+="CXXFLAGS = -std=c++11 -Wall\n\n";
    monTexte+="all: "+nomDuProgram+"\n\n";
    monTexte+="nomDuProgram: "+nomClass+".cpp main.cpp\n";
	monTexte+="\t$(CXX) $(CXXFLAGS) -o "+nomDuProgram+ " "+nomClass+".cpp main.cpp\n\n";
    monTexte+="run:\n";
    monTexte+="\t\t.\\"+nomDuProgram+"\n";
    monTexte+="\n\nclean:\n";
    monTexte+="\t\trm -f "+nomDuProgram+".cpp\n";
    monTexte+="\t\trm -f "+nomClass+".h\n";
    monTexte+="\t\trm -f "+nomClass+".cpp\n";
    monTexte+="\t\trm -f main.cpp\n\n";
    monTexte+="\n\nclean-o:\n";
    monTexte+="\t\trm -f *.o\n";
   

    return monTexte;

}

void ecritureFichier(string &nomFichier, string &texte)
{
    std::ofstream outFile(nomFichier);
    if (outFile.is_open())
    {
        outFile << texte << std::endl;
        std::cout << "fichier enregistré avec succes" << std::endl;
    }
    else{
         
            cout<<"Probleme sur le fichier\n";
    }
    outFile.close();
}


void lectureFichier(string &nomFichier){
     
    ifstream fichierEntre(nomFichier);

        if (fichierEntre.is_open())
        {
             string ligne;
                 while (getline(fichierEntre, ligne)) {
                    cout << ligne << endl;
                }
            fichierEntre.close();
        } 
        else {
               cout << "Erreur à l'ouverture du fichier" << endl;

            }  
                 

}


int main(){

   
    string monTexte;
    string nomDuProgram="classMaker";
    string nomClass="MyClass";
    string nomFichier="Makefile";


  
    
    monTexte=texteMakefile(nomDuProgram, nomClass);    
    ecritureFichier(nomFichier,monTexte);
    lectureFichier(nomFichier);

       


    return 0;
}
