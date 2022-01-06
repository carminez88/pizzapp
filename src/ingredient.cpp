#include "ingredient.h"

namespace tyc {

Ingredient::Ingredient(IngredientType_e type, double_t percentage, double_t quantity)
    : m_type       ( type              )
    , m_percentage ( percentage        )
    , m_quantity   ( quantity          )
{
}

const IngredientType_e& Ingredient::getIngredientType() const noexcept
{
    return m_type;
}

void Ingredient::setIngredientType(IngredientType_e type)
{
    m_type = type;
}

const double_t& Ingredient::getIngredientPercentage() const noexcept
{
    return m_percentage;
}

void Ingredient::setIngredientPercentage(double_t percentage)
{
    m_percentage = percentage;
}

const double_t& Ingredient::getIngredientQuantity() const noexcept
{
    return m_quantity;
}

void Ingredient::setIngredientQuantity(double_t quantity)
{
    m_quantity = quantity;
}

} // namespace tyc

