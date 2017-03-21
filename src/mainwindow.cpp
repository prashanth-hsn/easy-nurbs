/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"

#include <QApplication>
#include <QMenuBar>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QScrollArea>
#include <QVBoxLayout>
#include "glwidget.h"


#include <QSlider>

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
	m_mdiArea = new QMdiArea(this);
	m_mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(m_mdiArea);

	QMdiSubWindow *subWindow1 = new QMdiSubWindow;
	m_subwindows.push_back(subWindow1);
	m_mdiArea->addSubWindow(subWindow1);

	QScrollArea *scrollArea = new QScrollArea;
    GLWidget *glwidget = new GLWidget(this);

	subWindow1->setAttribute(Qt::WA_DeleteOnClose);
	subWindow1->setWidget(glwidget);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("E&xit", this, &QWidget::close);
    QMenu *showMenu = menuBar()->addMenu("&Show");
    //showMenu->addAction("Show 3D Logo", glwidget, &GLWidget::setLogo);
    //showMenu->addAction("Show 2D Texture", glwidget, &GLWidget::setTexture);
    //QAction *showBubbles = showMenu->addAction("Show bubbles", glwidget, &GLWidget::setShowBubbles);
    //showBubbles->setCheckable(true);
    //showBubbles->setChecked(true);
    QMenu *helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction("About Qt", qApp, &QApplication::aboutQt);

}



void MainWindow::resizeEvent(QResizeEvent *)
{
	for (QVector<QMdiSubWindow*>::iterator it = m_subwindows.begin();
		it != m_subwindows.end();
		it++)
		(*it)->setMinimumSize(size() - QSize(10, 10));

}
