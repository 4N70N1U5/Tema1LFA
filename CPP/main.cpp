#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int n, m, nf, ni; // n - nr noduri; m - nr tranzitii; nf - nr stari finale; ni - nr input-uri
char adiacenta[50][50]; // matrice de adiacenta
int initiala; // indicele starii initiale
std::vector<int> finale; // indicii starilor finale
std::vector<std::string> cuv; // cuvintele care trebuie testate
std::vector<int> drum; // nodurile din drumul gasit pentru fiecare cuvant
bool acc; // starea cuvantului - acceptat sau nu

void DFS()
{

}

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
        finale.push_back(aux);
    }

    fin >> ni;
    
    for (int i = 0; i < ni; i++)
    {
        std::string aux;
        cuv.push_back(aux);
    }
}

int main()
{

    std::cout << '\n';
    return 0;
}
