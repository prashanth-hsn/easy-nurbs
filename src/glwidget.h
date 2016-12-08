
/* GlWidget class*/
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QMatrix4x4>
#include <QTime>
#include <QVector>
#include <QPushButton>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>

class MainWindow;

QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)
QT_FORWARD_DECLARE_CLASS(QOpenGLShader)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GLWidget(MainWindow *mw, bool button, const QColor &background);
    ~GLWidget();

protected:
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void initializeGL() Q_DECL_OVERRIDE;

private:
    int m_vertexAttr;
    QOpenGLShader *m_vshader;
    QOpenGLShader *m_fshader;
    QOpenGLShaderProgram *m_program;
    MainWindow *m_mainWindow;
    QOpenGLBuffer m_vbo;
    QVector<GLfloat> m_vertices;
};

#endif
