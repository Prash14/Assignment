
#include "MyCanvas.h"
#include <iostream>

MyCanvas::MyCanvas():PixSize(20), StartPixPos(10)
{
	myCircleRadius = 0;
	myDrawCircle = false;
	myGridClear = false;
	myCircleCenter.x = 0;
	myCircleCenter.y = 0;
	myEllipseWidth = 0;
	myEllipseHeight	= 0;

	for (int i = 0; i < WIDGET::SIZE; i++)
	{
		for (int j = 0; j < WIDGET::SIZE; j++)
		{
			myCanvasGrid[i][j] = false;
		}
	}

}

MyCanvas::~MyCanvas()
{
}

/*
FUNCTION NAME: createDottedGrid
Description: It creates the Default Grid with toggel dots, on first click the dots changed to BLUE color.
On the second click it again moves back to GRAY color.
*/

void MyCanvas::createDottedGrid()
{
	/* create grid with dotted in grey */
	for (int pt_x = StartPixPos , i = 0; pt_x < WIDGET::WiSize; pt_x += PixSize,i++)
	{
		for (int pt_y = StartPixPos, j = 0; pt_y < WIDGET::WiSize; pt_y += PixSize, j++)
		{
			if (!myCanvasGrid[i][j] || myGridClear)
				drawPoint(pt_x, pt_y, 127, 127, 127); //If already selected Deselect the same ie make GRAY Dot
			else
				drawPoint(pt_x, pt_y, 0, 0, 127);  // BLUE DOT when it is selected first time
		}
	}
}


void MyCanvas::display()
{
    // Clear the canvas
    clear();

	createDottedGrid();

	if (myDrawCircle) /* 'G' or 'g' is Pressed create Red Circle */
		drawCircle(myCircleCenter.x, myCircleCenter.y, myCircleRadius, 127, 0, 0);

	if (myDrawEllipse) /* 'E' or 'e' is Pressed create Green Circle*/
		drawEllipse(myCircleCenter.x, myCircleCenter.y, myEllipseWidth, myEllipseHeight, 0, 127, 0);
	
    // -------------------------------------------------------------------------------------------
    // Make changes appear on screen
    swapBuffers();
}

void MyCanvas::onMouseButton(int button, int state, int x, int y)
{
	int i, j;
	WIDGET::MyPoint apoint;
    // Process mouse button events.
    switch (button) {
    case GLUT_LEFT_BUTTON:
		if (state == 0)
		{
			myGridClear = false;
			myDrawCircle = false;
			myDrawEllipse = false;
			cout << "Canvas::onMouseButton: " << state << ", " << x << ", " << y << std::endl;
			/* Snce one DOT contains 20 pixcel, below eqaution convert pixcel value to dot */
			apoint.x = x - x % 20 + 10;
			apoint.y = y - y % 20 + 10;
			i = apoint.x / 20;
			j = apoint.y / 20;
			myCanvasGrid[i][j] = myCanvasGrid[i][j] ? false : true;
			cout << "Grid Point" << i << " " << j <<std::endl;
		}
        break;
    default:
        break;
    }
    refresh();
}

void MyCanvas::onKeyboard(unsigned char key, int x, int y)
{
    // Process keyboard events.
    cout << "Canvas::onKeyboard: '" << key << "', " << x << ", " << y << std::endl;
    switch (key) {
    case 27: // ESC
        exit(0);
        break;
	case 'g':
	case 'G':
		findMaxSum(myCanvasGrid);
		myDrawCircle = true;
		myDrawEllipse = false;
		break;
	case 'c':
	case 'C':
		memset(myCanvasGrid, false, sizeof(myCanvasGrid[0][0]) * WIDGET::SIZE * WIDGET::SIZE);
		myDrawCircle = false;
		myDrawEllipse = false;
		myGridClear = true;
		break;
	case 'e':
	case 'E':
		findMaxSum(myCanvasGrid);
		myDrawCircle = false;
		myDrawEllipse = true;
		break;
    default:
        break;
    }
    refresh();
}

// Implementation of Kadane's algorithm for 1D array. The function 
// returns the maximum sum and stores starting and ending indexes of the 
// maximum sum subarray at addresses pointed by start and finish pointers 
// respectively.
int MyCanvas::kadane(int* arr, int* start, int* finish, int n)
{
	// initialize sum, maxSum and
	int sum = 0, maxSum = INT_MIN, i;

	// Just some initial value to check for all negative values case
	*finish = -1;

	// local variable
	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	// There is at-least one non-negative number
	if (*finish != -1)
		return maxSum;

	// Special Case: When all numbers in arr[] are negative
	maxSum = arr[0];
	*start = *finish = 0;

	// Find the maximum element in array
	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

// The main function that finds maximum sum rectangle in M[][]
void MyCanvas::findMaxSum(bool MM[][WIDGET::SIZE])
{
	int M[WIDGET::SIZE][WIDGET::SIZE];
	for (int i=0; i < WIDGET::SIZE; ++i)
		for (int j = 0; j < WIDGET::SIZE; ++j)
			M[i][j] = MM[j][i] ? 1 : -40;

	// Variables to store the final output
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

	int left, right, i;
	int temp[WIDGET::SIZE], sum, start, finish;

	// Set the left column
	for (left = 0; left < WIDGET::SIZE; ++left)
	{
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));

		// Set the right column for the left column set by outer loop
		for (right = left; right < WIDGET::SIZE; ++right)
		{
			// Calculate sum between current left and right for every row 'i'
			for (i = 0; i < WIDGET::SIZE; ++i)
				temp[i] += M[i][right];

			// Find the maximum sum subarray in temp[]. The kadane() 
			// function also sets values of start and finish.  So 'sum' is 
			// sum of rectangle between (start, left) and (finish, right) 
			//  which is the maximum sum with boundary columns strictly as
			//  left and right.
			sum = kadane(temp, &start, &finish, WIDGET::SIZE);

			// Compare sum with maximum sum so far. If sum is more, then 
			// update maxSum and other output values
			if (sum > maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	// Print final values
	myCircleRadius = (finalBottom - finalTop) > (finalRight - finalLeft) ? (finalRight - finalLeft) * 10 : (finalBottom - finalTop) * 10;
	myCircleCenter.y = (finalTop + finalBottom + 1) * 10; //(y1+y2)/2 Mid point x co-ordinate
	myCircleCenter.x = (finalLeft + finalRight + 1) * 10; //(x1+x2)/2 Mid point y co-ordinate
	myEllipseWidth = (finalBottom - finalTop) * 7; /* instead of 10 here multiplication factor for eclipse is 7 as center is not at focus*/
	myEllipseHeight = (finalRight - finalLeft) * 7;
}