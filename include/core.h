#pragma once
#include "raylib.h"

enum class HorOrient{
    Left = 0, Center = 1, Right = 2
};

enum class VerOrient{
    Top = 0, Center = 1, Bottom = 2
};

class MonoWidget{
public:
    void virtual Render(Vector2, Vector2) const;
};

struct WidgetState
{
    Color bgcolor = BLUE;
};


float clapf(float, float, float);

void DrawRectangleRounded(Vector2 position, Vector2 size, float roundness, Color color);

namespace Core{
    
}