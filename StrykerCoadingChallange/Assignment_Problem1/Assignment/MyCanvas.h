#ifndef MyCanvas_h
#define MyCanvas_h

#include "Canvas.h"

namespace WIDGET
{
	const int WiSize = 400;
	
	/* Mouse Object: used to store the state & Position on Grid*/
	typedef struct M_mouse
	{
		bool state;
		double pos_x;
		double pos_y;
	};

	/* Circle Object : Contains origin as (start_x,start_y)
	Radius : radius
	*/
	typedef struct circle
	{
		double start_x;
		double start_y;
		double radius;
	};
};


class MyCanvas : public Canvas
{
public:
    MyCanvas();
    virtual ~MyCanvas();
    void display() override;
    void onKeyboard(unsigned char key, int x, int y) override;
    void onMouseButton(int button, int state, int x, int y) override;
	
	void createDottedGrid();
	void MousePressed(WIDGET::M_mouse& m_mouse);
		
private:
	bool default_display;
	WIDGET::circle cir;
	WIDGET::M_mouse mousePos;
	
	/*One Dot contains 20 points to make them visible*/
	const int PixSize;
	const int StartPixPos;
};

#endif // MyCanvas_h
