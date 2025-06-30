#include "raylib.h"
#include "raymath.h"
#include "border.h"
#include "core.h"
#include "widget.h"
#include "label.h"
#include "layout.h"
#include "textbox.h"
#include <iostream>

int main(){
  InitWindow(1600, 900, "Hello UI");
  SetTargetFPS(60);

  Label label = Label((Vector2){10, 10}, "Hello World", 24, RED);
  Layout layout = Layout((Vector2){100, 100}, (Vector2){500, 500});
  Label label1 = Label((Vector2){0, 0}, "Maga", 24, BLUE);
  
  layout.AddChild(&label);
  layout.AddChild(&label1);

  HorOrient horient = HorOrient::Left;
  VerOrient vorient = VerOrient::Top;

  Border border(3.0f, GREEN);
  layout.border = &border;

  Layout layout1 = Layout((Vector2){0, 0}, (Vector2){300, 100});
  layout1.border = &border;

  layout.AddChild(&layout1);

  while(!WindowShouldClose())
  {
    layout.horOrient = horient;
    layout.verOrient = vorient;

    if(IsKeyPressed(KEY_D)){
      switch (horient)
      {
      case HorOrient::Left:
        horient = HorOrient::Center;
        break;
      
      case HorOrient::Center:
        horient = HorOrient::Right;
        break;

      case HorOrient::Right:
        horient = HorOrient::Left;
        break;

      default:
        break;
      }
    }

    if(IsKeyPressed(KEY_S)){
      switch (vorient)
      {
      case VerOrient::Top:
        vorient = VerOrient::Center;
        break;
      
      case VerOrient::Center:
        vorient = VerOrient::Bottom;
        break;

      case VerOrient::Bottom:
        vorient = VerOrient::Top;
        break;

      default:
        break;
      }
    }

    BeginDrawing();
    ClearBackground((Color){15, 15, 15, 255});
    layout.Render();
    DrawRectangleRounded((Vector2){200, 200}, (Vector2){400, 100}, 0.3f, PINK);
    EndDrawing();
  }

  CloseWindow(); 
  return 0;
}