/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#pragma once

#include "spritesheet.h"
#include "types.h"

void set_render_sprite(spritesheet_t* spritesheet);
void set_render_fps(u8 fps);

void render_update(f32 dt);
void render();
