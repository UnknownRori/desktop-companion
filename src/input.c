/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#include "types.h"
#include <raylib.h>

static bool s_dragged = false;
static Vector2 s_pan_offset = { 0 };
static Vector2 s_window_pos;

void input_init()
{
    s_window_pos = GetWindowPosition();
}

void input_default_update(u32 sprite_width, u32 sprite_height)
{
    Vector2 curr_mos = GetMousePosition();
    f32 wheel = GetMouseWheelMove();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        s_dragged = true;
        s_pan_offset = curr_mos;
        s_window_pos = GetWindowPosition();
    }

    if (s_dragged) {
        s_window_pos.x += curr_mos.x - s_pan_offset.x;
        s_window_pos.y += curr_mos.y - s_pan_offset.y;
        
        SetWindowPosition((int)s_window_pos.x, (int)s_window_pos.y);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            s_dragged = false;
        }
    }

    if (wheel > 0.0f) {
        SetWindowSize(GetScreenWidth() + sprite_width / 2.f, GetScreenHeight() + sprite_height / 2.f);
    } 
    else if (wheel < 0.0f && GetScreenWidth() > 64) {
        SetWindowSize(GetScreenWidth() - sprite_width / 2.f, GetScreenHeight() - sprite_height / 2.f);
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) {
        SetWindowSize(sprite_width, sprite_height);
    }
}
