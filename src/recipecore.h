#ifndef RECIPECORE_H
#define RECIPECORE_H

#include <QAbstractTableModel>
#include <cstdint>
#include <vector>

#include "ingredient.h"

namespace tyc {

class RecipeCore : public QAbstractTableModel
{
    using Ingredients = std::vector<Ingredient>;
    class Header
    {
    public:
        enum class HeaderColumns
        {
            Ingredient          = 0,
            QuantityPercentage  = 1,
            QuantityWeight      = 2
        };

        static QStringList headerData()
        {
            return k_headerData;
        }

        static size_t headerSize()
        {
            return k_headerData.size();
        }

        static QString at(int32_t index)
        {
            return k_headerData.at( index );
        }

        inline static const QStringList k_headerData = { "Ingredient", "Quantity [%]", "Quantity [g]" };
    };
public:
    explicit RecipeCore() = default;

    ~RecipeCore() override = default;

    bool validate() const;

    void setUnits(int32_t units);

    void setUnitWeight(int32_t weight);

    void addIngredient(Ingredient ingredient);

    int32_t rowCount(const QModelIndex& a_parent = QModelIndex()) const override;

    int32_t columnCount(const QModelIndex& a_parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& a_index, int32_t a_role = Qt::DisplayRole) const override;

    QVariant headerData(int32_t a_section, Qt::Orientation a_orientation, int32_t a_role = Qt::DisplayRole) const override;

private:
    template<IngredientType_e::_integral ingredientType>
    int32_t checkIngredientQuantity() const;

    bool checkIngredientsUniqueness() const;

    bool checkPresenceCoreIngredients() const;

    void recalcQuantities();

private:
    int32_t m_units { 1 };
    int32_t m_unitWeight { 1000 };
    Ingredients m_ingredients;
};

} // namespace tyc

#endif // RECIPECORE_H
