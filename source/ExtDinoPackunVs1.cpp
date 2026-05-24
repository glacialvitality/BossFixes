#include "ExtDinoPackunVs1.h"
#include "Game/Boss/DinoPackunSequencer.h"

//exeOpeningDemo__14DinoPackunDemoFv=0x800B1D20
//exeCryDemo__14DinoPackunDemoFv=0x800B1FA0
//exeAngryDemo__14DinoPackunDemoFv=0x800B20F0
//exeDownDemo__14DinoPackunDemoFv=0x800B2310

void DinoPackunDemo::exeOpeningDemo() {
    if (MR::isFirstStep(this)) {
        MR::stopStageBGM(30);
        getHost()->startDemoAndReset();
        getHost()->mDemoPos->startOpeningDemo();
        MR::startAnimCameraTargetSelf(getHost(), getHost()->mCameraInfo, "OpeningDemo", 0, 1.0f);
        MR::startAction(getHost(), "OpeningDemo");
        MR::startBva(getHost()->getEggShell(), "OpeningDemo");
        MR::invalidateCollisionParts(getHost()->getEggShell());
        MR::startBckPlayer("BattleWait", static_cast< const char* >(0));
    }

    getHost()->mDemoPos->movement();

    if (MR::isStep(this, 28)) {
        MR::startSystemSE("SE_DM_MEET_BOSS", -1, -1);
        MR::startSound(getHost(), "SE_BV_D_PAKKUN_EGG_CREAK", -1, -1);
        MR::startSound(getHost(), "SE_BM_D_PAKKUN_SLAVER", -1, -1);
        MR::startSound(getHost(), "SE_BM_D_PAKKUN_EGG_CREAK", -1, -1);
    }

    if (MR::isStep(this, 118)) {
        MR::startSound(getHost(), "SE_BM_D_PAKKUN_EGG_DIG_OUT", -1, -1);
        MR::startSound(getHost(), "SE_BV_D_PAKKUN_EGG_GROAN", -1, -1);
        MR::startSound(getHost(), "SE_BM_D_PAKKUN_SLAVER", -1, -1);
    }

    if (MR::isStep(this, 245)) {
        MR::startSound(getHost(), "SE_BM_D_PAKKUN_TAIL_ATTACK", -1, -1);
    }

    if (MR::isBckStopped(getHost())) {
        MR::startStageBGM("MBGM_GALAXY_INTER", false);
        getHost()->mDemoPos->endDemo();
        getHost()->resetPosition();
        getHost()->endDemo("ディノパックン開始デモ");
        MR::endAnimCamera(getHost(), getHost()->mCameraInfo, "OpeningDemo", -1, true);
        getHost()->activateParts();
        MR::validateCollisionParts(getHost()->getEggShell());
        kill();
    }
}

void DinoPackunDemo::exeCryDemo() {
    if (MR::isFirstStep(this)) {
        MR::zeroVelocity(getHost());
        MR::stopStageBGM(30);
        getHost()->startDemoAndReset();
        MR::startAnimCameraTargetSelf(getHost(), getHost()->mCameraInfo, "CryDemo", 0, 1.0f);
        MR::startAction(getHost(), "CryDemo");
        MR::startBckPlayer("BattleWait", static_cast< const char* >(0));
    }

    if (MR::isStep(this, 100)) {
        MR::startCenterScreenBlur(20, 12.0f, 0x50, 5, 10);
    }

    if (MR::isBckStopped(getHost())) {
        MR::startBossBGM(4);
        getHost()->endDemo("ディノパックン泣きデモ");
        MR::endAnimCamera(getHost(), getHost()->mCameraInfo, "CryDemo", -1, -1);
        getHost()->activateParts();
        kill();
    }
}

void DinoPackunDemo::exeAngryDemo() {
    if (MR::isFirstStep(this)) {
        MR::stopStageBGM(30);
        getHost()->startDemoAndReset();
        MR::startAnimCameraTargetSelf(getHost(), getHost()->mCameraInfo, "AngryDemo", 0, 1.0);
        MR::startAction(getHost(), "AngryDemo");
        MR::startSound(getHost(), "SE_BV_D_PAKKUN_EGG_GROAN", -1, -1);
        MR::startSound(getHost(), "SE_BM_D_PAKKUN_SLAVER", -1, -1);
        MR::startBckPlayer("BattleWait", static_cast< const char* >(0));
    }
    if ((getHost()->mSequence->getVsCount()) == 1) {
        MR::startLevelSound(getHost(), "SE_BM_LV_D_PAKKUN_ANGRY", -1, -1, -1);
        if (MR::isStep(this, 99)) {
            MR::startCenterScreenBlur(80, 18.0, 0x50u, 5, 30);
        }
    }
    if ((getHost()->mSequence->getVsCount()) == 2) {
        if (MR::isLessStep(this, 205)) {
            MR::startLevelSound(getHost(), "SE_BM_LV_D_PAKKUN_ANGRY", -1, -1, -1);
        }
        if (MR::isStep(this, 220)) {
            MR::startCenterScreenBlur(80, 18.0, 0x50u, 5, 30);
        }
    }
    if (MR::isBckStopped(getHost())) {
        MR::startBossBGM(5);
        getHost()->endDemo("ディノパックン怒りデモ");
        MR::endAnimCamera(getHost(), getHost()->mCameraInfo, "AngryDemo", -1, 1);
        getHost()->activateParts();
        kill();
    }
}