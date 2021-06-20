#pragma once

#include<string>
#include <iostream>
#include<set>
#include<algorithm>
#include "Model.h"
#include "GUI.h"

/* This is the main class of the program
 * Events know how how to deal with GUI, and events know how to deal with Model
 * Events can trigger other events
 * */

class GUI;
class Model;

class UserEvent
{
protected:
    std::string mType;
    std::set<std::string> mPossibleCorrectNextEvents = {};

public:

    UserEvent() : mPossibleCorrectNextEvents{}, mType("UserEvent")
    {
    }

    std::string GetType();
    void GenerateState(Model& m);
    void GenerateState(Model& m, const std::vector<UserEvent*>& prev_events);
    void UpdateView(GUI& ui);

    bool ExpectSmth(); // check if the method expects some other event next

    bool Expect(UserEvent* prev); // check if event is in list of possible expected events
};

class UserClick : public UserEvent
{
public:
    UserClick()
    {
    }
};

class SaveButtonClick : public UserClick
{
public:
    SaveButtonClick();

    void GenerateState(Model& m); // event can trigger model on generating state
    void GenerateState(Model& m, const std::vector<UserEvent*>& prev_events); // event might act differently depending on prev events in sequence
    void UpdateView(GUI& ui);
};

class LoadButtonClick : public UserClick
{
public:
    LoadButtonClick();
    void GenerateState(Model& m);
};

class CanvasClick : public UserClick
{
public:
    CanvasClick();
    void GenerateState(Model& m, const std::vector<UserEvent*>& prev_events);
};

/*
 * Other Mouse click actions
*/

class UserMouseMove : public UserEvent
{
    UserMouseMove();
};

class CanvasMouseMove : public UserMouseMove
{
public:
    CanvasMouseMove();
};

/*
 * Other mouse move actions
 */

class KeyboardEvent : public UserEvent
{
public:
    KeyboardEvent(char* key)
    {
    }
};

class EmptyEvent : public UserEvent
{
};