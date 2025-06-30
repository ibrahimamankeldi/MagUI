#include "widget.h"

Widget* Widget::GetParent(){
    return _parent;
}

std::list<Widget*> Widget::GetChildren(){
    return _children;
}

void Widget::SetParent(Widget* newParent){
    _parent = newParent;
}

void Widget::SetPosition(Vector2 newPosition){
    _position = newPosition;
}

Rectangle Widget::GetRectangle(){
    Rectangle rec{_position.x, _position.y, _size.x, _size.y};
    return rec;
}

Vector2 Widget::GetSize(){
    return _size;
}

Vector2 Widget::GetPosition(){
    return _position;
}

void Widget::AddChild(Widget* child){
    _children.push_back(child);
    child->SetParent(this);
}

void Widget::Render() const{}

void Widget::Update(){}

void Widget::OnMouseEnter(Vector2 mousePos){}