#include "Canvas.h"
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height)
{
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			Matrix[i][j] = ' ';
		}
	}
	h = height;
	w = width;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int dx=4;
	for (int i = x-ray;i <=x+ray;i++)
	{
		for (int j = y-ray;j <= y+ray;j++)
		{
			if (ray == 2 or ray == 3 or ray == 4)
			{
				dx = 1;
			}
			if (pow(i-x,2)+pow(j-y,2)==pow(ray,2) or pow(i - x, 2) + pow(j - y, 2) == pow(ray, 2)-dx or pow(i - x, 2) + pow(j - y, 2) == pow(ray, 2)+x)
			{
				Matrix[i][j] = ch;
			}

		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = x - ray;i <= x + ray;i++)
	{
		for (int j = y - ray;j <= y + ray;j++)
		{
			int dx = 1;
			if (pow(i - x, 2) + pow(j - y, 2) <= pow(ray, 2))
			{
				Matrix[i][j] = ch;
			}

		}
	}

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++)
	{
		for (int j = left;j <= right;j++)
		{
			if (i == top or j == left or i == bottom or j == right)
			{
				Matrix[i][j] = ch; 
			}
		}
	}
}


void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++)
	{
		for (int j = left;j <= right;j++)
		{
			if (i > top or j > left or i < bottom or j < right)
			{
				Matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	Matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, p, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;

	x = x1;
	y = y1;


	while (x < x2)
	{
		if (p >= 0)
		{
			Matrix[x][y] = ch;
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			Matrix[x][y] = ch;
			p = p + 2 * dy;
		}
		x++;
	}
}

void Canvas::Print()
{
	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			Matrix[i][j] = ' ';
		}
	}
}








