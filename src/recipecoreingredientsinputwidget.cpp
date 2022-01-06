#include "addingredientwidget.h"
#include "recipecoreingredientsinputwidget.h"
#include "ui_recipecoreingredientsinputwidget.h"

RecipeCoreIngredientsInputWidget::RecipeCoreIngredientsInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeCoreIngredientsInputWidget)
{
    ui->setupUi(this);

    QHeaderView* header = ui->ingredientsTableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    connect( ui->addIngredientPushButton, &QPushButton::clicked, this, &RecipeCoreIngredientsInputWidget::on_addIngredientPushButtonClicked );
}

RecipeCoreIngredientsInputWidget::~RecipeCoreIngredientsInputWidget()
{
    delete ui;
}

void RecipeCoreIngredientsInputWidget::setModel(QAbstractTableModel *model)
{
    auto currentModel = ui->ingredientsTableView->model();

    if ( currentModel != model )
        ui->ingredientsTableView->setModel( model );

    ui->ingredientsTableView->update();
}

void RecipeCoreIngredientsInputWidget::on_addIngredientPushButtonClicked()
{
    auto* widget = new AddIngredientWidget;
    connect( widget, &AddIngredientWidget::newIngredientToAdd, this, &RecipeCoreIngredientsInputWidget::newIngredientToAdd );
    widget->show();
}
