#include "BossFixes.h"

void openingDemo() {
	OSReport("MBGM Changed. Was: BGM_EV_BOSSRUSH");
    MR::startStageBGM("MBGM_GALAXY_INTER", false);
}

kmCall(0x800B1EF8, openingDemo);

void cryDemoEnd() {
	OSReport("MBGM Changed. Was: MBGM_SMG_BOSS_03A");
    MR::startStageBGM("MBGM_SMG2_BOSS_05A", false); //MBGM_SMG_BOSS_03A
}

kmCall(0x800B2070, cryDemoEnd);

void angryDemoEnd() {
	OSReport("MBGM Changed. Was: MBGM_SMG_BOSS_03B");
    MR::startStageBGM("MBGM_SMG2_BOSS_05B", false); //MBGM_SMG_BOSS_03B
}

kmCall(0x800B2294, angryDemoEnd);