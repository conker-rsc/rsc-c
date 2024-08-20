#include <stdbool.h>
#include "../game-data.h"
#include "../utility.h"
#include "sundae.h"

/*
 * modifications to make game_data mimic mudclient110
 *
 * we could, of course, use an old config.jag, but this comes
 * with several disadvantages:
 *
 * - no coloured rocks or single-click mining/fishing/wc
 * - fewer examine texts (or broken examine texts)
 */

void apply_sundae(void) {
#if VERSION_ENTITY < 21
    game_data.animations[11].colour = 0; /* boots */
#endif

    game_data.items[11].name = mud_strdup("Arrows");
    game_data.items[11].description = mud_strdup("Hand crafted arrows");
    game_data.items[11].mask = 0; /* boots */

    game_data.items[37].members = false; /* life-rune */

    game_data.items[156].name = mud_strdup("pickaxe");
    game_data.items[156].mask = 0xeedddd;

    /* recolour strength potion to original */
    game_data.items[221].mask = 0x7250b1;
    game_data.items[222].mask = 0x7250b1;
    game_data.items[223].mask = 0x7250b1;
    game_data.items[224].mask = 0x7250b1;

    game_data.items[306].members = false; /* superchisel */

    for (int i = 0; i < game_data.npc_count; i++) {
        free(game_data.npcs[i].command);
        game_data.npcs[i].command = "";
    }

    for (int i = 0; i < game_data.object_count; i++) {
        if (strcmp(game_data.objects[i].command1, "rest") == 0) {
            free(game_data.objects[i].command1);
            game_data.objects[i].command1 = "WalkTo";
        }
    }
}
