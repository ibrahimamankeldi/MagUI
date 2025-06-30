#include "core.h"
#include "raylib.h"
#include "raymath.h"

float clapf(float n, float min, float max){
    if(n < min) n = min;
    if(n > max) n = max;
    return n;
}

void MonoWidget::Render(Vector2 position, Vector2 size) const{}

void DrawRectangleRounded(Vector2 position, Vector2 size, 
                            float roundness, Color color){
    roundness = clapf(roundness, 0.0f, 1.0f);
    float radius = (std::min(size.x, size.y) / 2) * roundness;

    Vector2 points[4];
    points[0] = position + (Vector2){radius, radius};
    points[1] = points[0] + (Vector2){size.x - 2 * radius, 0};
    points[2] = points[1] + (Vector2){0, size.y - 2 * radius};
    points[3] = points[0] + (Vector2){0, size.y - 2 * radius};

    Rectangle recs[4];
    Vector2 positions[4];
    positions[0] = position + (Vector2){0, radius};
    positions[1] = position + (Vector2){radius, 0};
    positions[2] = position + (Vector2){size.x - radius, radius};
    positions[3] = position + (Vector2){radius, size.y - radius};

    Vector2 sizes[2];
    sizes[0] = (Vector2){radius, size.y - 2 * radius};
    sizes[1] = (Vector2){size.x - 2 * radius, radius};

    for (int i = 0; i < 4; i++) {
        Vector2 pos = positions[i];
        Vector2 size_ = sizes[i % 2];
        recs[i] = (Rectangle){pos.x, pos.y, size_.x, size_.y};
    }

    DrawCircleSector(points[0], radius, -180, -90, 50, color);
    DrawCircleSector(points[1], radius, 0, -90, 50, color);
    DrawCircleSector(points[2], radius, 0, 90, 50, color);
    DrawCircleSector(points[3], radius, 180, 90, 50, color);

    for (Rectangle i : recs) {
        DrawRectangleRec(i, color);
    }

    DrawRectangleV(position + (Vector2){radius, radius}, size - (Vector2){radius * 2, radius * 2}, color);
}