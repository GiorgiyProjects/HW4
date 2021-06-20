#pragma once

#include <string>
#include <vector>
#include "Events.h"

class Point;
class Shape;
class UserEvent;

/*
 * The idea is to use the pattern Memento and store the system States that you can get back to anytime
 * State class stores all the info that is needed for saving or restoring the work progress
 */

class UserInfo
{
    std::string mUserName;
    std::string mUserId;
    //Other information we need about user and methods to get or set them
};

// Layers like in PhotoShop
class CanvasLayer
{
    std::vector<std::vector<Point*>> mCanvasRGB; // sets of points that defines canvas
    std::vector<Shape*> mShapes; // I am not sure why we need it, but canvas points are actually grouped in shapes by logic.
};

class CanvasInfo
{
    std::vector<CanvasLayer> mLayers;
};

class State
{
    UserInfo mUser;
    CanvasInfo mCanvas;
};

class Model
{
    std::vector<State> StateStack;
public:
    // various methods for working with states
    void SaveStateToFile(std::string filename)
    {
        std::cout << "saving state" << std::endl;
    }
    void LoadStateFromFile(std::string filename);
    void GoBackToPreviousState();
    bool AttachState(State& s);
};