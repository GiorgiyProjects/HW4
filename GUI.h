class UserEvent
{
};

class UserClick : public UserEvent
{
};

class UserMouseMove : public UserEvent
{
};

class KeyboardEvent : public UserEvent
{

};

class EmptyEvent : public UserEvent
{

};

class GUI
{
public:
    GUI() = default;

    UserEvent EventListener(HardwareObjects& ho)
    {
        if (ho.MouseSignal())
        {
            if (ho.MouseClick())
            {
                UserMouseMove e(ho);
            } else{
                UserClick e(ho);
            }
        } else  if (ho.KeyboardSignal())
        {
            KeyboardEvent e(ho); // nothing happened -> create empty user event
        } else{
            EmptyEvent e(ho);
        }
        return e;
    }
};
