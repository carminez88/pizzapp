#include <QApplication>

#include "recipecorewidget.h"

int32_t main(int32_t argc, char* argv[])
{
    QApplication a( argc, argv );

    RecipeCoreWidget w;
    w.show();

	return a.exec();
}
