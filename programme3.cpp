#include <iostream>
#include <chrono>
using namespace std;

constexpr int NB_ITERATIONS = 50'000'000;

class A {
public:
    void statique() const {        // liaison statique
        // opération minimale
        asm(""); // empêche certaines optimisations
    }

    virtual void dynamique() const { // liaison dynamique
        asm("");
    }
};

int main() {
    A objet;
    using Horloge = chrono::high_resolution_clock;

    // Mesure liaison statique
    auto debut_stat = Horloge::now();
    for (int i = 0; i < NB_ITERATIONS; ++i) {
        objet.statique();
    }
    auto fin_stat = Horloge::now();

    // Mesure liaison dynamique
    auto debut_dyn = Horloge::now();
    for (int i = 0; i < NB_ITERATIONS; ++i) {
        objet.dynamique();
    }
    auto fin_dyn = Horloge::now();

    chrono::duration<double> t_stat = fin_stat - debut_stat;
    chrono::duration<double> t_dyn  = fin_dyn  - debut_dyn;

cout << "Temps liaison statique : " << t_stat.count() << " s\n";
cout << "Temps liaison dynamique: " << t_dyn.count()  << " s\n";
cout << "Difference            : " << (t_dyn.count() - t_stat.count()) << " s\n";


    return 0;
}
