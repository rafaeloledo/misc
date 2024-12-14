#include "Cpf.hpp"
#include <iostream>

Cpf::Cpf(std::string numero) {
    if(!valida(numero)) {
        std::cout << "Cpf tem que ter 14 dígitos" << std::endl;
        exit(1);
    }
    this->numero = numero;
}

std::string Cpf::getNumero() {
    return this->numero;
}

bool Cpf::valida(std::string numero) {
    return numero.size() == 14;
}
