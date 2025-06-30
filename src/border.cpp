#include "raylib.h"
#include "border.h"

Border::Border(float thickness, Color color){
    _thickness = thickness;
    _color = color;
}

void Border::Render(Vector2 pos, Vector2 size) const{
    DrawRectangleLinesEx((Rectangle){pos.x, pos.y, size.x, size.y}, _thickness, _color);
}

