#pragma once
#include <cstddef>
#include <string_view>
namespace uin {
inline constexpr std::size_t nbMentions = 5;
inline constexpr double noteMin = 0.0;
inline constexpr double noteMax = 20.0;
inline constexpr double seuilValidation = 10.0;
enum class Mention { Ajourne, Passable, AssezBien, Bien, TresBien };
Mention mentionPour(double note);
std::string_view libelle(Mention m);
}