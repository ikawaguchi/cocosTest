//
//  GameScene.cpp
//  nyan25
//
//  Created by  kawaguchi on 2014/06/30.
//
//

#include "GameScene.h"


using namespace cocos2d;
using namespace std;

Scene *GameScene::scene()
{
    Scene *scene = Scene::create();
    GameScene *layer = GameScene::create();
    scene->addChild(layer);
    
    
    return scene;
}


bool GameScene::init()
{
    if (!Layer::init()){
        return false;
    }
    
    // 乱数を初期化する
    srand((unsigned)time(NULL));
    
    // 背景を作成する
    makeBackground();
    
    // 1~25のカードを配置する
    makeCards();
    
    return true;
}


// 背景を作成する
void GameScene::makeBackground()
{
    // 画面サイズを取得
    auto winSize = Director::getInstance()->getWinSize();
    
    
    // 背景を生成
    auto pBG = Sprite::create("background.png");
    pBG->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(pBG);
    
}

// 1~25のカードを配置する
void GameScene::makeCards()
{
    // 数値配列を初期化する
    Vector<Value> numbers;
    for (int i=1;i<=25;i++){
        numbers.pushBack(Value(i));
    }
    
    // 画面サイズを取得
    auto winSize = Director::getInstance()->getWinSize();
    
    for (int x=0;x<5;x++){
        for(int y=0;y<5;y++){
            //ランダムで１つの値を取得する
            int index = rand() % numbers.size();
            int number = numbers.at(index).asInt();
            
            //カードを生成する
            auto pCard = Sprite::create("card_frontside.png");
            auto cardSize = pCard->getContentSize();
            
            pCard->setPosition(Point(winSize.width * 0.5 + (x - 2) * cardSize.width,
                                     winSize.height * 0.5 + (y - 2) * cardSize.height));
            pCard->setTag(number);
            this->addChild(pCard);
            
            //カード番号を表示
           // auto fileName = Value(<#const std::string &v#>)
            
        }
    }
    
}