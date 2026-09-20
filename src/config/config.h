#pragma once

#ifndef RORI_CONFIG_H
#define RORI_CONFIG_H

#include "types.h"

typedef struct rori_config_t rori_config_t;

#ifndef RORI_SV
typedef struct rori_sv  {
    const char* ptr;
    usize len;
} rori_sv;
#endif

typedef struct rori_config_properties  {
    rori_sv section;
    rori_sv name;
    rori_sv value;
} rori_config_properties;


bool config_load_file(rori_config_t* self, const char* file);
bool config_parse_buffer(rori_config_t* self, const char* buffer);
void config_unload(rori_config_t* self);

bool config_get_properties(rori_config_t* self, const char* section, const char* name, rori_config_properties* value);

bool config_get_properties_bool(rori_config_t* self, const char* section, const char* name, bool* value);
bool config_get_properties_i32(rori_config_t* self, const char* section, const char* name, i32* value);
bool config_get_properties_cstr(rori_config_t* self, const char* section, const char* name, char* value);
bool config_get_properties_sv(rori_config_t* self, const char* section, const char* name, rori_sv* value);

bool config_set_properties(rori_config_t* self, const char* section, const char* name, const char* value);

bool config_set_properties_i32(rori_config_t* self, const char* section, const char* name, i32 value);
bool config_set_properties_bool(rori_config_t* self, const char* section, const char* name, bool value);
bool config_set_properties_cstr(rori_config_t* self, const char* section, const char* name, const char* value); // NOTE : Possible memory leak
bool config_set_properties_sv(rori_config_t* self, const char* section, const char* name, rori_sv* value);

#endif // RORI_CONFIG_H
