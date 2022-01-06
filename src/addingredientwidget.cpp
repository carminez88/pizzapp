#include "addingredientwidget.h"
#include "ui_addingredientwidget.h"

AddIngredientWidget::AddIngredientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddIngredientWidget)
{
    ui->setupUi(this);

    loadIngredientsTypes();

    connect( ui->addIngredientPushButton, &QPushButton::clicked, this, &AddIngredientWidget::on_addIngredientPushButtonClicked );
}

AddIngredientWidget::~AddIngredientWidget()
{
    delete ui;
}

void AddIngredientWidget::on_addIngredientPushButtonClicked()
{
    auto type = tyc::IngredientType_e::_from_string( ui->ingredientsComboBox->currentText().toStdString().c_str() );
    auto quantityPercentage = ui->ingredientQuantityDoubleSpinBox->value();

    Q_EMIT newIngredientToAdd( tyc::Ingredient( type, quantityPercentage, 0. ) );

    close();
}

void AddIngredientWidget::loadIngredientsTypes()
{
    for ( const auto& t : tyc::IngredientType_e::_values() )
        ui->ingredientsComboBox->addItem( t._to_string() );
}
