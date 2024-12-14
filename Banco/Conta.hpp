#pragma once

#include <string>
#include <utility>
#include <variant>
#include <ostream>

#include "Titular.hpp"
#include "Conta.hpp"

class Conta {
    private:
        static int numeroDeContas;
        Titular titular;
    private:
        std::string numero;
    protected:
        float saldo;
    public:
        enum ResultadoSaque
        {
            ValorNegativo, SaldoInsuficiente
        };

        Conta(std::string numero, Titular titular);
        virtual ~Conta();
        std::variant<ResultadoSaque, float> sacar(float valorASacar);
        virtual float taxaDeSaque() const = 0;
        void depositar(float valorADespositar);
        void operator+=(float valorADepositar);
        static int getNumeroDeContas();
        float getSaldo() const;
        Titular getTitular();
        bool operator<(const Conta& outra);
        //friend ostream& operator <<(ostream& cout, const Conta& conta);
};
