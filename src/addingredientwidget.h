#ifndef ADDINGREDIENTWIDGET_H
#define ADDINGREDIENTWIDGET_H

#include <QWidget>

#include "ingredient.h"

namespace Ui {
class AddIngredientWidget;
}

class AddIngredientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddIngredientWidget(QWidget *parent = nullptr);
    ~AddIngredientWidget();

Q_SIGNALS:
    void newIngredientToAdd(tyc::Ingredient);

private Q_SLOTS:
    void on_addIngredientPushButtonClicked();

private:
    void loadIngredientsTypes();

private:
    Ui::AddIngredientWidget *ui;
};

#endif // ADDINGREDIENTWIDGET_H
