#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
// #include "generationMain.cpp"
using namespace std;
void ecritureFichier(string &nomFichier, string &texte)
{
    std::ofstream outFile(nomFichier);
    if (outFile.is_open())
    {
        outFile << texte << std::endl;
        std::cout << "fichier enregistré avec succes" << std::endl;
    }
    outFile.close();
}

string generationInclusionHeader(string nomClasse, string &contenuFichier)
{
    contenuFichier = "#include \" " + nomClasse + ".h \"\n\n";
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
    contenuFichier += "\n#include\"" + nomClasse + ".cpp\"";
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
    for (size_t i = 0; i < 3; i++)
    {
        contenuFichier += "\n\tint\t variable" + to_string(i) + " = " + to_string((i + 1)) + ";";
    }
    ////////////////////instanciation objet
    contenuFichier += "\n\t" + nomClasse + " " + nomClasseMinuscule + " =";
    contenuFichier += "" + nomClasse + "( ";
    for (size_t i = 0; i < 3; i++)
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

        contenuFichier += "\n\tstd::cout <<" + s +
                          "= << " + nomClasseMinuscule + ".get" + s + "()" +
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

int main(int argc, char const *argv[])
{

    string nomClasse = "Person";
    vector<string> attributs(3);

    attributs[0] = "variable1";
    attributs[1] = "variable2";
    attributs[2] = "variable3";
    generationFichierCpp(nomClasse, attributs);
    generationFichierMain(nomClasse, attributs);
    return 0;
}
