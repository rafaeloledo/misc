#include "Conta.hpp"
#include <iostream>

Conta::Conta(std::string numero, Titular titular):
    numero(numero),
    titular(titular),
    saldo(0)
{
    numeroDeContas++;
}

Conta::~Conta() {
    numeroDeContas--;
}

std::variant<Conta::ResultadoSaque, float> Conta::sacar (float valorASacar) {
    if (valorASacar < 0) {
        std::cout << "Não pode sacar valor negativo" << std::endl;
        return ValorNegativo;
    }

    float tarifaDeSaque = valorASacar * taxaDeSaque();
    float valorDoSaque = valorASacar + tarifaDeSaque;

    if (valorDoSaque > saldo) {
        std::cout << "Saldo insuficiente" << std::endl;
        return SaldoInsuficiente;
    }

    saldo -= valorDoSaque;
    
    return saldo;
}

void Conta::depositar(float valorADepositar) {
    if (valorADepositar < 0) {
        std::cout << "Não pode depositar valor negativo" << std::endl;
    }
    saldo += valorADepositar;
}

float Conta::getSaldo() const {
    return saldo;
}

int Conta::getNumeroDeContas() {
    return numeroDeContas;
}

Titular Conta::getTitular() {
    return titular;
}

void Conta::operator+=(float valorADepositar) {
    depositar(valorADepositar);
}

bool Conta::operator<(const Conta& outra)
{
    return this->saldo < outra.saldo;
}