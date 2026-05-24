#include "ExtDinoPackunVs1.h"

//exeOpeningDemo__14DinoPackunDemoFv=0x800B1D20
//exeCryDemo__14DinoPackunDemoFv=0x800B1FA0
//exeAngryDemo__14DinoPackunDemoFv=0x800B20F0
//exeDownDemo__14DinoPackunDemoFv=0x800B2310

void openingDemo() {
    MR::startStageBGM("MBGM_GALAXY_INTER", false);
}

kmCall(0x800B1EF8, openingDemo);

void cryDemoEnd() {
    MR::startStageBGM("MBGM_SMG2_BOSS_07", false);
}

kmCall(0x800B2070, cryDemoEnd);

void angryDemoEnd() {
    MR::startStageBGM("MBGM_SMG2_BOSS_07B", false);
}

kmCall(0x800B2294, angryDemoEnd);