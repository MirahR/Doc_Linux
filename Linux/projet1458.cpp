#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <limits>
using namespace std;

//***************Partie Saisie Datas**************************************************//

string selectTypeAttribut()
{
    string typeAttribut;

    bool saisieOk = false;

    string type[6] = {"string", "int", "float", "double", "bool", "char"};

    while (!saisieOk)
    {
        int choix;
        std::cout << " Merci de choisir un type d'attribut\n";
        std::cout << " 1. string\n";
        std::cout << " 2. int\n";
        std::cout << " 3. float\n";
        std::cout << " 4. double\n";
        std::cout << " 5. bool\n";
        std::cout << " 6. char\n";
        {
            cin >> choix;
            if (choix >= 1 && choix <= 6)
            {
                typeAttribut = type[choix - 1];
                saisieOk = true;
            }
            else
            {
                std::cout << "Saisie invalide. Réessayez." << endl;
                cin.clear();                                         // Réinitialise l'état du flux cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Efface le reste de la ligne
            }
        }
        continue;
    }
    return typeAttribut;
}

vector<string> ajouterTypeAttributParDefault(vector<string> typeAttributs)
{
    typeAttributs.push_back(selectTypeAttribut());

    return typeAttributs;
}

std::string ajoutNomClasse() // Controle du cas vide ou commencant par un chiffre
{
    std::string nomClasse;
    bool saisieValide = false;

    while (!saisieValide)
    {
        std::cout << "Merci de saisir le nom de votre Classe: \n ";
        std::getline(std::cin, nomClasse);

        saisieValide = !nomClasse.empty();

        if (!saisieValide || isalpha(nomClasse[0] || nomClasse.find('.') != std::string::npos))
        {
            std::cout << "Saisie invalide. Réessayez." << std::endl;
        }
    }

    nomClasse[0] = toupper(nomClasse[0]);

    return nomClasse;
}
/*

string ajoutNomClasse()
{
    string nomClasse;
    bool saisieValide = false;
    while (!saisieValide)
    {
        cout << "Merci de saisir le nom de votre Classe : ";
        getline(cin, nomClasse);
        saisieValide = !nomClasse.empty();
        if (!saisieValide)
        {
            cout << "Saisie invalide. Réessayez." << endl;
        }
    }
    nomClasse[0] = toupper(nomClasse[0]);
    return nomClasse;
}
*/

vector<string> ajouterAttributParDefault(vector<string> attributs)
{
    string attribut;

    cout << "Nom de l'attribut: \n";
    cin.ignore();
    cin >> attribut;
    attributs.push_back(attribut);
    return attributs;
}

vector<string> ajouterAttributPersonnaliser(vector<string> attributs)
{

    string attribut;
    cout << "Nom de l'attribut: \n";
    cin.ignore();
    cin >> attribut;
    attributs.push_back(attribut);
    return attributs;
}

void affichageAttribut(vector<string> attributs, string nomClasse)
{
    cout << "NOM DE LA CLASSE : " << nomClasse << endl;
    cout << endl;
    cout << "Listes des attributs" << endl;
    for (string attribut : attributs)
    {
        cout << attribut << endl;
    }
}

vector<string> ajouterAttribut(vector<string> attributs)
{
    string attribut;
    cout << "Nom de l'attribut: \n";
    cin.ignore();
    cin >> attribut;
    attributs.push_back(attribut);
    return attributs;
}

/**********************************Create Class CPP******************************************************/

void ecritureFichier(string &nomFichier, string &texte)
{
    ofstream outFile(nomFichier);
    if (outFile.is_open())
    {
        outFile << texte << endl;
        cout << nomFichier << " enregistré avec succès !" << endl;
    }
    else
    {
        cout << "Problème sur le fichier " << nomFichier << "\n";
    }
    outFile.close();
}

string generationInclusionHeader(string nomClasse, string &contenuFichier)
{
    contenuFichier = "# include \"" + nomClasse + ".h\"\n";
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
    contenuFichier += "}\n";
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
        contenuFichier += "int " + e + ",";
    }
    contenuFichier.erase(contenuFichier.end() - 1, contenuFichier.end());

    contenuFichier += ")\n{\n";
    for (auto e : attributs)
    {
        contenuFichier += "\tthis->" + e + " = " + e + ";\n";
    }
    contenuFichier += "}\n";
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
        contenuFichier += "\n int " +
                          nomClasse + "::" +
                          "get" + s + "() const \n{\n\treturn " + e + ";\n}\n";
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
        contenuFichier += "\nvoid " +
                          nomClasse + "::" +
                          "set" + s + "(int " + e + ")\n{\n"
                                                    "\tthis->" +
                          e + " = " + e + ";\n}\n";
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

/**********************************Create main.cpp******************************************************/

string generationInclusionHeaderMain(string nomClasse, string &contenuFichier)
{
    contenuFichier = "# include <iostream>\n";
    contenuFichier += "# include <cmath>\n";
    contenuFichier += "# include <fstream>\n";
    contenuFichier += "# include <vector>\n";
    contenuFichier += "# include <cctype>\n";
    contenuFichier += "# include <algorithm>\n";
    contenuFichier += "# include \"" + nomClasse + ".h\"\n";
    contenuFichier += "using namespace std;\n";
    return contenuFichier;
}

