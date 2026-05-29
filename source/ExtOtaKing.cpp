#include "BossFixes.h"

void exeAppearDemo() {
    MR::startStageBGM("MBGM_SMG2_BOSS_08A", false);
}

kmCall(0x800EFCE0, exeAppearDemo);

void postDemoOtaKingDown() {
    MR::startLastStageBGM();
}
// 800f0bc4, 800f0c28

kmCall(0x800F0BC4, postDemoOtaKingDown);
kmCall(0x800F0C28, postDemoOtaKingDown); // why the ever living f*ck is this called twice?            