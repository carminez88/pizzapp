#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <cmath>
#include <string>

#include "ingredienttypes.h"

namespace tyc {

class Ingredient
{
public:
    explicit Ingredient(IngredientType_e type, double_t percentage, double_t quantity);

    virtual ~Ingredient() = default;

    Ingredient(const Ingredient&) = default;
    Ingredient& operator=(const Ingredient&) = default;

    Ingredient(Ingredient&&) = default;
    Ingredient& operator=(Ingredient&&) = default;

    const IngredientType_e& getIngredientType() const noexcept;
    void setIngredientType(IngredientType_e type);

    const double_t& getIngredientPercentage() const noexcept;
    void setIngredientPercentage(double_t percentage);

    const double_t& getIngredientQuantity() const noexcept;
    void setIngredientQuantity(double_t quantity);

protected:
    IngredientType_e m_type;
    double_t m_percentage { 0. };
    double_t m_quantity { 0. };
};

} // namespace tyc

#endif // INGREDIENT_H
