/*
                             @@....--.......@@@                      
                          @@@.....-............@@                    
                       @...---.....................@                 
                    @........-##..-...............   @@              
                  @........++#++....--.......    ........@           
               @@.........++++++.........     ...........--@         
               @@.    ...++===++..   ..............--.------@        
                @.......+++==++..  ....--..........----------@       
                @--..---#++++++......--------------------+---  @  @  
               @--------##+++##---..-------##---##--+----++- ** ** @ 
             @@---------#######--------+-----###-----+----- ******* @
           @@%%---------#######------------++++-------+-----+ *** @  
         @##%-----------########+---------------+-----+...---+- @    
        @##%%------+----+########+----------....-+-----..----+---@   
      @#-##%#-----+----++--#######-+----....%%%.-+-----+++-------@   
      @##-###-----+----++-----####---+--%%%%....-+-----++++---+--@   
         @###@@--+++----%%%%%%%%%%...-...........-----+++++---+--@   
             @@+@@-+----++-   ++++..............-----++++++--+++--@  
               @+@+------++..  ===.............-----++++++---+++--@  
                @+++---------.................----+++++--+---++++-@  
                @++++-----------............---##+++++---+----++++-@ 
                @++++--+--+++++++.......---####--++@@--+++----@   @  
                 @++++----+++++++++++++####--..........@@@@+---@     
                   @++++--+@@  @@@......###.................@--@     
                      @++@@@@.........######............. ...@-@     
                       @@@..........#########.................@      
                        @..........###########................@      
                       @...........--.########.....-...........@     
                      @...........-..##########....-@-..........@    
                    @....--....--..-###########...--@ @..........@   
                   @......-==######%%############.-@   @@.........@  
                 @.......-=#######%%%#############-@  @..........@   
                @......--#########%%#############%-@ @.........-@    
               @......--.#%%%#####%%%###########%%@@..........-@     

Copyright (c) 2026 UnknownRori
Licensed under the PolyForm Noncommercial License 1.0.0
See LICENSE file in repository root for full terms.
 */

#include "animation.h"
#include "companion_config.h"
#include "render.h"
#include "spritesheet.h"
#include "input.h"
#include "types.h"
#include "window.h"

#include <raylib.h>
#include <rstb_common.h>

typedef enum {
    IDLE,
    MOVE,
} companion_state;

int main()
{
    config_load();
    u32 raylib_cfg_flag = 
            FLAG_WINDOW_UNDECORATED  | 
            FLAG_WINDOW_TRANSPARENT  | 
            FLAG_WINDOW_TOPMOST;
    if (config_vsync()) {
        raylib_cfg_flag |= FLAG_VSYNC_HINT;
    }
    SetConfigFlags(raylib_cfg_flag);
    InitWindow(config_get_width(), config_get_height(), "Lilith");
    SetTargetFPS(144);

    // TODO : extract this to somewhere
    ChangeDirectory("resources");
    spritesheet_t flan_idle;
    spritesheet_t flan_move;
    spritesheet_t flan_pat;
    animation_get(&flan_idle, "default");
    animation_get(&flan_move, "move");
    animation_get(&flan_pat, "headpat");

    set_render_sprite(&flan_idle);
    set_render_fps(config_fps());
    input_init();

    companion_state state = 0;
    bool dirty = false;

    #define CHANGE_STATE(STATE) do { if (state != (STATE)) dirty = true; state = (STATE);  } while (0)

    while (!WindowShouldClose()) {
        if (config_force_ontop()) force_ontop();
        input_default_update(config_get_width(), config_get_height());

        if (input_is_move()) {
            CHANGE_STATE(MOVE);
        } else {
            CHANGE_STATE(IDLE);
        }

        switch (state) {
            case IDLE: {
                if (dirty) {
                    dirty = false;
                    set_render_sprite(&flan_idle);
                }
            } break;
            case MOVE: {
                if (dirty) {
                    dirty = false;
                    set_render_sprite(&flan_move);
                }
            } break;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            break;
        }

        render_update(GetFrameTime());

        BeginDrawing(); {
            ClearBackground(BLANK);
                render();
            if (config_debug()) DrawFPS(0, 0);
        } EndDrawing();
    }
}
