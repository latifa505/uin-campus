#include "uincampus/saisie.hpp"
#include "uincampus/statistiques.hpp"
#include <format>
#include <iostream>
#include <vector>
int main() {
    std::cout << "Nom de l'UE: ";
    std::string ue;
    std::getline(std::cin, ue);
    const int nb = uin::lireEntier("Nombre d'etudiants (1 a 200): ", 1, 200);
    std::vector<double> notes;
    for (int i{1}; i <= nb; ++i) {
        notes.push_back(uin::lireNote(std::format("Note de l'etudiant {}: ", i)));
    }
    const auto stats = uin::calculer_statistiques(notes);
    uin::afficher_statistiques(ue, nb, stats);
}