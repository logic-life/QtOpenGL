#ifndef WINDOW_H
#define WINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>
#include "transform3d.h"
#include "camera3d.h"
#include "fwdopengl.h"

class Window : public QOpenGLWindow,
               protected QOpenGLFunctions
{
  Q_OBJECT

// OpenGL Events
public:
  Window();
  void initializeGL();
  void resizeGL(int width, int height);
  void paintGL();
protected slots:
  void teardownGL();
  void update();

protected:
  bool event(QEvent *event);
  void errorEventGL(OpenGLError *event);
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);

private:
  // OpenGL State Information
  OpenGLBuffer m_vertex;
  OpenGLVertexArrayObject m_object;
  OpenGLShaderProgram *m_program;

  // Shader Information
  int u_modelToWorld;
  int u_worldToCamera;
  int u_cameraToView;
  QMatrix4x4 m_projection;
  Camera3D m_camera;
  Transform3D m_transform;

  // Private Helpers
  void printVersionInformation();
};

#endif // WINDOW_H
