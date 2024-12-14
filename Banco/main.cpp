#include <iostream>
#include <string>
#include <optional>
#include <any>
 
#include "Funcionario.hpp"
#include "Conta.hpp"
#include "ContaPoupanca.hpp"
#include "Gerente.hpp"
#include "ContaCorrente.hpp"
#include "DiaDaSemana.hpp"

using namespace std;

int Conta::numeroDeContas = 0;

void ExibeSaldo(const Conta& conta) {
    cout << "O saldo da conta é: " << conta.getSaldo() << endl;
}

void RealizaSaque(Conta& conta) {
    auto resultado = conta.sacar(200);
    
    if(auto saldo = std::get_if<float>(&resultado)) {
        cout << "Novo saldo da conta: " << saldo << endl;
    } 
} 

void FazLogin(Autenticavel& alguem, string senha) 
{
    if (alguem.autentica(senha)) {
        cout << "Login realizado com sucesso" << endl;
    } else {
        cout << "Senha inválida" << endl;
    }
}
/*
ostream& operator <<(ostream& cout, const Conta& conta) {
    Pessoa titular = conta.getTitular();
    cout << "O saldo da conta é (operador): " << conta.getSaldo() << endl;
    cout << "O titular da conta é :" << titular.getNome() << endl;
    return cout;
} */

template<typename T>
T& Menor (T& a, T& b) {
    return a < b ? a : b;
}

int main() 
{
    Titular titularUm(Cpf("123.456.789-10"), "Rafael", "senha");
    ContaPoupanca contaPoupanca("123456", titularUm);
    contaPoupanca.depositar(500);

    Titular titulasDois(Cpf("098.765.432-10"), "Pedro Guilherme", "outrasenha");
    ContaCorrente contaCorrente("159753", titularUm);
    (Conta&) contaCorrente += 300;

    ContaCorrente contaCorrenteDois("123478", titularUm);

    contaCorrenteDois += contaCorrente;  
    
    Gerente gerenteUm(Cpf("123.951.756.44"), "Antônio", 1500, "159753", DiaDaSemana::Terca);

    cout << Menor<Conta&>(contaPoupanca, contaCorrente).getSaldo();

    return 0;
}