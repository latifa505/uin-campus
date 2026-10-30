#include "uincampus/saisie.hpp"
#include "uincampus/regles.hpp"
#include <iostream>
#include <sstream>
#include <string>
namespace uin {
int lireEntier(std::string_view invite, int min, int max) {
    while (true) {
        std::cout << invite;
        std::string ligne;
        if (!std::getline(std::cin, ligne)) return min;
        std::istringstream flux{ligne};
        int valeur{};
        char reste{};
        if (!(flux >> valeur) || (flux >> reste)) {
            std::cout << " Saisie invalide: entrez un nombre entier.\n";
        } else if (valeur < min || valeur > max) {
            std::cout << " La valeur doit être comprise entre " << min << " et " << max << ".\n";
        } else { return valeur; }
    }
}
double lireNote(std::string_view invite) {
    while (true) {
        std::cout << invite;
        std::string ligne;
        if (!std::getline(std::cin, ligne)) return noteMin;
        for (char& c: ligne) { if (c == ',') c = '.'; }
        std::istringstream flux{ligne};
        double note{};
        char reste{};
        if (!(flux >> note) || (flux >> reste)) {
            std::cout << " Saisie invalide.\n";
        } else if (note < noteMin || note > noteMax) {
            std::cout << " La note doit être comprise entre 0 et 20.\n";
        } else { return note; }
    }
}
}