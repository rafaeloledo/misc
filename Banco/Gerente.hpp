#pragma once
#include "Funcionario.hpp"
#include "Autenticavel.hpp"
#include "DiaDaSemana.hpp"

class Gerente final : public Funcionario, Autenticavel
{
    public:
        Gerente(Cpf cpf, std::string nome, float salario, std::string senha, DiaDaSemana diaDoPagamento);
        float bonificacao() const;
};