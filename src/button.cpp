// void Button::ChangeState(WidgetState* newState) {
//     currentState = newState;
// }

// std::array<Vector2, 4> Button::GetPoints() const {
//     std::array<Vector2, 4> points;
//     points[0] = position + (Vector2){radius, radius};
//     points[1] = points[0] + (Vector2){size.x - 2 * radius, 0};
//     points[2] = points[1] + (Vector2){0, size.y - 2 * radius};
//     points[3] = points[0] + (Vector2){0, size.y - 2 * radius};
//     return points;
// }

// std::array<Rectangle, 4> Button::GetRecs() const {
//     std::array<Rectangle, 4> recs;
//     std::array<Vector2, 4> positions;
//     positions[0] = position + (Vector2){0, radius};
//     positions[1] = position + (Vector2){radius, 0};
//     positions[2] = position + (Vector2){size.x - radius, radius};
//     positions[3] = position + (Vector2){radius, size.y - radius};

//     std::array<Vector2, 2> sizes;
//     sizes[0] = (Vector2){radius, size.y - 2 * radius};
//     sizes[1] = (Vector2){size.x - 2 * radius, radius};

//     for (int i = 0; i < 4; i++) {
//         Vector2 pos = positions[i];
//         Vector2 size_ = sizes[i % 2];
//         recs[i] = (Rectangle){pos.x, pos.y, size_.x, size_.y};
//     }

//     return recs;
// }

// Button::Button(Vector2 position, Vector2 size, float roundness) {
//     this->position = position;
//     this->size = size;
//     this->roundness = core::clap(roundness, 0, 1);
//     radius = (std::min(size.x, size.y) / 2) * this->roundness;
//     currentState = &normal;
// }

// void Button::SetText(const std::string& str) {
//     text = str;
// }

// void Button::OnMouseEnter(const Vector2& mousePos) {
//     ChangeState(&normal);

//     bool res = false;

//     for (Vector2 i : GetPoints()) {
//         if (CheckCollisionPointCircle(mousePos, i, radius)) {
//             res = true;
//             break;
//         }
//     }

//     for (Rectangle i : GetRecs()) {
//         if (CheckCollisionPointRec(mousePos, i)) {
//             res = true;
//             break;
//         }
//     }

//     Vector2 recPos = position + (Vector2){radius, radius};
//     Vector2 recSize = size - (Vector2){radius * 2, radius * 2};
//     Rectangle rec = {recPos.x, recPos.y, recSize.x, recSize.y};

//     if (CheckCollisionPointRec(mousePos, rec)) res = true;

//     if (res) {
//         ChangeState(&hover);
//         if (IsMouseButtonDown(0)) ChangeState(&click);
//     }
// }

// void Button::DrawBackground() const {
//     std::array<Vector2, 4> points = GetPoints();
//     Color bgcolor = currentState->backgroundColor;

//     DrawCircleSector(points[0], radius, -180, -90, 50, bgcolor);
//     DrawCircleSector(points[1], radius, 0, -90, 50, bgcolor);
//     DrawCircleSector(points[2], radius, 0, 90, 50, bgcolor);
//     DrawCircleSector(points[3], radius, 180, 90, 50, bgcolor);

//     for (Rectangle i : GetRecs()) {
//         DrawRectangleRec(i, bgcolor);
//     }

//     DrawRectangleV(position + (Vector2){radius, radius}, size - (Vector2){radius * 2, radius * 2}, bgcolor);
// }

// void Button::Render() const {
//     DrawBackground();

//     float font_spacing = 1;
//     float font_size = 48;
//     Vector2 text_size = MeasureTextEx(fonts[0], text.c_str(), font_size, font_spacing);
//     Vector2 text_pos = position + Vector2{
//         (size.x - text_size.x) / 2,
//         (size.y - text_size.y) / 2
//     };

//     DrawTextEx(fonts[0], text.c_str(), text_pos, font_size, font_spacing, BLACK);
// }
