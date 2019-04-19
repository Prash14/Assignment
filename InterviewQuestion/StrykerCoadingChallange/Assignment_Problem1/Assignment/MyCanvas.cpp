
#include "MyCanvas.h"
#include <iostream>
using namespace std;

MyCanvas::MyCanvas():PixSize(20), StartPixPos(10)
{
	/* Initiallize Default Circle obj */
	cir.start_x = 0;
	cir.start_y = 0;
	cir.radius = 0;
	/* Initiallize Default MousePosition & state*/
	mousePos.state = false;
	mousePos.pos_x = 0;
	mousePos.pos_y = 0;
	/*Default grid display*/
	default_display = true;
}

MyCanvas::~MyCanvas()
{
}

void MyCanvas::createDottedGrid()
{
	/* create grid with dotted in grey */
	for (int pt_x = StartPixPos; pt_x < WIDGET::WiSize; pt_x +=PixSize)
	{
		for (int pt_y = StartPixPos; pt_y < WIDGET::WiSize; pt_y += PixSize)
		{
			if (default_display)
			{
				/* Draw a grey point when flag is false the canvas */
				drawPoint(pt_x, pt_y, 127, 127, 127);
			}
			else
			{
				/* Draw a grey point when flag is true the canvas */
				double radDiffLow = (cir.radius - PixSize);
				double radDiffHigh = (cir.radius + PixSize);
				double distCircles = sqrt(pow((pt_x - cir.start_x),2) + pow((pt_y - cir.start_y),2));
				if (radDiffLow <= distCircles && radDiffHigh >= distCircles)
				{
					/*Draw Blue point*/
					drawPoint(pt_x, pt_y, 0, 0, 127);
				}
				else
				{
					drawPoint(pt_x, pt_y, 127, 127, 127);
				}
			}			
		}
	}
}

void MyCanvas::display()
{
    // Clear the canvas
    clear();

	/* Default Grid with grey dot*/
	createDottedGrid();
	  
    // Draw a 3 circles on the canvas if the mouse is released
	if (default_display == false)
	{
		/* Draw a blue circle on the canvas below & above, Two make dark create three circle near by. */
		drawCircle(cir.start_x, cir.start_y, cir.radius -1, 0, 0, 127);
		drawCircle(cir.start_x, cir.start_y, cir.radius   , 0, 0, 127);
		drawCircle(cir.start_x, cir.start_y, cir.radius +1, 0, 0, 127);

		/* Draw a red circle on the canvas below & above, since it is Light no need to create extra crcle */
		drawCircle(cir.start_x, cir.start_y, cir.radius + PixSize, 127, 0, 0);
		drawCircle(cir.start_x, cir.start_y, cir.radius - PixSize, 127, 0, 0);
	}
   
	// -------------------------------------------------------------------------------------------
    // Make changes appear on screen
    swapBuffers();
}


void MyCanvas::MousePressed(WIDGET::M_mouse& m_mouse)
{

	if (m_mouse.state == GLUT_DOWN)
	{
		/* Left key pressed, store this point as origin*/
		cir.start_x = mousePos.pos_x;
		cir.start_y = mousePos.pos_y;
		cout << "Canvas::Circle origin " << cir.start_x << ", " << cir.start_y << endl;
	}
	else
	{
		/* Left key released , store this point and calualte radius*/
		default_display = false;
		double end_x = mousePos.pos_x;
		double end_y = mousePos.pos_y;

		/* If mouse click outside the widget no need to make circle*/
		if (end_x > WIDGET::WiSize ||
			end_y > WIDGET::WiSize)
		{
			default_display = true;
		}
		else
		{
			/* Calculate Radius of circle*/
			cir.radius = sqrt(pow((end_x - cir.start_x), 2) + pow((end_y - cir.start_y), 2));

			cout << "Canvas::Circle create with radius " << cir.radius << endl;
			/* Check the boundary condition for the cicle*/

			if ((((cir.start_x - cir.radius)+PixSize == 0) &&
				(cir.start_y - cir.radius + PixSize == 0)) &&
			   ((cir.start_x + cir.radius + PixSize == WIDGET::WiSize) &&
				(cir.start_y + cir.radius + PixSize == WIDGET::WiSize)))
			{
				cir.radius -= PixSize;
			}			
			else if ((((cir.start_x - cir.radius) > 0) &&
				(cir.start_y - cir.radius  > 0)) &&
				((cir.start_x + cir.radius  < WIDGET::WiSize) &&
				(cir.start_y + cir.radius  < WIDGET::WiSize)))
			{
				/* Do nothing*/
			}
			else
			{
				cout << "Radius is higher " << endl;
				default_display = true;
			}		

			if (cir.radius == 0)
			{
				cout << "Canvas::Circle Radius is too small " << endl;
				default_display = true;
			}
		}
		display();		
	}

}


void MyCanvas::onMouseButton(int button, int state, int x, int y)
{
	/* Recreate the dot and remove circle when ever mouse is clicked*/
	default_display = true;
	display();
    // Process mouse button events.
    switch (button) {
    case GLUT_LEFT_BUTTON:
        std::cout << "Canvas::onMouseButton: " << state << ", " << x << ", " << y << std::endl;
		mousePos.state = state;
		mousePos.pos_x = x;
		mousePos.pos_y = y;

		MousePressed(mousePos);
		break;
    default:
        break;
    }
    refresh();
}

void MyCanvas::onKeyboard(unsigned char key, int x, int y)
{
    // Process keyboard events.
    std::cout << "Canvas::onKeyboard: '" << key << "', " << x << ", " << y << std::endl;
    switch (key) {
    case 27: // ESC
        exit(0);
        break;
    default:
        break;
    }
    refresh();
}
