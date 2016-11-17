/**
* Easy-Nurbs
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMdiArea>
#include <QVector>
#include <QMdiSubWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    void resizeEvent(QResizeEvent *);

private slots:

private:
	QMdiArea *m_mdiArea;
	QVector<QMdiSubWindow*> m_subwindows;
};

#endif
