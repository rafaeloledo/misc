#include "Autenticavel.hpp"

Autenticavel::Autenticavel (std::string senha) : senha(senha)
{

}

bool Autenticavel::autentica (std::string) const
{
    return senha == this->senha;
}