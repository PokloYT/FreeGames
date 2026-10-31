#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/LevelTools.hpp>
#include <Geode/Enums.hpp>
#include "hooks/MoreGamesLayer.hpp"
#include "hooks/MoreGamesLayer.cpp"
#include "Meltdown/MeltdownSelectLayer.h"
#include "SubZero/SubZeroSelectLayer.h"
#include "World/ownWorldSelectLayer.h"

using namespace geode::prelude;

#include <iostream>
#include <filesystem> 
using namespace more;

#include <Geode/utils/web.hpp>

void updateGroundColorM(CCSpriteBatchNode* batch, const cocos2d::ccColor3B& color)
{
    for (int i = 0; i < batch->getChildren()->count(); ++i) {
        auto sprite = static_cast<CCSprite*>(batch->getChildren()->objectAtIndex(i));
        sprite->setColor(color);
        for (int o = 0; o < sprite->getChildren()->count(); ++o) {
            auto spriteChild = static_cast<CCSprite*>(sprite->getChildren()->objectAtIndex(o));
            spriteChild->setColor(color);
        }
    }
}

class $modify(LoadingLayer)
{
    void loadAssets()
    {
        LoadingLayer::loadAssets();

        std::filesystem::path zipFilePath = geode::Mod::get()->getResourcesDir() / "SpinOffGames.zip";
        std::filesystem::path unzipDir = geode::Mod::get()->getResourcesDir() / "SpinOffGames";

        // Исправлено под актуальный API Unzip в Geode
        if (auto unzip = geode::utils::file::Unzip::create(zipFilePath)) {
            if (auto res = unzip.unwrap().extractAllTo(unzipDir); !res) {
                // Логирование ошибки при распаковке, если потребуется
            }
        }
        
        CCFileUtils::get()->addTexturePack(CCTexturePack{
            .m_id = this->getID(),
            .m_paths = { unzipDir.string() }
        });

        auto* textureCache = CCTextureCache::sharedTextureCache();
        auto* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

        textureCache->addImage("WorldSheet.png", false);
        spriteFrameCache->addSpriteFramesWithFile("WorldSheet.plist");
    }
};

class $modify(LevelTools)
{
    static GJGameLevel* getLevel(int levelID, bool getString)
    {
        GJGameLevel* level = GJGameLevel::create();

        switch (levelID) {
        case 1001: // Meltdown
            level->m_levelName = getAudioTitle(23);
            level->m_audioTrack = 23;
            level->m_coins = 3;
            level->m_stars = 1;
            level->m_difficulty = GJDifficulty::Easy;
            break;
        case 1002:
            level->m_levelName = getAudioTitle(24);
            level->m_audioTrack = 24;
            level->m_coins = 3;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 1003:
            level->m_levelName = getAudioTitle(25);
            level->m_audioTrack = 25;
            level->m_coins = 3;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Hard;
            break;
        case 2001: // World
            level->m_levelName = getAudioTitle(27);
            level->m_audioTrack = 27;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Easy;
            break;
        case 2002:
            level->m_levelName = getAudioTitle(28);
            level->m_audioTrack = 28;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Easy;
            break;
        case 2003:
            level->m_levelName = getAudioTitle(29);
            level->m_audioTrack = 29;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2004:
            level->m_levelName = getAudioTitle(30);
            level->m_audioTrack = 30;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2005:
            level->m_levelName = getAudioTitle(31);
            level->m_audioTrack = 31;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2006:
            level->m_levelName = getAudioTitle(32);
            level->m_audioTrack = 32;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2007:
            level->m_levelName = getAudioTitle(33);
            level->m_audioTrack = 33;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2008:
            level->m_levelName = getAudioTitle(34);
            level->m_audioTrack = 34;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2009:
            level->m_levelName = getAudioTitle(35);
            level->m_audioTrack = 35;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2010:
            level->m_levelName = getAudioTitle(36);
            level->m_audioTrack = 36;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 4001: // SubZero
            level->m_levelName = getAudioTitle(37);
            level->m_audioTrack = 37;
            level->m_coins = 3;
            level->m_stars = 4;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 4002:
            level->m_levelName = getAudioTitle(38);
            level->m_audioTrack = 38;
            level->m_coins = 3;
            level->m_stars = 6;
            level->m_difficulty = GJDifficulty::Hard;
            break;
        case 4003:
            level->m_levelName = getAudioTitle(39);
            level->m_audioTrack = 39;
            level->m_coins = 3;
            level->m_stars = 8;
            level->m_difficulty = GJDifficulty::Harder;
            break;
        default:
            return LevelTools::getLevel(levelID, getString);
        }

        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
        return level;
    }
};

