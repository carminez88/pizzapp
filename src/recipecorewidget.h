#ifndef RECIPECOREWIDGET_H
#define RECIPECOREWIDGET_H

#include <QWidget>

#include "recipecore.h"

namespace Ui {
class RecipeCoreWidget;
}

class RecipeCoreWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeCoreWidget(QWidget *parent = nullptr);
    ~RecipeCoreWidget();

private Q_SLOTS:
    void on_unitsChanged(int32_t units);

    void on_unitWeightChanged(int32_t unitWeight);

    void on_newIngredientToAdd(tyc::Ingredient ingredient);

private:
    Ui::RecipeCoreWidget *ui;
    tyc::RecipeCore* m_recipeCore { nullptr };
};

#endif // RECIPECOREWIDGET_H
