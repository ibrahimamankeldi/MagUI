#pragma once
#include "core.h"
#include "widget.h"
#include "raylib.h"
#include <string>
#include <array>

class Button : Widget{
public:
    void ChangeState(WidgetState* newState);

    std::array<Vector2, 4> GetPoints() const;

    std::array<Rectangle, 4> GetRecs() const;

    Button(Vector2 position, Vector2 size, float roundness)

    void SetText(const std::string& str)

    void OnMouseEnter(const Vector2& mousePos)

    void DrawBackground() const;

    void Render() const;

private:

}

