#pragma once

#include<algorithm>
#include <string>
#include<map>
#include <tuple>
#include "Primitives.h"

/*
 * Just a primitive keyboard class, that generates random events and models work of user keyboard
 */
class Keyboard
{
    std::string mAlphabet = "abcdefghijklmnopqrstuvwxyz01234567890";
    std::map<char, bool> mIsClicked;
public:
    Keyboard();
    void GenerateRandomClick();
    void BackToDefault();
    char GetClickedKey();
};

class Mouse
{
    Point mPos; // in pixels
    bool mButtonClicked = false;

public:
    Mouse() = default;
    void GenerateRandomClick();
    void GenerateRandomMove();
    void BackToDefault();
    Point GetMousePos();
};

/* This is a class containing all the hardware objects - mouse, keyboard
 * Talks to GUI gives commands to it
 * */
class HardwareObjects
{
    bool mIsMouseMoved = false;
    bool mIsMouseClicked = false;
    bool mIsKeyboardClicked = false;
    Keyboard mKB;
    Mouse mM;

public:
    HardwareObjects() = default;

    bool MouseSignal();

    bool MouseClick();
    bool MouseMove();

    Point GetMousePosition();
    bool KeyboardSignal();
    char GetClickedKey();
    void CreateRandomEvent();
    void BackToDefault();

};