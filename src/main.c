/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

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
    config_load();
    u32 raylib_cfg_flag = 
            FLAG_WINDOW_UNDECORATED  | 
            FLAG_WINDOW_TRANSPARENT  | 
            FLAG_WINDOW_TOPMOST;
    if (config_vsync()) {
        raylib_cfg_flag |= FLAG_VSYNC_HINT;
    }
    SetConfigFlags(raylib_cfg_flag);
    InitWindow(config_get_width(), config_get_height(), "Lilith");
    SetTargetFPS(144);

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
    set_render_fps(config_fps());
    input_init();

    while (!WindowShouldClose()) {
        if (config_force_ontop()) force_ontop();
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
