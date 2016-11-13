// A simple program that computes the square root of a number
#include "easy_nurbs.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "mainwindow.h"
#include <iostream>

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Prakruthi");
    QCoreApplication::setApplicationName("Easy-nurbs");
    QString versionNumber = QString("%1.%2").arg(easy_nurbs_VERSION_MAJOR).arg(easy_nurbs_VERSION_MINOR);
    QCoreApplication::setApplicationVersion(versionNumber);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
//  Add command options here.
    parser.process(app);

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
