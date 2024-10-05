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

    /* remove members spells*/
    for (int i = 0; i < game_data.spell_count; ++i) {
        if (strstr(game_data.spells[i].name, "Ardougne") != NULL ||
                strstr(game_data.spells[i].name, "Camelot") != NULL ||
                strstr(game_data.spells[i].name, "Watchtower") != NULL ||
                strstr(game_data.spells[i].name, "Charge") != NULL ||
                strstr(game_data.spells[i].name, "Iban") != NULL) {
            game_data.spell_count--;
            for (int j = i; j < game_data.spell_count; ++j) {
                game_data.spells[j] = game_data.spells[j + 1];
            }
            i--;
        } else if (strstr(game_data.spells[i].name, "Fire blast") != NULL) {
            game_data.spell_count = i + 1;
        }
    }

    game_data.items[11].name = mud_strdup("Arrows");
    game_data.items[11].description = mud_strdup("Hand crafted arrows");
    game_data.items[11].mask = 0; /* boots */

    game_data.objects[139].description = "The Bank of Varrock";

    game_data.items[156].name = mud_strdup("pickaxe");
    game_data.items[156].mask = 0xeedddd;

    /* recolour strength potion to original */
    game_data.items[221].mask = 0x7250b1;
    game_data.items[222].mask = 0x7250b1;
    game_data.items[223].mask = 0x7250b1;
    game_data.items[224].mask = 0x7250b1;

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
