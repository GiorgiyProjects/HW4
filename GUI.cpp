#include "GUI.h"

bool Widget::CheckIfHovered(Point P)
{
    return Obj.Contains(P);
}

UserEvent* SaveButton::Click()
{
    return new SaveButtonClick();
}

Widget::Widget()
{
    std::cout << "Define Widget" << std::endl;
}

UserEvent* Widget::Click()
{
    return nullptr;
}

UserEvent* Widget::Hover()
{
    return nullptr;
}

Canvas::Canvas()
{
    std::cout << "Define canvas" << std::endl;
}

SaveButton::SaveButton()
{
    std::cout << "Define SaveButton" << std::endl;
}

CreateTriangleButton::CreateTriangleButton()
{
    std::cout << "Define CreateTriangleButton" << std::endl;
}

KeyboardWidget::KeyboardWidget()
{
    std::cout << "Define KeyboardWidget" << std::endl;
}

UserEvent* KeyboardWidget::KeyboardClick(char c)
{
    return nullptr;
}

GUI::GUI() {
    Canvas c;
    mWidgets.push_back(&c);
    SaveButton sb;
    mWidgets.push_back(&sb);
    //...
    CreateTriangleButton tb;
    mWidgets.push_back(&tb);
}

Widget* GUI::GetHoveredWidget(Point mp)
{
    for (const auto& wg : mWidgets)
    {
        if (wg->CheckIfHovered(mp))
        {
            return wg;
        }
    }
    return nullptr;
}

UserEvent* GUI::HardwareEventListen(HardwareObjects& ho)
{
    if (ho.MouseSignal())
    {
        Point mp = ho.GetMousePosition();
        Widget* widget = GetHoveredWidget(mp);
        if (widget == nullptr) return (new EmptyEvent());
        if (ho.MouseClick())
        {
            return(widget->Click());
        } else{
            return(widget->Hover());
        }
    } else if (ho.KeyboardSignal())
    {
        char clickedKey =  ho.GetClickedKey();
        return(mKeyboard.KeyboardClick(clickedKey));
    }
    return (new EmptyEvent());
}