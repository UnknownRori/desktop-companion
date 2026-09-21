/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#pragma once

#include <rconfig.h>
#include "types.h"

typedef struct animation_info_t{
    u8 row, col, tail;
} animation_info_t;

void config_load();
bool config_vsync();
bool config_debug();
bool config_force_ontop();
u32 config_fps();
u32 config_get_width();
u32 config_get_height();



bool config_get_animation_section(const char* name, char* value, usize max_len);
bool config_get_animation_path(const char* section, char* value, usize max_len);
bool config_get_animation_info(const char* section, animation_info_t* info);
