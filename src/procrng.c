#include "global.h"
#include "new_game.h"
#include "procrng.h"
#include "random.h"
#if MODERN
#include <alloca.h>
#endif

// Generated in main_menu.c randomly, and stored in a var for recall (gets referenced twice)
// then never referenced again
u16 ProceduralRandomThisIsAPokemon() {
    return ProceduralPokemon(Random() % NUM_SPECIES);
}
u16 ProceduralRandomStarter(u16 starterSpecies) {
    u16 trainerId = (u16)GetTrainerId(gSaveBlock2Ptr->playerTrainerId);
    return ProceduralPokemon(trainerId + starterSpecies);
}
u16 ProceduralRandomWildPokemon(u16 species) {
    u16 trainerId = (u16)GetTrainerId(gSaveBlock2Ptr->playerTrainerId);
    return ProceduralPokemon(trainerId + species + gSaveBlock1Ptr->location.mapGroup * 7 + gSaveBlock1Ptr->location.mapNum * 13);
}
u16 ProceduralPokemon(u16 input) {
    // ignore
    u16 subtraction = 14
        + 1 + (SPECIES_GROUDON_PRIMAL - SPECIES_VENUSAUR_MEGA) 
        + 1 + (SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL - SPECIES_PIKACHU_COSPLAY)
        + (SPECIES_SQUAWKABILLY_WHITE - SPECIES_SQUAWKABILLY_GREEN)
        + (SPECIES_TATSUGIRI_STRETCHY - SPECIES_TATSUGIRI_CURLY)
        + (SPECIES_TAUROS_PALDEA_AQUA - SPECIES_TAUROS_PALDEA_COMBAT)
        + (SPECIES_OGERPON_CORNERSTONE_TERA - SPECIES_OGERPON_TEAL_TERA)
        + (SPECIES_TERAPAGOS_STELLAR - SPECIES_TERAPAGOS_NORMAL)
        + 1 + (SPECIES_SCATTERBUG_POKEBALL - SPECIES_SCATTERBUG_POLAR)
        + 1 + (SPECIES_MIMIKYU_TOTEM_BUSTED - SPECIES_RATICATE_ALOLA_TOTEM);

    rng_value_t rand = LocalRandomSeed(input);
    int randVal = LocalRandom(&rand) % (NUM_SPECIES - subtraction);
    input = randVal;

    // shift pokemon to skip forms

    // Species None
    input++;
    if (input >= SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM) {
        input++;
    }
    if (input >= SPECIES_VENUSAUR_MEGA) {
        input += 1 + SPECIES_GROUDON_PRIMAL - SPECIES_VENUSAUR_MEGA;
    }
    if (input >= SPECIES_PIKACHU_COSPLAY) {
        input += 1 + (SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL - SPECIES_PIKACHU_COSPLAY);
    }
    if (input >= SPECIES_SQUAWKABILLY_GREEN + 1) {
        input += SPECIES_SQUAWKABILLY_WHITE - SPECIES_SQUAWKABILLY_GREEN;
    }
    if (input >= SPECIES_MAUSHOLD_THREE) {
        input++;
    }
    if (input >= SPECIES_OINKOLOGNE_M) {
        input++;
    }
    if (input >= SPECIES_PALAFIN_HERO) {
        input++;
    }
    if (input >= SPECIES_TATSUGIRI_CURLY + 1) {
        input += SPECIES_TATSUGIRI_STRETCHY - SPECIES_TATSUGIRI_CURLY;
    }
    if (input >= SPECIES_DUDUNSPARCE_THREE_SEGMENT) {
        input++;
    }
    if (input >= SPECIES_GIMMIGHOUL_ROAMING) {
        input++;
    }
    if (input >= SPECIES_TAUROS_PALDEA_COMBAT) {
        input += 1 + SPECIES_TAUROS_PALDEA_AQUA - SPECIES_TAUROS_PALDEA_COMBAT;
    }
    if (input >= SPECIES_POLTCHAGEIST_ARTISAN) {
        input++;
    }
    if (input >= SPECIES_SINISTCHA_MASTERPIECE) {
        input++;
    }
    if (input >= SPECIES_OGERPON + 1) {
        input += SPECIES_OGERPON_CORNERSTONE - SPECIES_OGERPON;
    }
    if (input >= SPECIES_OGERPON_TEAL_TERA) {
        input += 1 + SPECIES_OGERPON_CORNERSTONE_TERA - SPECIES_OGERPON_TEAL_TERA;
    }
    if (input >= SPECIES_URSALUNA_BLOODMOON) {
        input++;
    }
    if (input >= SPECIES_TERAPAGOS_NORMAL + 1) {
        input += SPECIES_TERAPAGOS_STELLAR - SPECIES_TERAPAGOS_NORMAL;
    }
    if (input >= SPECIES_SCATTERBUG_POLAR) {
        input += 1 + SPECIES_SCATTERBUG_POKEBALL - SPECIES_SCATTERBUG_POLAR;
    }
    if (input >= SPECIES_SPEWPA_POLAR) {
        input += 1 + SPECIES_SPEWPA_POKEBALL - SPECIES_SPEWPA_POLAR;
    }
    if (input >= SPECIES_RATICATE_ALOLA_TOTEM) {
        input += 1 + SPECIES_MIMIKYU_TOTEM_BUSTED - SPECIES_RATICATE_ALOLA_TOTEM;
    }
    /**
    1 SPECIES_NONE
    2 SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM
    R SPECIES_VENUSAUR_MEGA -> SPECIES_GROUDON_PRIMAL
    R SPECIES_PIKACHU_COSPLAY -> SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL
    R -random: SPECIES_SQUAWKABILLY_GREEN, SPECIES_SQUAWKABILLY_BLUE, SPECIES_SQUAWKABILLY_YELLOW, SPECIES_SQUAWKABILLY_WHITE
    5 -random: SPECIES_MAUSHOLD_THREE, SPECIES_MAUSHOLD_FOUR
    6 -random: SPECIES_OINKOLOGNE_M, SPECIES_OINKOLOGNE_F
    3 SPECIES_PALAFIN_HERO
    8 -random: SPECIES_TATSUGIRI_CURLY, SPECIES_TATSUGIRI_DROOPY, SPECIES_TATSUGIRI_STRETCHY
    9 -random: SPECIES_DUDUNSPARCE_TWO_SEGMENT, SPECIES_DUDUNSPARCE_THREE_SEGMENT
    10 -random: SPECIES_GIMMIGHOUL_CHEST, SPECIES_GIMMIGHOUL_ROAMING
    R -random: SPECIES_TAUROS -> SPECIES_TAUROS_PALDEA_COMBAT, SPECIES_TAUROS_PALDEA_BLAZE, SPECIES_TAUROS_PALDEA_AQUA
    11 -random: SPECIES_POLTCHAGEIST_COUNTERFEIT, SPECIES_POLTCHAGEIST_ARTISAN
    R -random: SPECIES_SINISTCHA_UNREMARKABLE, SPECIES_SINISTCHA_MASTERPIECE
    14 -random: SPECIES_OGERPON, SPECIES_OGERPON_TEAL, SPECIES_OGERPON_WELLSPRING, SPECIES_OGERPON_HEARTHFLAME, SPECIES_OGERPON_CORNERSTONE
    R SPECIES_OGERPON_TEAL_TERA, SPECIES_OGERPON_WELLSPRING_TERA, SPECIES_OGERPON_HEARTHFLAME_TERA, SPECIES_OGERPON_CORNERSTONE_TERA
    4 SPECIES_URSALUNA_BLOODMOON
    R SPECIES_TERAPAGOS_NORMAL, SPECIES_TERAPAGOS_TERASTAL, SPECIES_TERAPAGOS_STELLAR
    R -random: SPECIES_SCATTERBUG_POLAR -> SPECIES_SCATTERBUG_POKEBALL
    R -random: SPECIES_SPEWPA_POLAR -> SPECIES_SPEWPA_POKEBALL
    R SPECIES_RATICATE_ALOLA_TOTEM -> SPECIES_MIMIKYU_TOTEM_BUSTED
    */
    if (input >= NUM_SPECIES || input < SPECIES_BULBASAUR) {
        return SPECIES_LUGIA_SHADOW;
    }
    return input;
}

u16 ProceduralItem(u16 input) {
    u32 trainerId = GetTrainerId(gSaveBlock2Ptr->playerTrainerId) + input;
    u16 subtraction = ITEM_ABILITY_SHIELD - ITEM_TM51 + 2;  // 1 to go HM01-1, 1 for Item_0_NONE
    rng_value_t rand = LocalRandomSeed(trainerId + input);
    int randVal = LocalRandom(&rand) % (ITEMS_COUNT - subtraction);
    input = randVal;
    input++;
    if (input >= ITEM_TM51) {
        input += 1 + ITEM_ABILITY_SHIELD - ITEM_TM51;
    }
    if (input > ITEMS_COUNT || input < 1) {
        return ITEM_ULTRA_BALL;
    }
    return input;

    // 1 -> ITEM_HM01
    // ITEM_ABILITY_SHIELD -> ITEM_STRANGE_BALL
}