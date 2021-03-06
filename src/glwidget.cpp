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

#include "glwidget.h"
#include <QOpenGLTexture>
#include <QCoreApplication>
#include <math.h>
#include "cnurb.h"
#include "mainwindow.h"
#include "teapot.h"

const int bubbleNum = 8;

GLWidget::GLWidget(MainWindow *mw)
    : m_mainWindow(mw)
{
    setMinimumSize(300, 250); // Set widget size
    QVector<QVector3D> points;
    for (int i=0; i<nBottom; i++)
    {
        points.push_back(QVector3D(Vertices[Bottom[i]][0], Vertices[Bottom[i]][1], Vertices[Bottom[i]][2]));
    }
    short p, q;
    QVector<float> U,V;
    p = q = 2;

    m_nurb = new CNurb();
}

GLWidget::~GLWidget()
{

    // And now release all OpenGL resources.
    makeCurrent();
    delete m_program;
    delete m_vshader;
    delete m_fshader;
    m_vbo.destroy();
    doneCurrent();
}


void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    m_vshader = new QOpenGLShader(QOpenGLShader::Vertex);
    m_fshader = new QOpenGLShader(QOpenGLShader::Fragment);
    if (m_vshader->compileSourceFile(QString("shader/passThrough.vert"))
            &&
            m_fshader->compileSourceFile(QString("shader/passThrough.frag")))
    {
        m_vbo.create();
        m_vbo.bind();

        m_vbo.allocate(m_vertices.constData(), m_vertices.count() * sizeof(GLfloat));
        m_vbo.release();

        m_program = new QOpenGLShaderProgram;
        m_program->addShader(m_vshader);
        m_program->addShader(m_fshader);
        m_program->link();
        m_program->bind();
        m_vertexAttr = m_program->attributeLocation("vPosition");
    }
}

void GLWidget::paintGL()
{

    if (m_program->isLinked())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        m_program->enableAttributeArray(m_vertexAttr);
        m_vbo.bind();
        m_program->setAttributeBuffer(m_vertexAttr, GL_FLOAT, 0, 2);
        m_vbo.release();

        glDrawArrays(GL_TRIANGLES, 0, 6);

        m_program->disableAttributeArray(m_vertexAttr);
        glFlush();
    }

}

void GLWidget::resizeGL(int, int)
{

}

