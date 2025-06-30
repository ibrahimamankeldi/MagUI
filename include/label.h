#pragma once
#include "widget.h"
#include "raylib.h"
#include <string>

class Label : public Widget{
private:
    std::string _text;
    int _fontSize;
    Color _fontColor;
public:
    Label(Vector2 position, const std::string& text, int fontSize);
    Label(Vector2 position, const std::string& text, int fontSize, Color fontColor);
    void Render() const override;
    void Update() override;
};