#include<vector>
#include<iostream>
/*
 * This file ill contain classes for virtual graphical objects, like Points, Lines, Circles and so on
 */

struct Point
{
    int x,y; //coords
    int r,g,b; // color
    double opacity;
    // other ifo we need about points
};


/*
 * We use shapes in two ways.
 * 1) Do define what is drawn on a Canvas widget layer
 * 2) for GUI to draw all the buttons. For GUI to draw the canvas
 */
struct Shape
{
public:
    bool mIsComplete; // a way to know if we already finished that shape or are still drawing
    std::vector<Point*> mPoints; // shape does not store points itself - only pointers to them. Shape is a logical grouping of points, but not a 'physical' object itself
};

struct Rectangle : public Shape
{
    std::vector<Point*> mCornerPoints;
    int mXl,mYl, mXr, mYr;

public:
    void SetShapeDimensions()
    {
        std::cout << "here we set xl, xr, yl, yr from corner points of the shape is finished" << std::endl;
    }

    bool Contains (Point p)
    {
        return ((p.x >= mXl) && (p.x < mXr)) && ((p.y >= mYl) && (p.y < mYr));
    }

    Rectangle(int xl = 0, int yl = 0, int xr = 0, int yr = 0):
    mXl(xl), mYl(yl), mXr(xr), mYr(yr)
    {
        mIsComplete = true;
        mPoints.resize((xr - xl) * (yr - yl)); // hardcode screen size for now
        // set mPoints array
    }
    // other options for constructor might no set IsCOmplete to true.

};

// similar way we define triangle, circle, polygon and others