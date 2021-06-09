#include<algorithm>
#include <string>
#include<map>

class Keyboard
{
    std::string mAlphabet = "abcdefghijklmnopqrstuvwxyz01234567890";
    std::map<char, bool> mIsClicked;
public:
    Keyboard()
    {
        BackToDefault();
    }

    void GenerateRandomClick()
    {
        int r = rand() % mAlphabet.size() +1;
        mIsClicked[mAlphabet[r]] = true;
    }

    void BackToDefault()
    {
        std::for_each( mAlphabet.begin(), mAlphabet.end(), [mIsClicked](char c) // fix lambda
        {
            mIsClicked[c] = false;
        }
        );
    }
};

class Mouse
{
    int mPosX; // in pixels
    int mPosY;
    bool mButtonClicked = false;

public:
    Mouse() = default;

    void GenerateRandomClick()
    {
        mButtonClicked = true;
    }

    void GenerateRandomMove()
    {
        mPosX = rand() % 1080 +1;
        mPosY = rand() % 1080 +1;
    }

    void BackToDefault()
    {
        mButtonClicked = false;
    }
};

class HardwareObjects
{
    bool mIsMouseMoved = false;
    bool mIsMouseClicked = false;
    bool mIsKeyboardClicked = false;
    Keyboard mKB;
    Mouse mM;

public:
    HardwareObjects() = default;

    bool MouseSignal()
    {
        if (mIsMouseMoved || mIsMouseClicked)
        {
            return true;
        }
        return false;
    }

    bool MouseClick()
    {
        return mIsMouseClicked;
    }

    bool MouseMove()
    {
        return mIsMouseMoved;
    }

    bool KeyboardSignal()
    {
        if (mIsKeyboardClicked)
        {
            return true;
        }
        return false;
    }

    void CreateRandomEvent()
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

    void BackToDefault()
    {
        mIsMouseMoved = false;
        mIsMouseClicked = false;
        mIsKeyboardClicked = false;
        mM.BackToDefault();
        mKB.BackToDefault();
    }

};