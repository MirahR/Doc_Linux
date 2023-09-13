#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

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
    contenuFichier += "\nusing namespace std;";
    return contenuFichier;
}
string generationFonctionMain(string nomClasse, string &contenuFichier)
{

    contenuFichier += "\nint main( void )\n{";
    contenuFichier += "\n\tint\t x = 4;";

    string s;
    transform(nomClasse.begin(), nomClasse.end(), back_inserter(s), ::tolower);
    for (size_t i = 0; i < 3; i++)
    {
        contenuFichier += "\n\tint\t variable" + to_string(i) + " = " + to_string((i + 1)) + ";";

        // s += to_string(i);
        // contenuFichier += "\n\t" + nomClasse + " " + s + " =";
        // contenuFichier += "" + nomClasse + "( , ) ;";

        // s.erase(s.end() - 1, s.end());
    }
    // for (size_t i = 0; i < 3; i++)
    // {

    //     s += to_string(i);
    //     contenuFichier += "\n\t" + nomClasse + " " + s + " =";
    //     contenuFichier += "" + nomClasse + "(" + to_string((i + 1)) + " , ) ;";

    //     s.erase(s.end() - 1, s.end());
    // }
    // s += to_string(i);
    contenuFichier += "\n\t" + nomClasse + " " + s + " =";
    contenuFichier += "" + nomClasse + "( ";
    for (size_t i = 0; i < 3; i++)
    {

        contenuFichier += to_string((i + 1)) + " ,";
    }
    contenuFichier.erase(contenuFichier.end() - 1, contenuFichier.end());
    contenuFichier += ") ;";

    contenuFichier += "\n\treturn 0;\n}\n";
    // contenuFichier += "\nint main\n{\n}";

    return contenuFichier;
}
void generationFichierMain(string nomClasse, vector<string> &attributs)
{
    string contenuFichier;
    string ficc = "main.cpp";

    generationInclusionHeaderMain(nomClasse, contenuFichier);
    generationFonctionMain(nomClasse, contenuFichier);

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