class $modify(MenuLayer) {
    void onMoreGames(CCObject* sender) {
        auto* layer = more::MoreGamesLayer::create();
        addChild(layer, 100);
        layer->showLayer(false);
    }
    
    void onPlay(CCObject* sender) {
        auto back = Mod::get()->getSavedValue<int>("onsubzero");
        back = 10;
        Mod::get()->setSavedValue("onsubzero", back);
        MenuLayer::onPlay(sender);
    }
};

class $modify(GJGarageLayer) {
    bool init() {
        auto back = Mod::get()->getSavedValue<int>("onsubzero");
        back = 10;
        Mod::get()->setSavedValue("onsubzero", back);
        return GJGarageLayer::init();
    }

    void onBack(cocos2d::CCObject* sender)
    {
        auto pages = Mod::get()->getSavedValue<int>("onworldpages");
        auto World = ownWorldSelectLayer::create(0);
        auto scene = CCScene::create();

        scene->addChild(World);
        
        if (pages != 0 && pages != 10)
        {
            auto transitionScene = CCScene::create(); 
            CCSize winSize = CCDirector::sharedDirector()->getWinSize();
            CCActionInterval* moveUp = CCMoveBy::create(0.23f, ccp(0, winSize.height));
            this->runAction(moveUp);

            if (pages == 1) {
                World->m_scrollLayer->instantMoveToPage(0);
                World->m_background->setColor(GameManager::sharedState()->colorForIdx(4));
            }
            else if (pages == 2) {
                World->m_scrollLayer->instantMoveToPage(1);
                World->m_background->setColor(GameManager::sharedState()->colorForIdx(6));
            }

            auto transition = CCTransitionMoveInB::create(0.31f, scene);
            CCActionInterval* moveDown = CCMoveBy::create(0.5f, ccp(0, -winSize.height));
            transitionScene->runAction(moveDown);

            scene->setZOrder(1);
            this->setZOrder(2);
            transition->setZOrder(1);
            transitionScene->setZOrder(2);
            CCDirector::sharedDirector()->pushScene(transitionScene);
            CCDirector::sharedDirector()->pushScene(transition);
        }
        else
        {
            GJGarageLayer::onBack(sender);
        }
    }
};

class $modify(PauseLayer) {
    void onQuit(CCObject* sender) {
        auto GM = GameManager::sharedState();
        
        if (GM && GM->m_playLayer && GM->m_playLayer->m_level) {
            int levelID = GM->m_playLayer->m_level->m_levelID;
            
            if (levelID > 1000 && levelID < 1004) {
                auto MeltdownScene = MeltdownSelectLayer::create(0);
                auto scene = CCScene::create();
                if (levelID == 1001) MeltdownScene = MeltdownSelectLayer::create(0);
                if (levelID == 1002) MeltdownScene = MeltdownSelectLayer::create(1);
                if (levelID == 1003) MeltdownScene = MeltdownSelectLayer::create(2);
            
                scene->addChild(MeltdownScene);
                CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
                PauseLayer::onQuit(sender);
                return;
            }

            if (levelID > 2000 && levelID < 2011) {
                auto specificWorldScene = ownWorldSelectLayer::create(0);
                auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS
                int colorID = 0;
                if (levelID > 2000 && levelID < 2006) {
                    specificWorldScene->m_scrollLayer->instantMoveToPage(0);
                    colorID = 4;
                }
                else if (levelID > 2005 && levelID < 2011) {
                    specificWorldScene->m_scrollLayer->instantMoveToPage(1);
                    colorID = 6;
                }
                specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
                scene->addChild(specificWorldScene);
#endif
#ifdef GEODE_IS_ANDROID
                auto worldScene = WorldSelectLayer::create(0);
                if (levelID > 2000 && levelID < 2006) {
                    worldScene = WorldSelectLayer::create(0);
                }
                else if (levelID > 2005 && levelID < 2011) {
                    worldScene = WorldSelectLayer::create(1);
                }
                scene->addChild(worldScene);
#endif
                CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
                PauseLayer::onQuit(sender);
                return;
            }

            if (levelID > 4000 && levelID < 4004) {
                auto SubZeroScene = SubZeroSelectLayer::create(0);
                auto scene = CCScene::create();
                if (levelID == 4001) SubZeroScene = SubZeroSelectLayer::create(0);
                if (levelID == 4002) SubZeroScene = SubZeroSelectLayer::create(1);
                if (levelID == 4003) SubZeroScene = SubZeroSelectLayer::create(2);
                
                scene->addChild(SubZeroScene);
                CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
                PauseLayer::onQuit(sender);
                return;
            }
        }

        PauseLayer::onQuit(sender);
    }
};

