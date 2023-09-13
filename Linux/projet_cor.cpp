#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

//***************Partie  Saisie  Datas**************************************************//

std::string SelectTypeAttribut()
{

    std::string typeAttribut;

    bool saisieOk = false;

    std::string type[6] = {"string", "int", "float", "double", "bool", "char"};

    while (!saisieOk)
    {
        int choix;
        std::cout << " Merci de choisir un type d'attribut\n";
        std::cout << " 1. string\n";
        std::cout << " 2.int\n";
        std::cout << " 3.float\n";
        std::cout << " 4.double\n";
        std::cout << " 5.bool\n";
        std::cout << " 6.char\n";
        std::cin >> choix;

        if (choix >= 1 && choix <= 6)
        {

            typeAttribut = type[choix - 1];
            saisieOk = true;
        }
        else
        {

            std::cout << "Erreur de saisie";
        }
    }

    return typeAttribut;
}

std::string ajoutNomClasse()
{

    std::string nomClasse;
    std::cout << "Merci de saisir le nom de votre Classe\n";
    std::cin >> nomClasse;

    nomClasse[0] = toupper(nomClasse[0]);

    return nomClasse;
}

std::vector<std::string> ajouterAttribut(std::vector<std::string> attributs)
{
    std::string attribut;
    std::cout << "Nom de l'attribut: \n";
    std::cin.ignore();
    std::cin >> attribut;

    attributs.push_back(attribut);

    return attributs;
}

std::vector<std::string> ajouterAttributParDefault(std::vector<std::string> attributs)
{
    std::string attribut;
    std::string typeDefault;

    std::cout << "Nom de l'attribut: \n";
    std::cin.ignore();
    std::cin >> attribut;

    attributs.push_back(attribut);

    return attributs;
}

void affichageAttribut(std::vector<std::string> attributs, std::string nomClasse)
{

    std::cout << "NOM DE LA CLASSE : " << nomClasse << std::endl;
    std::cout << std::endl;
    std::cout << "Listes des attributs" << std::endl;

    for (std::string attribut : attributs)
    {

        std::cout << attribut << std::endl;
    }
}

/**********************************Create Class et Main CPP******************************************************/
void ecritureFichier(string &nomFichier, string &texte)
{
    std::ofstream outFile(nomFichier);
    if (outFile.is_open())
    {
        outFile << texte << std::endl;
        std::cout << "fichier enregistré avec succes" << std::endl;
    }
    else
    {

        std::cout << "Probleme sur le fichier\n";
    }
    outFile.close();
}

string generationInclusionHeader(string nomClasse, string &contenuFichier)
{
    contenuFichier = "#include \"" + nomClasse + ".h\"\n\n";
    return contenuFichier;
}
string generationInclusionConstructeurDefaut(string nomClasse,
                                             string &contenuFichier,
                                             vector<string> &attributs)
{
    contenuFichier += "\n " +
                      nomClasse + "::" +
                      nomClasse + "()\n{\n";

    for (auto e : attributs)
    {
        contenuFichier += "\t" + e + " = 0;\n";
    }
    contenuFichier += "}\n\n";
    return contenuFichier;
}

string generationInclusionConstructeurParametres(string nomClasse,
                                                 string &contenuFichier,
                                                 vector<string> &attributs)
{
    contenuFichier += "\n " +
                      nomClasse + "::" +
                      nomClasse + "(";
    for (auto e : attributs)
    {
        contenuFichier += "int " + e + " ,";
    }
    contenuFichier.erase(contenuFichier.end() - 1, contenuFichier.end());

    contenuFichier += ")\n{\n";
    for (auto e : attributs)
    {
        contenuFichier += "\tthis->" + e + " = " + e + ";\n";
    }
    contenuFichier += "}\n\n";
    return contenuFichier;
}

string generationGetters(string nomClasse,
                         string &contenuFichier,
                         vector<string> &attributs)
{
    for (auto e : attributs)
    {
        string s;
        transform(e.begin(), e.begin() + 1, back_inserter(s), ::toupper);
        s += e.substr(1, e.size() - 1);
        contenuFichier += "\n int  " +
                          nomClasse + "::" +
                          " get" + s + "() const \n{\n\treturn  " + e + ";\n}\n\n";
    }

    return contenuFichier;
}

string generationSetters(string nomClasse,
                         string &contenuFichier,
                         vector<string> &attributs)
{
    for (auto e : attributs)
    {
        string s;
        transform(e.begin(), e.begin() + 1, back_inserter(s), ::toupper);
        s += e.substr(1, e.size() - 1);
        contenuFichier += "\n void  " +
                          nomClasse + "::" +
                          " set" + s + "(int " + e + ")\n{\n"
                                                     "\tthis->" +
                          e + " = " + e + ";\n}\n\n";
    }
    return contenuFichier;
}

