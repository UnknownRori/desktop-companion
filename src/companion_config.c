/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#include "companion_config.h"
#include "types.h"
#define RORI_RCONFIG_NO_PREFIX
#include <rconfig.h>
#include <raylib.h>

static rori_config_t s_config;

void config_load()
{
    const char* cfg = LoadFileText("./config.cfg");
    if (cfg == NULL)
        TraceLog(LOG_FATAL, "Failed to load configuration file: file missing");

    if (!rconfig_parse_buffer(&s_config, cfg)) 
        TraceLog(LOG_FATAL, "Failed to load configuration file: parse error");
}

bool config_vsync()
{
    bool value;
    rconfig_get_properties_bool(&s_config, "app", "vsync", &value);
    return value;
}

bool config_debug()
{
    bool value;
    rconfig_get_properties_bool(&s_config, "app", "debug", &value);
    return value;
}

bool config_force_ontop()
{
    bool value;
    rconfig_get_properties_bool(&s_config, "app", "force_ontop", &value);
    return value;
}

u32 config_fps()
{
    i32 value;
    rconfig_get_properties_i32(&s_config, "companion", "fps", &value);
    return value;
}

u32 config_get_width()
{
    i32 value;
    rconfig_get_properties_i32(&s_config, "companion", "width", &value);
    return value;
}

u32 config_get_height()
{
    i32 value;
    rconfig_get_properties_i32(&s_config, "companion", "height", &value);
    return value;
}
bool config_get_animation_section(const char* name, char* value, usize max_len)
{
    return rconfig_get_properties_cstr(&s_config, "animation", name, value, max_len);
}

bool config_get_animation_path(const char* name, char* value, usize max_len)
{
    return rconfig_get_properties_cstr(&s_config, name, "src", value, max_len);
}

bool config_get_animation_info(const char* section, animation_info_t* info)
{
    i32 row, col, tail;
    if (!rconfig_get_properties_i32(&s_config, section, "row", &row))    return false;
    if (!rconfig_get_properties_i32(&s_config, section, "column", &col)) return false;
    if (!rconfig_get_properties_i32(&s_config, section, "tail", &tail))  return false;
    info->row  = (u8)row;
    info->col  = (u8)col;
    info->tail = (u8)tail;
    return true;
}
