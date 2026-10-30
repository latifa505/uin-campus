#include "uincampus/version.hpp"
#include <cstdio>
#include <print>

int main() // NOLINT(bugprone-exception-escape)
{
    try {
        std::println("UIN-Campus - Systeme de gestion academique");
        std::println("Version {}", uin::version());
    } catch (...) {
        std::fputs("Erreur critique\n", stderr);
        return 1;
    }
    return 0;
}
