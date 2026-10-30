#pragma once
#include <array>
#include <string>
#include <vector>
#include "uincampus/regles.hpp"
namespace uin {
struct Statistiques {
    double minimum = 0.0;
    double maximum = 0.0;
    double moyenne = 0.0;
    double ecartType = 0.0;
    int admis = 0;
    std::array<int, nbMentions> repartition{};
};
Statistiques calculer_statistiques(const std::vector<double>& notes);
void afficher_statistiques(const std::string& ue, int nb, const Statistiques& s);
}