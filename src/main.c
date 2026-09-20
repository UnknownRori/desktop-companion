#include "spritesheet.h"
#include "types.h"
#include "window.h"
#include <raylib.h>
#include <rstb_common.h>

#define WIDTH  64
#define HEIGHT 64

int main()
{
    SetConfigFlags(
    FLAG_VSYNC_HINT          | 
           FLAG_WINDOW_UNDECORATED  | 
           FLAG_WINDOW_TRANSPARENT  | 
           FLAG_WINDOW_TOPMOST
    );
    InitWindow(WIDTH, HEIGHT, "Lilith");
    SetTargetFPS(60);

    // TODO : Extract this later
    int lilith_fps = 60;
    f32 frame_time = 1.0f / (float)lilith_fps;
    f32 timer = 0.0f;
    Texture lilith_tex = LoadTexture("./resources/Spritesheet.png");

    spritesheet_t lilith_idle;
    spritesheet_init(
        &lilith_idle, 
        14, 
        14, 
        10, 
        lilith_tex
    );

    // TODO : Extract this later
    bool dragged = false;
    Vector2 pan_offset = { 0 };
    Vector2 window_pos = GetWindowPosition();

    while (!WindowShouldClose()) {
        force_ontop();

        Vector2 curr_mos = GetMousePosition();
        f32 wheel = GetMouseWheelMove();
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            break;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            dragged = true;
            pan_offset = curr_mos;
            window_pos = GetWindowPosition();
        }

        if (dragged) {
            window_pos.x += curr_mos.x - pan_offset.x;
            window_pos.y += curr_mos.y - pan_offset.y;
            
            SetWindowPosition((int)window_pos.x, (int)window_pos.y);

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                dragged = false;
            }
        }

        if (wheel > 0.0f) {
            SetWindowSize(GetScreenWidth() + WIDTH / 2.f, GetScreenHeight() + HEIGHT / 2.f);
        } 
        else if (wheel < 0.0f && GetScreenWidth() > 64) {
            SetWindowSize(GetScreenWidth() - WIDTH / 2.f, GetScreenHeight() - HEIGHT / 2.f);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) {
            SetWindowSize(WIDTH, HEIGHT);
        }

        timer += GetFrameTime();
        if (timer >= frame_time) {
            timer -= frame_time;
            spritesheet_next_frame(&lilith_idle);
        }

        BeginDrawing(); {
            ClearBackground(BLANK);
            spritesheet_draw(&lilith_idle, WIDTH, HEIGHT, (Rectangle) {
                0, 0,
                GetScreenWidth(), GetScreenHeight(),
            });
            DrawFPS(0, 0);
        } EndDrawing();
    }
}
