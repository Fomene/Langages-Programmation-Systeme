#include <chrono>
#include <iostream>

using namespace std;

// tableau de grande taille et 100 000 appels par type d'allocation.
constexpr std::size_t TAILLE_TABLEAU = 1'000'000;
constexpr int         NB_ITERATIONS  = 100'000;

// pour 1'000'000 éléments sur la pile, augmenter la taille de pile si nécessaire.
using Horloge = chrono::high_resolution_clock;

// Allocation statique 
int tableau_statique[TAILLE_TABLEAU];

void allocation_statique() {
    tableau_statique[0] = 1;
}

void allocation_pile() {
    int tableau_pile[TAILLE_TABLEAU]; // allocation sur la pile
    tableau_pile[0] = 1;
}

void allocation_dynamique() {
    int* tableau_dynamique = new int[TAILLE_TABLEAU]; // allocation dynamique
    tableau_dynamique[0] = 1;
    delete[] tableau_dynamique;
}

template<typename Fonction>
double chronometrer(Fonction fonction) {
    auto debut_mesure = Horloge::now();

    for (int iteration = 0; iteration < NB_ITERATIONS; ++iteration) {
        fonction();
    }

    auto fin_mesure = Horloge::now();
    chrono::duration<double> duree = fin_mesure - debut_mesure;
    return duree.count();
}

int main() {
    cout << "Taille du tableau  : " << TAILLE_TABLEAU << " elements\n";
    cout << "Nombre d'iterations : " << NB_ITERATIONS << "\n";

    double temps_statique = chronometrer(allocation_statique);
    double temps_pile      = chronometrer(allocation_pile);
    double temps_dynamique = chronometrer(allocation_dynamique);

    cout << "Allocation statique : " << temps_statique << " s\n";
    cout << "Allocation pile     : " << temps_pile      << " s\n";
    cout << "Allocation dynamique: " << temps_dynamique << " s\n";
}
