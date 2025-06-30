#pragma once
#include "raylib.h"
#include "list"

class Widget{
protected:
    Vector2 _position;
    Vector2 _size;
    Widget* _parent;
    std::list<Widget*> _children;
public:
    void virtual Render() const;
    void virtual Update();
    void virtual OnMouseEnter(Vector2 mousePos);

    Widget* GetParent();

    std::list<Widget*> GetChildren();

    Rectangle GetRectangle();

    Vector2 GetSize();

    Vector2 GetPosition();
    
    void SetParent(Widget*);

    void SetPosition(Vector2);

    void AddChild(Widget* child);
};