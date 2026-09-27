/*
 * Copyright (c) 2026 UnknownRori
 * Licensed under the PolyForm Noncommercial License 1.0.0
 * See LICENSE file in repository root for full terms.
 */

#include <rstb_common.h>
#include "animation.h"
#include "companion_config.h"

bool animation_get(spritesheet_t* spritesheet, const char* name)
{
    RORI_ASSERT(spritesheet != NULL && "Skill issue");
    char section_name[1024];
    if (!config_get_animation_section(name, section_name, 1024)) return false;

    char path[1024];
    if (!config_get_animation_path(section_name, path, 1024)) return false;
    Texture texture = LoadTexture(path);

    animation_info_t anim;
    config_get_animation_info(section_name, &anim);

    spritesheet_init(
        spritesheet, 
        anim.row, 
        anim.col, 
        anim.tail, 
        texture
    );
    return true;
}
