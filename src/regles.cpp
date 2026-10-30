#include "uincampus/regles.hpp"
namespace uin {
Mention mentionPour(double note) {
    if (note < seuilValidation) return Mention::Ajourne;
    if (note < 12.0) return Mention::Passable;
    if (note < 14.0) return Mention::AssezBien;
    if (note < 16.0) return Mention::Bien;
    return Mention::TresBien;
}
std::string_view libelle(Mention m) {
    using enum Mention;
    switch (m) {
    case Ajourne: return "Ajourné";
    case Passable: return "Passable";
    case AssezBien: return "Assez bien";
    case Bien: return "Bien";
    case TresBien: return "Très bien";
    }
    return "Inconnue";
}
}