string generationNomFichierCpp(string nomClasse)
{
    return nomClasse + ".cpp";
}
void generationFichierCpp(string nomClasse, vector<string> &attributs)
{
    string nomFichier;
    string contenuFichier;
    nomFichier = generationNomFichierCpp(nomClasse);
    contenuFichier = generationInclusionHeader(nomClasse, contenuFichier);
    generationInclusionConstructeurDefaut(nomClasse, contenuFichier, attributs);
    generationInclusionConstructeurParametres(nomClasse, contenuFichier, attributs);
    generationGetters(nomClasse, contenuFichier, attributs);
    generationSetters(nomClasse, contenuFichier, attributs);

    ecritureFichier(nomFichier, contenuFichier);
}
string generationInclusionHeaderMain(string nomClasse, string &contenuFichier)
{
    contenuFichier = "#include <iostream>";
    contenuFichier += "\n#include <cmath>";
    contenuFichier += "\n#include <fstream>";
    contenuFichier += "\n#include <vector>";
    contenuFichier += "\n#include <cctype>";
    contenuFichier += "\n#include<algorithm>";
    contenuFichier += "\n#include\"" + nomClasse + ".h\"";
    contenuFichier += "\nusing namespace std;";
    return contenuFichier;
}
string generationFonctionMain(string nomClasse, string &contenuFichier, vector<string> &attributs)
{
    string nomClasseMinuscule;
    contenuFichier += "\nint main( void )\n{";
    /////////////////////declaration variables
    string s;
    transform(nomClasse.begin(), nomClasse.end(), back_inserter(nomClasseMinuscule), ::tolower);
    //    for (size_t i = 0; i < attributs.size(); i++)
    //    {
    //        contenuFichier += "\n\tint\t variable" + to_string(i) + " = " + to_string((i + 1)) + ";";
    //    }
    //    ////////////////////instanciation objet
    contenuFichier += "\n\t" + nomClasse + " " + nomClasseMinuscule + " =";
    contenuFichier += "" + nomClasse + "( ";
    for (size_t i = 0; i < attributs.size(); i++)
    {

        contenuFichier += to_string((i + 1)) + " ,";
    }
    contenuFichier.erase(contenuFichier.end() - 1, contenuFichier.end());
    contenuFichier += ") ;\n";
    //////////////////// setters
    for (auto e : attributs)
    {
        string s;
        transform(e.begin(), e.begin() + 1, back_inserter(s), ::toupper);
        s += e.substr(1, e.size() - 1);
        contenuFichier += "\t" + nomClasseMinuscule + "." +
                          " set" + s + "(" + to_string((1 + rand() % 5)) + ") ;\n";
    }
    /////////////////////////////getters
    for (auto e : attributs)
    {
        string s;
        transform(e.begin(), e.begin() + 1, back_inserter(s), ::toupper);
        s += e.substr(1, e.size() - 1);

        contenuFichier += "\n\tstd::cout << \"" + s +
                          " = \"<< " + nomClasseMinuscule + ".get" + s + "()" +
                          "<< std::endl; ";
    }

    contenuFichier += "\n\treturn 0;\n}\n";
    // contenuFichier += "\nint main\n{\n}";

    return contenuFichier;
}
void generationFichierMain(string nomClasse, vector<string> &attributs)
{
    string contenuFichier;
    string ficc = "main.cpp";

    generationInclusionHeaderMain(nomClasse, contenuFichier);
    generationFonctionMain(nomClasse, contenuFichier, attributs);

    ecritureFichier(ficc, contenuFichier);
}

/***********************Create class .H**********************************************************************/

void creationFichier_h(string nomClasse)
{
    std::ofstream fichier_h(nomClasse + ".h");

    if (fichier_h.is_open())
    {
        std::cout << "Le fichier " << nomClasse << ".h a bien été créé" << std::endl;
        fichier_h.close();
    }
    else
    {
        std::cout << "Erreur lors de la création du fichier " << nomClasse << ".h" << std::endl;
        // Quitter le programme en cas d'erreur
    }
}

