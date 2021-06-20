#pragma once

#include "Model.h"
#include "GUI.h"
#include "Events.h"
#include <iostream>

/*
 * The idea of Controller is to manage communication between Model and GUI
 * Controller stores the logic that is associated with Event partitioning, coming from Widgets and Models
 * Based on that logic he can generate States
 * Controller calls GUI whenever is needs to be updated
 */
class Controller
{
    std::vector<UserEvent*> mEvents; // this vector is made for processing event sequences. once the sequence starts over
public:
    void FinishEventSequence();
    bool Manage(UserEvent* e, Model& mod, GUI& ui);
};