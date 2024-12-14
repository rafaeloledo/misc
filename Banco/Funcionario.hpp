#pragma once
#include "Cpf.hpp"
#include "Pessoa.hpp"
#include <string>
#include "DiaDaSemana.hpp"

class Funcionario : public Pessoa<Cpf>
{
    private:
        float salario;
        // 0 domingo, 1 segunda ...
        DiaDaSemana diaDoPagamento;
    public:
        Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);
        float getSalario() const;
        std::string getNome() const;
        virtual float bonificacao() const = 0;
};