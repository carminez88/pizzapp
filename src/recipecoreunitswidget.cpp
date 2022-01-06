#include "recipecoreunitswidget.h"
#include "ui_recipecoreunitswidget.h"

RecipeCoreUnitsWidget::RecipeCoreUnitsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeCoreUnitsWidget)
{
    ui->setupUi(this);

    connect( ui->unitsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &RecipeCoreUnitsWidget::unitsChanged );
    connect( ui->unitWeightSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &RecipeCoreUnitsWidget::unitWeightChanged );
}

RecipeCoreUnitsWidget::~RecipeCoreUnitsWidget()
{
    delete ui;
}

double_t RecipeCoreUnitsWidget::getUnits() const noexcept
{
    return ui->unitsSpinBox->value();
}

double_t RecipeCoreUnitsWidget::getUnitWeight() const noexcept
{
    return ui->unitWeightSpinBox->value();
}

double_t RecipeCoreUnitsWidget::getTotalWeight() const
{
    return ui->unitsSpinBox->value() * ui->unitWeightSpinBox->value();
}
