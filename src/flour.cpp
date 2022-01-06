#include "flour.h"

namespace tyc {

Flour::Flour(IngredientType_e type, double_t percentage, double_t quantity, FlourType_e flourType, std::string flourName)
    : Ingredient  ( type, percentage, quantity )
    , m_flourType ( flourType                  )
    , m_flourName ( std::move( flourName )     )
{
}

const FlourType_e& Flour::getFlourType() const noexcept
{
    return m_flourType;
}

const std::string &Flour::getFlourName() const noexcept
{
    return m_flourName;
}

} // namespace tyc