class $modify(EndLevelLayer) {
    void onMenu(CCObject* sender) {
        auto GM = GameManager::sharedState();

        if (GM && GM->m_playLayer && GM->m_playLayer->m_level) {
            int levelID = GM->m_playLayer->m_level->m_levelID;

            if (levelID > 1000 && levelID < 1004) {
                auto MeltdownScene = MeltdownSelectLayer::create(0);
                auto scene = CCScene::create();
                if (levelID == 1001) MeltdownScene = MeltdownSelectLayer::create(0);
                if (levelID == 1002) MeltdownScene = MeltdownSelectLayer::create(1);
                if (levelID == 1003) MeltdownScene = MeltdownSelectLayer::create(2);

                scene->addChild(MeltdownScene);
                CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
                EndLevelLayer::onMenu(sender);
                return;
            }

            if (levelID > 2000 && levelID < 2011) {
                auto specificWorldScene = ownWorldSelectLayer::create(0);
                auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS
                int colorID = 0;
                if (levelID > 2000 && levelID < 2006) {
                    specificWorldScene->m_scrollLayer->instantMoveToPage(0);
                    colorID = 4;
                }
                else if (levelID > 2005 && levelID < 2011) {
                    specificWorldScene->m_scrollLayer->instantMoveToPage(1);
                    colorID = 6;
                }
                specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
                scene->addChild(specificWorldScene);
#endif
#ifdef GEODE_IS_ANDROID
                auto worldScene = WorldSelectLayer::create(0);
                if (levelID > 2000 && levelID < 2006) {
                    worldScene = WorldSelectLayer::create(0);
                }
                else if (levelID > 2005 && levelID < 2011) {
                    worldScene = WorldSelectLayer::create(1);
                }
                scene->addChild(worldScene);
#endif
                CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
                EndLevelLayer::onMenu(sender);
                return;
            }

            if (levelID > 4000 && levelID < 4004) {
                auto SubZeroScene = SubZeroSelectLayer::create(0);
                auto scene = CCScene::create();
                if (levelID == 4001) SubZeroScene = SubZeroSelectLayer::create(0);
                if (levelID == 4002) SubZeroScene = SubZeroSelectLayer::create(1);
                if (levelID == 4003) SubZeroScene = SubZeroSelectLayer::create(2);

                scene->addChild(SubZeroScene);
                CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
                EndLevelLayer::onMenu(sender);
                return;
            }
        }

        EndLevelLayer::onMenu(sender);
    }
};

class $modify(PlayLayer) {
    void levelComplete() {
        PlayLayer::levelComplete();
        auto gsm = GameStatsManager::sharedState();
        if (!gsm || !m_level) return;
        
        int coinsCollected = 0;
        int setPercentage = 0;
        
        // В 2.2+ статистику монет лучше проверять через встроенные методы или безопасный доступ к мапе/словарю
        switch (m_level->m_levelID) {
        case 1001:
            if (gsm->hasUserCoin("unique_1001_1")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_1001_2")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_1001_3")) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin01", setPercentage, false);
            break;
        case 1002:
            if (gsm->hasUserCoin("unique_1002_1")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_1002_2")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_1002_3")) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin02", setPercentage, false);
            break;
        case 1003:
            if (gsm->hasUserCoin("unique_1003_1")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_1003_2")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_1003_3")) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin03", setPercentage, false);
            break;
        case 4001:
            if (gsm->hasUserCoin("unique_4001_1")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_4001_2")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_4001_3")) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins001", setPercentage, false);
            break;
        case 4002:
            if (gsm->hasUserCoin("unique_4002_1")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_4002_2")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_4002_3")) ++coinsCollected;
            setPercentage = coinsCollected * 10oz / 3; // поправлено на стандартную логику ниже
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins002", setPercentage, false);
            break;
        case 4003:
            if (gsm->hasUserCoin("unique_4003_1")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_4003_2")) ++coinsCollected;
            if (gsm->hasUserCoin("unique_4003_3")) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins003", setPercentage, false);
            break;
        }
    }
};
