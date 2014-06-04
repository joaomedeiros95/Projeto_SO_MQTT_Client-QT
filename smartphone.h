#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <QGLWidget>
#include <QtOpenGL>

class Smartphone : public QGLWidget
{
    Q_OBJECT
public:
//    explicit Smartphone(QObject *parent = 0);
    Smartphone(QWidget *parent = NULL)
            : QGLWidget(parent) {}
    void setX(float value);
    void setY(float value);
    void setZ(float value);

signals:

public slots:

protected:
    // Set up the rendering context, define display lists etc.:
    void initializeGL();
    // draw the scene:
    void paintGL();
    // setup viewport, projection etc.:
    void resizeGL (int width, int height);
    // set the rotate of cube
    float rotValue_X;
    float rotValue_Y;
    float rotValue_Z;
};

#endif // SMARTPHONE_H
