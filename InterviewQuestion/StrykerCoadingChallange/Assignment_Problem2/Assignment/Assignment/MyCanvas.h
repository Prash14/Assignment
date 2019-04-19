#ifndef MyCanvas_h
#define MyCanvas_h

#include "Canvas.h"
using namespace std;

namespace WIDGET
{
	typedef struct MyPoint {
		float x;
		float y;
	};
	const int SIZE = 20;
	const int WiSize = 400;
};

class MyCanvas : public Canvas
{
private:
	bool myCanvasGrid[WIDGET::SIZE][WIDGET::SIZE];
	WIDGET::MyPoint myCircleCenter;
	int myCircleRadius;     // Radius of circle
	bool myDrawCircle;      // Flag is set for creation of circle when the 'g' or 'G' is pressed.
	bool myDrawEllipse;     // Flag is set for creation of ecplise when the 'g' or 'G' is pressed.
	bool myGridClear;       // Flag to clear grid, sets when 'c' is pressed

	/*One Dot contains 20 points to make them visible*/
	const int PixSize;
	const int StartPixPos;
	int myEllipseWidth;
	int myEllipseHeight;

public:
    MyCanvas();
    virtual ~MyCanvas();
    void display() override;
    void onKeyboard(unsigned char key, int x, int y) override;
    void onMouseButton(int button, int state, int x, int y) override;
	void createDottedGrid();

	void MyCanvas::findMaxSum(bool M[][WIDGET::SIZE]);
	int MyCanvas::kadane(int* arr, int* start, int* finish, int n);
	
};

#endif // MyCanvas_h
