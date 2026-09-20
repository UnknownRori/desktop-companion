#include "spritesheet.h"
#include "types.h"
#include "utils.h"

#include <raylib.h>
#include <rstb_common.h>
#include <string.h>

void spritesheet_init(
    spritesheet_t* self,
    u8 row,
    u8 col,
    u8 tail,
    Texture texture
)
{
    RORI_ASSERT(self != NULL && "You dummy dumb dumb, baka");
    memset(self, 0, sizeof(*self));

    self->row     = row;
    self->column  = col;
    self->tail    = tail;
    self->texture = texture;
    self->total_frames = ((self->row - 1) * self->column) + self->tail;
}

void spritesheet_draw(spritesheet_t* self, u32 width, u32 height, Rectangle dst)
{
    RORI_ASSERT(self != NULL && "You dummy dumb dumb, baka");

    int row = self->current_frame / self->column;
    int col = self->current_frame % self->column;
    Rectangle src = { 
        (f32)(col * width), 
        (f32)(row * height), 
        (f32)width,
        (f32)height 
    };
    DrawTexturePro(
        self->texture, 
        src,
        dst, 
        VEC2_ZERO, 
        0.0f, 
        WHITE
    );
}

void spritesheet_next_frame(spritesheet_t* self)
{
    RORI_ASSERT(self != NULL && "You dummy dumb dumb, baka");
    self->current_frame = (self->current_frame + 1) % self->total_frames;
}

void spritesheet_unload(spritesheet_t* self)
{
    RORI_ASSERT(self != NULL && "You dummy dumb dumb, baka");
    UnloadTexture(self->texture);
    memset(self, 0, sizeof(*self));
}
