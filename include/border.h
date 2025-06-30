#pragma once
#include "raylib.h"
#include "core.h"

class Border : public MonoWidget{
private: 
    float _thickness = 1;
    Color _color = RED;

public:
    Border(float thickness, Color color);
    void Render(Vector2 position, Vector2 size) const override;
};