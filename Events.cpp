#include "Events.h"

std::string UserEvent::GetType()
{
    return mType;
}

bool UserEvent::ExpectSmth() // check if the method expects some other event next
{
    std::cout << "dd " << mPossibleCorrectNextEvents.size() << std::endl;
    return (mPossibleCorrectNextEvents.size() > 0);
}

bool UserEvent::Expect(UserEvent* prev)  // check if event is in list of possible expected events
{
    return (mPossibleCorrectNextEvents.find(prev->GetType()) != mPossibleCorrectNextEvents.end());
}

void UserEvent::GenerateState(Model& m, const std::vector<UserEvent*>& prev_events)
{
    std::cout << "Generate state for event" << std::endl;
    return;
}

void UserEvent::UpdateView(GUI& ui)
{
    std::cout << "Generate UpdateView for event" << std::endl;
    return;
}

SaveButtonClick::SaveButtonClick()
{
    mType = "SaveButtonClick";
    mPossibleCorrectNextEvents = {};
}

void SaveButtonClick::GenerateState(Model& m)
{
    std::cout << "Here will be the logic for saving model to attached file" << std::endl;
}

void SaveButtonClick::GenerateState(Model& m, const std::vector<UserEvent*>& prev_events)
{
    // ... model on saving state to file if prev events are correct
    m.SaveStateToFile("filename.txt");
}

void SaveButtonClick::UpdateView(GUI& ui)
{
    std::cout << "Here we will have a logic for updating GUI for user" << std::endl;
}

LoadButtonClick::LoadButtonClick()
{
    mType = "LoadButtonClick";
    mPossibleCorrectNextEvents = {"OkButtonClick", "UndoButtonClick"};
}


