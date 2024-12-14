#pragma once

#include "Conta.hpp"

class ContaCorrente final: public Conta 
{
    public:
        ContaCorrente(std::string, Titular titular);
        float taxaDeSaque() const override;
        void transferePara(Conta& conta, float valor);
        void operator+=(ContaCorrente& contaDeOrigem);
};