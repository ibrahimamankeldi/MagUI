#pragma once
#include "core.h"
#include "widget.h"
#include "border.h"

class Layout : public Widget{
private:
    Vector2 _childrenSize;

public:
    Vector2 padding = {10.0f, 10.0f};
    Vector2 space = {10.0f, 10.0f};

    HorOrient horOrient = HorOrient::Left;
    VerOrient verOrient = VerOrient::Top;

    Border* border = nullptr;

    Layout(Vector2 position, Vector2 size);
    void Render() const override;
    void Update() override;
    void Compose();
    void AddChild(Widget* child);
};