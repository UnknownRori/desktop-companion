/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#pragma once

#include "types.h"
#include <raylib.h>

typedef struct spritesheet_t {
    u8 current_frame;
    u8 total_frames;
    u8 row;
    u8 column;
    u8 tail;

    Texture texture;
} spritesheet_t;

void spritesheet_init(
    spritesheet_t* self,
    u8 row,
    u8 col,
    u8 tail,
    Texture texture
);
void spritesheet_draw(spritesheet_t* self, u32 width, u32 height, Rectangle dst);
void spritesheet_next_frame(spritesheet_t* self);
void spritesheet_unload(spritesheet_t* self);
