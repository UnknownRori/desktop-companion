/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#include "render.h"
#include "spritesheet.h"
#include "companion_config.h"

#include <raylib.h>
#include <rstb_common.h>

static spritesheet_t* s_active;
static f32 s_frame_time = 0.0f;
static f32 s_timer = 0.0f;

void set_render_sprite(spritesheet_t* spritesheet)
{
    RORI_ASSERT(spritesheet != NULL && "Skill issue");
    s_active = spritesheet;
    s_frame_time = 0.f;
    s_timer = 0.f;
}

void set_render_fps(u8 fps)
{
    s_frame_time = 1.0f / (float)fps;
}

void render_update(f32 dt)
{
    s_timer += dt;
    if (s_timer >= s_frame_time) {
        s_timer -= s_frame_time;
        spritesheet_next_frame(s_active);
    }
}
void render()
{
    spritesheet_draw(s_active, config_get_width(), config_get_height(), (Rectangle) {
        0, 0,
        GetScreenWidth(), GetScreenHeight(),
    });
}
