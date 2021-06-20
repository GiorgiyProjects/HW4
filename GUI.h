#pragma once

#include<vector>
#include <tuple>
#include "Events.h"
#include "HardwareObjects.h"

/*
 * Widget is every object that defines UI - canvas, buttons. special type of UI object is keyboard. Widgets have size
 * and physical location, tied to the computer screen.
 * Widgets talk to Events. Widget can return a user event, and widgets can be triggered by events
 */

class UserEvent; // Forward declaration to avoid circular dependencies

class Widget
{
protected:
    Rectangle Obj; // locations or left and right boundaries. We assume all widgets are squared

public:
    Widget();
    bool CheckIfHovered(Point P);
    UserEvent* Click();
    UserEvent* Hover();
};

class SaveButton : public Widget
{
public:
    SaveButton();
    UserEvent* Click();
};

class ExportButton : public Widget
{
public:
    ExportButton();
    UserEvent* Click();
};

class ImportButton : public Widget
{
public:
    ImportButton();
    UserEvent* Click();
};

class CreateSquareButton : public Widget
{
public:
    CreateSquareButton();
};

class CreateTriangleButton : public Widget
{
public:
    CreateTriangleButton();
};

class Canvas : public Widget
{
public:
    Canvas();
};

class KeyboardWidget : public Widget
{
public:
    KeyboardWidget();
    UserEvent* KeyboardClick(char c);
};

/*
 * GUI is a class that contains Widgets and can also talk to hardware objects.
 * Hardware objects tell gui everything it needs to know to understand which Widget is triggered
 * The result of GUI's work is UserEvent*, which knows how to talk to other classes.
 *
 */
class GUI {
    std::vector<Widget *> mWidgets;
    KeyboardWidget mKeyboard;
public:
    GUI();
    Widget* GetHoveredWidget(Point mp);
    UserEvent* HardwareEventListen(HardwareObjects& ho);
};
