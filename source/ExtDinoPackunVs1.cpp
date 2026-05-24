#include "ExtDinoPackunVs1.h"

//exeOpeningDemo__14DinoPackunDemoFv=0x800B1D20
//exeCryDemo__14DinoPackunDemoFv=0x800B1FA0
//exeAngryDemo__14DinoPackunDemoFv=0x800B20F0
//exeDownDemo__14DinoPackunDemoFv=0x800B2310

void openingDemoEnd(DinoPackun* pDino) {
    if (MR::isBckStopped(pDino))
        MR::startStageBGM("MBGM_GALAXY_INTER", false);
}

kmCall(0x800B1D20, openingDemoEnd);

void cryDemoEnd(DinoPackun* pDino) {
    if (MR::isBckStopped(pDino))
        MR::startStageBGM("MBGM_SMG2_BOSS_05A", false);
}

kmCall(0x800B1FA0, cryDemoEnd);

void angryDemoEnd(DinoPackun* pDino) {
    if (MR::isBckStopped(pDino))
        MR::startStageBGM("MBGM_SMG2_BOSS_05B", false);
}

kmCall(0x800B20F0, angryDemoEnd);