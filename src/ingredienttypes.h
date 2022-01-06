#ifndef INGREDIENTTYPES_H
#define INGREDIENTTYPES_H

#include "enum.h"

namespace tyc {

BETTER_ENUM(IngredientType_e, uint8_t, Flour, Water, Salt, Yeast, Fat, Misc)

//enum class IngredientType_e {
//    Flour,
//    Water,
//    Salt,
//    Yeast,
//    Fat,
//    Add
//};

enum class FlourType_e {
    GenericFlour,
    BreadFlour,
    Type00Flour,
    Type1Flour,
    Type2Flour,
    WholemealFlour,
    RyeFlour,
    SpeltFlour,
    EnkirFlour,
    BuckwheatFlour,
    MixedTypesFlour,
};

} // namespace tyc

#endif // INGREDIENTTYPES_H
