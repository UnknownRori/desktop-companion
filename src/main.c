#include "companion_config.h"
#include "render.h"
#include "spritesheet.h"
#include "input.h"
#include "types.h"
#include "window.h"

#include <raylib.h>
#include <rstb_common.h>

int main()
{
    SetConfigFlags(
    FLAG_VSYNC_HINT          | 
           FLAG_WINDOW_UNDECORATED  | 
           FLAG_WINDOW_TRANSPARENT  | 
           FLAG_WINDOW_TOPMOST
    );
    InitWindow(config_get_width(), config_get_height(), "Lilith");
    SetTargetFPS(60);

    Texture lilith_tex = LoadTexture("./resources/Spritesheet.png");

    spritesheet_t lilith_idle;
    spritesheet_init(
        &lilith_idle, 
        14, 
        14, 
        10, 
        lilith_tex
    );

    set_render_sprite(&lilith_idle);
    set_render_fps(30);
    input_init();

    while (!WindowShouldClose()) {
        force_ontop();
        input_default_update(config_get_width(), config_get_height());

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            break;
        }

        render_update(GetFrameTime());

        BeginDrawing(); {
            ClearBackground(BLANK);
                render();
            DrawFPS(0, 0);
        } EndDrawing();
    }
}
