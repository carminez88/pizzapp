#ifndef RECIPECOREINGREDIENTSINPUTWIDGET_H
#define RECIPECOREINGREDIENTSINPUTWIDGET_H

#include <QWidget>
#include <QAbstractTableModel>

#include "ingredient.h"

namespace Ui {
class RecipeCoreIngredientsInputWidget;
}

class RecipeCoreIngredientsInputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeCoreIngredientsInputWidget(QWidget *parent = nullptr);
    ~RecipeCoreIngredientsInputWidget();

    void setModel(QAbstractTableModel* model);

Q_SIGNALS:
    void newIngredientToAdd(tyc::Ingredient);

public Q_SLOTS:
    void on_addIngredientPushButtonClicked();

private:
    Ui::RecipeCoreIngredientsInputWidget *ui;
};

#endif // RECIPECOREINGREDIENTSINPUTWIDGET_H
