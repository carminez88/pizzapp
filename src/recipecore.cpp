#include <algorithm>
#include <map>
#include <iostream>

#include "recipecore.h"

namespace tyc {

bool RecipeCore::validate() const
{
    bool isValid { true };

    isValid &= checkPresenceCoreIngredients();
    isValid &= checkIngredientsUniqueness();
    isValid &= m_units > 0;
    isValid &= m_unitWeight > 0;

    return isValid;
}

void RecipeCore::setUnits(int32_t units)
{
    m_units = units;

    recalcQuantities();
}

void RecipeCore::setUnitWeight(int32_t weight)
{
    m_unitWeight = weight;

    recalcQuantities();
}

void RecipeCore::addIngredient(Ingredient ingredient)
{
    const int32_t newRow = m_ingredients.size();
    beginInsertRows( QModelIndex(), newRow, newRow );
    m_ingredients.emplace_back( std::move( ingredient ) );
    endInsertRows();

    recalcQuantities();
}

int32_t RecipeCore::rowCount(const QModelIndex &a_parent) const
{
    Q_UNUSED( a_parent )

    return static_cast<int32_t>( m_ingredients.size() );
}

int32_t RecipeCore::columnCount(const QModelIndex &a_parent) const
{
    Q_UNUSED( a_parent )

    return Header::headerSize();
}

QVariant RecipeCore::data(const QModelIndex &a_index, int32_t a_role) const
{
    const int32_t l_row = a_index.row();
    const int32_t l_column = a_index.column();

    const bool l_invalid = ( not a_index.isValid() ) or ( a_index.row() >= static_cast<int32_t>( rowCount() ) );

    if ( l_invalid )
        return QVariant();

    if ( a_role == Qt::DisplayRole ) {

        const auto& ingredient = m_ingredients.at( l_row );

        auto columnEnumIdx = static_cast<Header::HeaderColumns>( l_column );

        switch ( columnEnumIdx ) {

        case Header::HeaderColumns::Ingredient:
            return QVariant( QString( ingredient.getIngredientType()._to_string() ) );
            break;

        case Header::HeaderColumns::QuantityPercentage:
            return QVariant( QString::number( ingredient.getIngredientPercentage(),'f', 2 ) );
            break;

        case Header::HeaderColumns::QuantityWeight:
            return QVariant( QString::number( ingredient.getIngredientQuantity(), 'f', 2 ) );
            break;

        }

    }

    return QVariant();
}

QVariant RecipeCore::headerData(int32_t a_section, Qt::Orientation a_orientation, int32_t a_role) const
{
    return ( a_role == Qt::DisplayRole && a_orientation == Qt::Horizontal ) ? QVariant( Header::at( a_section ) ) : QVariant();
}

template<IngredientType_e::_integral ingredientType>
int32_t RecipeCore::checkIngredientQuantity() const
{
    return std::count_if( m_ingredients.cbegin(), m_ingredients.cend(), [](const auto& ingredient){ return ingredient.getIngredientType() == ingredientType; } );
}

bool RecipeCore::checkIngredientsUniqueness() const
{
    std::vector<IngredientType_e> types;

    for ( const auto& i : m_ingredients )
        types.emplace_back( i.getIngredientType() );

    std::sort( types.begin(), types.end() );

    const auto duplicate = std::adjacent_find( types.begin(), types.end() );

    return ( duplicate == types.end() );
}

bool RecipeCore::checkPresenceCoreIngredients() const
{
    bool l_checked = checkIngredientQuantity<IngredientType_e::Flour>() > 0;
    l_checked &= checkIngredientQuantity<IngredientType_e::Water>() > 0;
    l_checked &= checkIngredientQuantity<IngredientType_e::Salt>() > 0;
    l_checked &= checkIngredientQuantity<IngredientType_e::Yeast>() > 0;

    return l_checked;
}

void RecipeCore::recalcQuantities()
{
    const double_t totalWeight = m_units * m_unitWeight;

    double_t sum ( 1. );

    for ( const auto& i : m_ingredients )
        if ( i.getIngredientType()._value != IngredientType_e::Flour )
            sum += i.getIngredientPercentage() / 100.;

    const double_t flourTotal = totalWeight / sum;

    for ( auto& i : m_ingredients ) {
        if ( i.getIngredientType()._value == IngredientType_e::Flour )
            i.setIngredientQuantity( flourTotal );
        else
            i.setIngredientQuantity( i.getIngredientPercentage() * flourTotal / 100. );
    }

    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex( rowCount(), 0 );
    Q_EMIT dataChanged( topLeft, bottomRight );
}

} // namespace tyc
