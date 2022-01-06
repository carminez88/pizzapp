#ifndef RECIPECOREUNITSWIDGET_H
#define RECIPECOREUNITSWIDGET_H

#include <QWidget>

#include <cmath>

namespace Ui {
class RecipeCoreUnitsWidget;
}

class RecipeCoreUnitsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeCoreUnitsWidget(QWidget *parent = nullptr);
    ~RecipeCoreUnitsWidget() override;

    double_t getUnits() const noexcept;

    double_t getUnitWeight() const noexcept;

    double_t getTotalWeight() const;

Q_SIGNALS:
    void unitsChanged(int32_t);

    void unitWeightChanged(int32_t);

private:
    Ui::RecipeCoreUnitsWidget *ui;
};

#endif // RECIPECOREUNITSWIDGET_H
