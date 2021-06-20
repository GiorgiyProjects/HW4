#include "HardwareObjects.h"

Keyboard::Keyboard()
{
    BackToDefault();
}

void Keyboard::GenerateRandomClick()
{
    int r = rand() % mAlphabet.size() +1;
    mIsClicked[mAlphabet[r]] = true;
}

void Keyboard::BackToDefault()
{
    for(std::map<char, bool>::iterator  it = mIsClicked.begin(); it != mIsClicked.end(); ++it) {
        it->second = false;
    }
}

char Keyboard::GetClickedKey()
{
    for (const auto& [key, val] : mIsClicked)
    {
        if (val) return key;
    }
    return '0';
}

void Mouse::GenerateRandomClick()
{
    mButtonClicked = true;
}

void Mouse::GenerateRandomMove()
{
    mPos.x = rand() % 1080 +1;
    mPos.y = rand() % 1080 +1;
}

void Mouse::BackToDefault()
{
    mButtonClicked = false;
}

Point Mouse::GetMousePos()
{
    return mPos;
}

bool HardwareObjects::MouseSignal()
{
    if (mIsMouseMoved || mIsMouseClicked)
    {
        return true;
    }
    return false;
}

bool HardwareObjects::MouseClick()
{
    return mIsMouseClicked;
}

bool HardwareObjects::MouseMove()
{
    return mIsMouseMoved;
}

Point HardwareObjects::GetMousePosition()
{
    return mM.GetMousePos();
}

bool HardwareObjects::KeyboardSignal()
{
    if (mIsKeyboardClicked)
    {
        return true;
    }
    return false;
}

char HardwareObjects::GetClickedKey()
{
    if (mIsKeyboardClicked) return (mKB.GetClickedKey());
    return '0';
}

void HardwareObjects::CreateRandomEvent()
{
    int r = rand() % 3 +1;
    switch (r) {
        case 1:
            mIsMouseMoved = true;
            mM.GenerateRandomMove();
        case 2:
            mIsMouseClicked = true;
            mM.GenerateRandomClick();
        case 3:
            mIsKeyboardClicked = true;
            mKB.GenerateRandomClick();
    }
};

void HardwareObjects::BackToDefault()
{
    mIsMouseMoved = false;
    mIsMouseClicked = false;
    mIsKeyboardClicked = false;
    mM.BackToDefault();
    mKB.BackToDefault();
}