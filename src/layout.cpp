#include "layout.h"
#include "raylib.h"
#include "raymath.h"
#include "core.h"

Layout::Layout(Vector2 position, Vector2 size){
    _position = position;
    _size = size;
}

void Layout::Compose(){

}

void Layout::Render() const{
    if(border != nullptr){
        border->Render(_position, _size);
    }
    
    Vector2 offset = _position + padding;
    float horSpace = (_children.size() - 1) * space.x;
    float verSpace = (_children.size() - 1) * space.y;

    if(horOrient == HorOrient::Center){
        offset.x += (_size.x - (_childrenSize.x + horSpace)) / 2 - padding.x * 2;
    }

    if(horOrient == HorOrient::Right){
        offset.x += _size.x - _childrenSize.x - horSpace - padding.x * 2;
    }

    if(verOrient == VerOrient::Center){
        offset.y += (_size.y - (_childrenSize.y + verSpace)) / 2 + padding.y;
    }

    if(verOrient == VerOrient::Bottom){
        offset.y += _size.y - (_childrenSize.y + verSpace) + padding.y;
    }

    for(Widget* child : _children){
        child->SetPosition(offset);
        offset.x += child->GetSize().x;
        offset.x += horSpace;

        child->Render();
    }
}

void Layout::Update(){
    for(Widget* child : _children){
        child->Update();
    }
}

void Layout::AddChild(Widget* child){
    _children.push_back(child);
    _childrenSize += child->GetSize();
}