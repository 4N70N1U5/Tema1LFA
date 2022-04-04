#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int n, m, nf, ni; // n - nr noduri; m - nr tranzitii; nf - nr stari finale; ni - nr input-uri
char adiacenta[50][50]; // matricea de adiacenta
int initiala; // indicele starii initiale
std::vector<int> finale; // indicii starilor finale
std::vector<std::string> lista; // lista cuvintelor care trebuie testate
std::vector<std::string>::iterator pozitie; // iterator pentru lista de cuvinte
std::string curent; //cuvantul la care am ajuns sa-l testam
std::vector<int> drum; // nodurile din drumul gasit pentru fiecare cuvant
int indiceLitera; // indice pentru litera la care am ajuns in cuvant
bool acceptat; // daca cuvantul a fost acceptat sau nu

void citiri()
{
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        fin >> a >> b >> c;
        adiacenta[a][b] = c;
    }

    fin >> initiala;
    
    fin >> nf;

    for (int i = 0; i < nf; i++)
    {
        int aux;
        fin >> aux;
        finale.push_back(aux);
    }

    fin >> ni;
    
    for (int i = 0; i < ni; i++)
    {
        std::string aux;
        fin >> aux;
        lista.push_back(aux);
    }
}

void afisare()
{
    if (acceptat)
    {
        fout << "DA";
        for (int i = 0; i < drum.size(); i++)
        {
            fout << " " << drum[i];
        }
    }
    else
    {
        fout << "NU";
    }

    fout << "\n\n";
}

void verificare(int stare)
{
    if (indiceLitera == curent.size() && std::find(finale.begin(), finale.end(), stare) != finale.end())
    {
        acceptat = true;
        drum.push_back(stare);
        afisare();
        return;
    }

    if (indiceLitera == curent.size())
        return; // daca s-au terminat literele din cuvant, functia se opreste

    if (acceptat)
        return; // daca cuvantul a fost deja acceptat, functia se opreste
    
    for (int i = 0; i < n; i++)
    {
        if (adiacenta[stare][i] == curent[indiceLitera])
        {
            indiceLitera++;
            drum.push_back(stare);
            verificare(i);
            drum.pop_back();
            indiceLitera--;
        }
    }
}

int main()
{
    citiri();

    for (pozitie = lista.begin(); pozitie < lista.end(); pozitie++)
    {
        curent = *pozitie;
        indiceLitera = 0;
        drum.clear();
        acceptat = false;

        verificare(initiala);

        if (!acceptat)
            afisare();
    }

    return 0;
}
