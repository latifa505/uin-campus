#include "uincampus/statistiques.hpp"
#include <algorithm>
#include <cmath>
#include <print>
#include <string>
namespace uin {
Statistiques calculer_statistiques(const std::vector<double>& notes) {
    Statistiques s;
    s.minimum = noteMax;
    s.maximum = noteMin;
    double somme{0.0};
    for (double n: notes) {
        s.minimum = std::min(s.minimum, n);
        s.maximum = std::max(s.maximum, n);
        somme += n;
        if (n >= seuilValidation) ++s.admis;
        ++s.repartition[static_cast<std::size_t>(mentionPour(n))];
    }
    const double taille = static_cast<double>(notes.size());
    s.moyenne = somme / taille;
    double sommeEcarts{0.0};
    for (double n: notes) { sommeEcarts += (n - s.moyenne) * (n - s.moyenne); }
    s.ecartType = std::sqrt(sommeEcarts / taille);
    return s;
}
void afficher_statistiques(const std::string& ue, int nb, const Statistiques& s) {
    const double taille = static_cast<double>(nb);
    std::println("\nStatistiques - {} ({} etudiants)", ue, nb);
    std::println("{:-<58}", "");
    std::println("{:<18}: {:6.2f}", "Note minimale", s.minimum);
    std::println("{:<18}: {:6.2f}", "Note maximale", s.maximum);
    std::println("{:<18}: {:6.2f}", "Moyenne", s.moyenne);
    std::println("{:<18}: {:6.2f}", "Ecart-type", s.ecartType);
    std::println("{:<18}: {:6} ({:.1f} %)", "Admis", s.admis, 100.0 * s.admis / taille);
    std::println("\nRepartition par mention");
    for (std::size_t i{0}; i < nbMentions; ++i) {
        const auto m = static_cast<Mention>(i);
        std::println("{:<12} {} ({})", libelle(m),
            std::string(static_cast<std::size_t>(s.repartition[i]), '*'), s.repartition[i]);
    }
}
}