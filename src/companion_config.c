#include "companion_config.h"
#include "config/config.h"
#include <raylib.h>

static rori_config_t s_config;

void config_load()
{
    const char* cfg = LoadFileText("./config.cfg");
    if (cfg == NULL)
        TraceLog(LOG_FATAL, "Failed to load configuration file: file missing");

    if (!config_parse_buffer(&s_config, cfg)) 
        TraceLog(LOG_FATAL, "Failed to load configuration file: parse error");
}

bool config_vsync()
{
    bool value;
    config_get_properties_bool(&s_config, "app", "vsync", &value);
    return value;
}

bool config_debug()
{
    bool value;
    config_get_properties_bool(&s_config, "app", "debug", &value);
    return value;
}

bool config_force_ontop()
{
    bool value;
    config_get_properties_bool(&s_config, "app", "force_ontop", &value);
    return value;
}

u32 config_fps()
{
    i32 value;
    config_get_properties_i32(&s_config, "companion", "fps", &value);
    return value;
}

u32 config_get_width()
{
    i32 value;
    config_get_properties_i32(&s_config, "companion", "width", &value);
    return value;
}

u32 config_get_height()
{
    i32 value;
    config_get_properties_i32(&s_config, "companion", "height", &value);
    return value;
}
