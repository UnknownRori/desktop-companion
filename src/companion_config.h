/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#pragma once

#include "types.h"

void config_load();
bool config_vsync();
bool config_debug();
bool config_force_ontop();
u32 config_fps();
u32 config_get_width();
u32 config_get_height();
