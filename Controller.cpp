#include "Controller.h"

void Controller::FinishEventSequence()
{
    std::cout << "finishing event sequence" << std::endl;
    mEvents.clear();
}

bool Controller::Manage(UserEvent* e, Model& mod, GUI& ui)
{
    std::cout << "Manager is managing" << std::endl;
    // check, if previous user event expects certain other event
    if (!mEvents.empty() && !mEvents.back()->Expect(e))
    {
        FinishEventSequence();
        std::cout << "Unexpected event in the sequence! Finish the sequence" << std::endl;
        return false;
    }
    std::cout << "New event in the sequence started" << std::endl;
    mEvents.push_back(e);
    if (!e->ExpectSmth())
    {
        FinishEventSequence();
        e->GenerateState(mod ,mEvents);
        return true;
    }
    e->UpdateView(ui);
    return true;
}