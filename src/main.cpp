// A simple program that computes the square root of a number
#include "easy_nurbs.h"

#include <QApplication>
#include <QMainWindow>
#include <QSurfaceFormat>
#include "mainwindow.h"

int main( int argc, char ** argv )
{
//    Q_INIT_RESOURCE(texture);
    QApplication a( argc, argv );

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    if (QCoreApplication::arguments().contains(QStringLiteral("--multisample")))
        format.setSamples(4);
    QSurfaceFormat::setDefaultFormat(format);

    MainWindow mw;
    mw.showMaximized();
    return a.exec();
}