string generationFonctionMain(string nomClasse, string &contenuFichier, vector<string> &attributs)
{
    string nomClasseMinuscule;
    contenuFichier += "int main()\n{";

    /////////////////// declaration variables
    string s;
    transform(nomClasse.begin(), nomClasse.end(), back_inserter(nomClasseMinuscule), ::tolower);

    /////////////////// instanciation objet
    contenuFichier += "\n\t" + nomClasse + " " + nomClasseMinuscule + " = ";
    contenuFichier += nomClasse + "(";
    for (size_t i = 0; i < attributs.size(); i++)
    {
        contenuFichier += to_string((i + 1)) + ", ";
    }
    contenuFichier.erase(contenuFichier.end() - 1, contenuFichier.end());
    contenuFichier += ");\n";

    //////////////////// setters
    for (auto e : attributs)
    {
        string s;
        transform(e.begin(), e.begin() + 1, back_inserter(s), ::toupper);
        s += e.substr(1, e.size() - 1);
        contenuFichier += "\t" + nomClasseMinuscule + "." +
                          "set" + s + "(" + to_string((1 + rand() % 5)) + ");\n";
    }

    //////////////////// getters
    for (auto e : attributs)
    {
        string s;
        transform(e.begin(), e.begin() + 1, back_inserter(s), ::toupper);
        s += e.substr(1, e.size() - 1);

        contenuFichier += "\tcout << \"" + s +
                          " = \"<< " + nomClasseMinuscule + ".get" + s + "()" +
                          " << endl;\n";
    }
    contenuFichier += "\treturn 0;\n}\n";
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

void ecritureFichierH(string nomClasse, vector<string> attributs)
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

        cout << "Fichier " << nomClasse << ".h enregistré avec succès !" << endl;
        file.close();
    }
    else
    {
        cout << "Problème d'ouverture du fichier " << nomClasse << ".h pour écriture... Veuillez réessayer l'opération." << endl;
    }
}

void generationFichierh(string nomClasse, vector<string> &attributs)
{
    creationFichier_h(nomClasse);
    ecritureFichierH(nomClasse, attributs);
}

/*************** Create make ***************/

string texteMakefile(string nomDuProgram, string nomClass)
{
    string monTexte;
    monTexte = "CXX = g++\n";
    monTexte += "CXXFLAGS = -std=c++11 -Wall\n";
    monTexte += "\nall: " + nomDuProgram + "\n";
    monTexte += nomDuProgram + ": " + nomClass + ".cpp main.cpp\n";
    monTexte += "\t$(CXX) $(CXXFLAGS) -o " + nomDuProgram + " " + nomClass + ".cpp main.cpp\n";
    monTexte += "\nrun:\n";
    monTexte += "\t\t.\\" + nomDuProgram + "\n";
    monTexte += "\nclean:\n";
    monTexte += "\trm -f " + nomDuProgram + ".cpp\n";
    monTexte += "\trm -f " + nomClass + ".h\n";
    monTexte += "\trm -f " + nomClass + ".cpp\n";
    monTexte += "\trm -f main.cpp\n";
    monTexte += "\nclean-o:\n";
    monTexte += "\trm -f *.o\n";
    return monTexte;
}

void lectureFichier(string &nomFichier)
{
    ifstream fichierEntre(nomFichier);

    if (fichierEntre.is_open())
    {
        cout << "\nLecture du Makefile" << endl;
        string ligne;
        while (getline(fichierEntre, ligne))
        {
            cout << ligne << endl;
        }
        fichierEntre.close();
    }
    else
    {
        cout << "Erreur à l'ouverture du Makefile" << endl;
    }
}

int main()
{
    string typeAttribut;
    string nomClasse;
    vector<string> typeAttributs;
    vector<string> attributs;
    nomClasse = ajoutNomClasse();
    bool ajouter = true;
    while (ajouter)
    {
        int choix;
        cout << "\n1. Ajouter un attribut de classe avec type par défaut\n";
        cout << "2. Ajouter un attribut de classe avec type personnaliser\n";
        cout << "3. Afficher la liste des attributs de la classe\n";
        cout << "4. Terminer\n";
        cin >> choix;
        cout << "\n";
        switch (choix)
        {
        case 1:
            typeAttribut = selectTypeAttribut();
            attributs = ajouterAttributParDefault(attributs);
            break;
        case 2:
            typeAttributs = ajouterTypeAttributParDefault(typeAttributs);
            attributs = ajouterAttributPersonnaliser(attributs);
            break;
        case 4:
            ajouter = false;
            break;
        case 3:
            affichageAttribut(attributs, nomClasse);
            break;
        default:
            cout << "Erreur de saisie!!!\n";
            break;
        }
    }

    //    while (ajouter)
    //    {
    //        int choix;
    //        cout << "1. Ajouter un attribut de classe\n";
    //        cout << "2. Afficher la liste des attributs de la classe\n";
    //        cout << "3. Terminer\n";
    //        cin >> choix;
    //        cout << "\n";
    //        switch (choix)
    //        {
    //        case 1:
    //            attributs = ajouterAttribut(attributs);
    //            cout << "\n";
    //            break;
    //        case 2:
    //            affichageAttribut(attributs, nomClasse);
    //            cout << "\n";
    //            break;
    //        case 3:
    //            ajouter = false;
    //            cout << "\n";
    //            break;
    //        default:
    //            cout << "Erreur de saisie!!!\n";
    //            break;
    //        }
    //    }

    generationFichierCpp(nomClasse, attributs);
    generationFichierMain(nomClasse, attributs);
    generationFichierh(nomClasse, attributs);
    string monTexte;
    string nomDuProgram = "classMaker";
    string nomFichier = "Makefile";

    monTexte = texteMakefile(nomDuProgram, nomClasse);
    ecritureFichier(nomFichier, monTexte);
    lectureFichier(nomFichier);

    // 1)  fonction  pour lancer la création des points .cpp, .h et main.cpp:
    // 2)  fonction pour lancer la création du makeFile
    // 3)  commande de lancement du makeFile avec la commande system (".\make")
}
