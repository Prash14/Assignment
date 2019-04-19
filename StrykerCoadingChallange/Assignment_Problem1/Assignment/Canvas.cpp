
#include "Canvas.h"
#include <cmath>

std::unique_ptr<Canvas> Canvas::_instance;

Canvas::Canvas()
: _width(0)
, _height(0)
{
}

Canvas::~Canvas()
{
}

void Canvas::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::swapBuffers()
{
    glutSwapBuffers();
}

void Canvas::drawPoint(GLint cx, GLint cy, GLubyte red, GLubyte green, GLubyte blue)
{
    cy = _height - cy;
    glColor3ub(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2f(cx + 0.5f, cy + 0.5f);
    glEnd();
}

void Canvas::drawCircle(GLint cx, GLint cy, GLuint radius, GLubyte red, GLubyte green, GLubyte blue)
{
    static const int numSlices = 72;
    static const GLfloat deltaAngle = 2.0f * std::atan2f(0.0f, -1.0f) / numSlices;
    cy = _height - cy;
    glColor3ub(red, green, blue);
    glBegin(GL_LINE_LOOP);
    GLfloat angle = 0.0f;
    for (int i = 0; i < numSlices; ++i, angle += deltaAngle) {
        glVertex2f(cx + 0.5f + radius * std::cosf(angle), cy + 0.5f + radius * std::sinf(angle));
    }
    glEnd();
}

void Canvas::refresh()
{
    glutPostRedisplay();
}

void Canvas::reshape(GLuint width, GLuint height)
{
    _width = width;
    _height = height;
    glViewport(0, 0, _width, _height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, _width, 0, _height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

Canvas& Canvas::GetInstance()
{
    return *_instance.get();
}

void Canvas::SetInstance(Canvas* instance)
{
    _instance.reset(instance);
}

void DisplayFunc()
{
    Canvas::GetInstance().display();
}

void ReshapeFunc(int width, int height)
{
    Canvas::GetInstance().reshape(width, height);
}

void MouseFunc(int button, int state, int x, int y)
{
    Canvas::GetInstance().onMouseButton(button, state, x, y);
}


void KeyboardFunc(unsigned char key, int x, int y)
{
    Canvas::GetInstance().onKeyboard(key, x, y);
}

void Canvas::create(GLuint width, GLuint height, const std::string& title)
{
    static const GLfloat pointSize = 10.0f;
    static const GLfloat lineWidth = 1.3f;
    static const GLfloat backColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    _width = width;
    _height = height;
    glutInitWindowSize(_width, _height);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(title.c_str());
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glClearColor(backColor[0], backColor[1], backColor[2], backColor[3]);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(pointSize);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(lineWidth);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(DisplayFunc);
    glutReshapeFunc(ReshapeFunc);
    glutKeyboardFunc(KeyboardFunc);
    glutMouseFunc(MouseFunc);
	//gultMotionFunc(MouseMotion);
    Canvas::SetInstance(this);
}
