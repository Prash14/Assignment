#include "MyCanvas.h"

int main(int argc, char** argv)
{
    // Initialize GLUT with command line arguments
    glutInit(&argc, argv);
    // Create a canvas for the coding challenge
    MyCanvas* canvas = new MyCanvas();
    canvas->create(400, 400, "C++ Coding Challenge");
    // Run the GLUT event loop
    glutMainLoop();
    return 0;
}
