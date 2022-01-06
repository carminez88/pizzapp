#include "recipecorewidget.h"
#include "ui_recipecorewidget.h"

RecipeCoreWidget::RecipeCoreWidget(QWidget *parent)
    : QWidget      ( parent                   )
    , ui           ( new Ui::RecipeCoreWidget )
    , m_recipeCore ( new tyc::RecipeCore      )
{
    ui->setupUi(this);

    connect( ui->unitsWidget, &RecipeCoreUnitsWidget::unitsChanged, this, &RecipeCoreWidget::on_unitsChanged );
    connect( ui->unitsWidget, &RecipeCoreUnitsWidget::unitWeightChanged, this, &RecipeCoreWidget::on_unitWeightChanged );
    connect( ui->ingredientsWidget, &RecipeCoreIngredientsInputWidget::newIngredientToAdd, this, &RecipeCoreWidget::on_newIngredientToAdd );

    ui->ingredientsWidget->setModel( m_recipeCore );

    on_unitsChanged( ui->unitsWidget->getUnits() );
    on_unitWeightChanged( ui->unitsWidget->getUnitWeight() );
}

RecipeCoreWidget::~RecipeCoreWidget()
{
    delete ui;
}

void RecipeCoreWidget::on_unitsChanged(int32_t units)
{
    m_recipeCore->setUnits( units );
}

void RecipeCoreWidget::on_unitWeightChanged(int32_t unitWeight)
{
    m_recipeCore->setUnitWeight( unitWeight );
}

void RecipeCoreWidget::on_newIngredientToAdd(tyc::Ingredient ingredient)
{
    m_recipeCore->addIngredient( std::move( ingredient ) );
}
