#pragma once

#include <string>

class Cpf {
    private:
        std::string numero;
    public:
        explicit Cpf(std::string numero);
        std::string getNumero();
    private:
        bool valida(std::string numero);
};