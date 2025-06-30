#include "label.h"
#include "raylib.h"
#include <string>

Label::Label(Vector2 position, const std::string& text, int fontSize){
    _position = position;
    _text = text;
    _fontSize = fontSize;
    _size.x = (float)MeasureText(text.c_str(), fontSize);
    _size.y = (float)fontSize;
}

Label::Label(Vector2 position, const std::string& text, int fontSize, Color fontColor) :
    Label(position, text, fontSize){
    _fontColor = fontColor;
}

void Label::Render() const{
    DrawText(_text.c_str(), _position.x, _position.y, _fontSize, _fontColor);
}
void Label::Update(){

}