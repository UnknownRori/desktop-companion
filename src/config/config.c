#include "config.h"

#include <rstb_common.h>

bool config_load_file(rori_config_t* self, const char* file)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(file);
    UNIMPLEMENTED;
}

bool config_parse_buffer(rori_config_t* self, const char* buffer)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(buffer);
    UNIMPLEMENTED;
}

void config_unload(rori_config_t* self)
{
    UNIMPLEMENTED;
}

bool config_get_properties(rori_config_t* self, const char* section, const char* name, rori_config_properties* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_get_properties_bool(rori_config_t* self, const char* section, const char* name, bool* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_get_properties_i32(rori_config_t* self, const char* section, const char* name, i32* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}
bool config_get_properties_cstr(rori_config_t* self, const char* section, const char* name, char* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_get_properties_sv(rori_config_t* self, const char* section, const char* name, rori_sv* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_set_properties(rori_config_t* self, const char* section, const char* name, const char* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_set_properties_i32(rori_config_t* self, const char* section, const char* name, i32 value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_set_properties_bool(rori_config_t* self, const char* section, const char* name, bool value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_set_properties_cstr(rori_config_t* self, const char* section, const char* name, const char* value) // NOTE : Possible memory leak
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}

bool config_set_properties_sv(rori_config_t* self, const char* section, const char* name, rori_sv* value)
{
    RORI_ASSERT(self != NULL && "skill issue");
    UNUSED(section);
    UNUSED(name);
    UNUSED(value);
    UNIMPLEMENTED;
}
