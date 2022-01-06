#ifndef FLOUR_H
#define FLOUR_H

#include "ingredient.h"

namespace tyc {

class Flour : public Ingredient
{
public:
    explicit Flour(IngredientType_e type, double_t percentage, double_t quantity, FlourType_e flourType, std::string flourName);

    ~Flour() override = default;

    Flour(const Flour&) = default;
    Flour& operator=(const Flour&) = default;

    const FlourType_e& getFlourType() const noexcept;

    const std::string& getFlourName() const noexcept;

private:
    FlourType_e m_flourType;
    std::string m_flourName;
};

} // namespace tyc

#endif // FLOUR_H
