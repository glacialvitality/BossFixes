#include "BossFixes.h"

void ground() {
    MR::startStageBGM("MBGM_SMG2_BOSS_08A", false);
}

kmCall(0x800A8904, ground);

void lowFly() {
    MR::startStageBGM("MBGM_SMG2_BOSS_08B", false);
}

kmCall(0x800A89C0, lowFly);