void ecritureFichier_h(string nomClasse, vector<string> attributs)
{
    string nomClasse_Maj = nomClasse;
    transform(nomClasse_Maj.begin(), nomClasse_Maj.end(), nomClasse_Maj.begin(), ::toupper);

    int nbAttribut = size(attributs);

    std::ofstream file(nomClasse + ".h");
    if (file.is_open())
    {

        file << "# ifndef " + nomClasse_Maj + "_H" << endl;
        file << "# define " + nomClasse_Maj + "_H\n"
             << endl;
        file << "class " + nomClasse + " {" << endl;
        file << "public:" << endl;
        file << "\t" + nomClasse + "();" << endl;
        file << "\t" + nomClasse + "(";
        for (int i = 0; i < nbAttribut; i++)
        {
            if (i == nbAttribut - 1)
            {
                file << "int " + attributs[i] + ");\n"
                     << endl;
                ;
            }
            else
            {
                file << "int " + attributs[i] + ",";
            }
        }

        for (int i = 0; i < nbAttribut; i++)
        {
            attributs[i][0] = toupper(attributs[i][0]);
            file << "\tint get" << attributs[i] << "() const;" << endl;
            file << "\tvoid set" << attributs[i] << "(int ";
            attributs[i][0] = tolower(attributs[i][0]);
            file << attributs[i] << ");\n"
                 << endl;
        }

        file << "private:\n";
        for (auto e : attributs)
        {
            file << "\tint " + e + ";" << endl;
        }
        file << "};\n"
             << endl;
        file << "# endif" << endl;

        cout << "Fichier enregistré !" << endl;
        file.close();
    }
    else
    {
        cout << "Problème d'ouverture du fichier pour écriture... Veuillez réessayer l'opération." << endl;
    }
}

void generationFichierh(string nomClasse, vector<string> &attributs)
{
    creationFichier_h(nomClasse);
    ecritureFichier_h(nomClasse, attributs);
}

/***************    Create make                                                ***********/
std::string texteMakefile(std::string nomDuProgram, std::string nomClass)
{

    std::string monTexte;
    monTexte = "CXX = g++\n";
    monTexte += "CXXFLAGS = -std=c++11 -Wall -Werror\n\n";
    monTexte += "all: " + nomDuProgram + "\n\n";
    monTexte += nomDuProgram + ": " + nomClass + ".cpp main.cpp\n";
    monTexte += "\t$(CXX) $(CXXFLAGS) -o " + nomDuProgram + " " + nomClass + ".cpp  main.cpp\n\n";
    monTexte += "run:\n";
    monTexte += "\t\t./" + nomDuProgram + "\n";
    monTexte += "\n\nclean:\n";
    monTexte += "\t\trm -f " + nomDuProgram + ".cpp\n";
    monTexte += "\t\trm -f " + nomClass + ".h\n";
    monTexte += "\t\trm -f " + nomClass + ".cpp\n";
    monTexte += "\t\trm -f main.cpp\n\n";
    monTexte += "\n\nclean-o:\n";
    monTexte += "\t\trm -f *.o\n";

    return monTexte;
}

void lectureFichier(std::string &nomFichier)
{

    std::ifstream fichierEntre(nomFichier);

    if (fichierEntre.is_open())
    {
        std::string ligne;
        while (getline(fichierEntre, ligne))
        {
            std::cout << ligne << std::endl;
        }
        fichierEntre.close();
    }
    else
    {
        std::cout << "Erreur à l'ouverture du fichier" << std::endl;
    }
}

int main()
{

    std::string nomClasse;

    std::vector<std::string> attributs;
    nomClasse = ajoutNomClasse();

    bool ajouter = true;

    while (ajouter)
    {
        int choix;
        std::cout << "1. Ajouter un attribut de classe\n";
        std::cout << "2. afficher la liste des attributs de la classe\n";
        std::cout << "3. Terminer\n";
        std::cin >> choix;

        switch (choix)
        {
        case 1:
            attributs = ajouterAttribut(attributs);

            break;

        case 2:
            affichageAttribut(attributs, nomClasse);
            break;

        case 3:
            ajouter = false;
            break;

        default:
            std::cout << " Erreur de saisie!!\n";
            break;
        }
    }

    generationFichierCpp(nomClasse, attributs);
    generationFichierMain(nomClasse, attributs);
    generationFichierh(nomClasse, attributs);

    std::string monTexte;
    std::string nomDuProgram = "classMaker";

    std::string nomFichier = "Makefile";

    monTexte = texteMakefile(nomDuProgram, nomClasse);
    ecritureFichier(nomFichier, monTexte);
    lectureFichier(nomFichier);

    // 1)  fonction  pour lancer la création des points .cpp, .h et main.cpp:
    // 2)  fonction pour lancer la création du makeFile
    // 3)  commande de lancement du makeFile avec la commande system (".\make")
}
