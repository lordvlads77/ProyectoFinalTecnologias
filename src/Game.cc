#include "CommonHeaders.hh"
#include "Player.hh"
#include "Enemy.hh"
#include "TileGroup.hh"


sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_HARRYP, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
Enemy* enemy{};
GameObject* chest1{};
GameObject* light1{};
GameObject* light2{};
GameObject* light3{};
GameObject* light4{};
GameObject* lightMiddle{};
GameObject* kaboomMiddleLeft{};
GameObject* kaboomMiddleRight{};
Enemy* enemy1{};
Enemy* enemy2{};
Enemy* enemy3{};
Enemy* enemy4{};
Enemy* enemy5{};
Enemy* enemy6{};
Enemy* enemy7{};
Enemy* enemy8{};
GameObject* wall1{};
GameObject* wall2{};
GameObject* wall3{};
GameObject* wall4{};
GameObject* wall5{};
GameObject* wall6Sliced{};
GameObject* wall7Up{};
GameObject* wall8Up{};
GameObject* wall1Down{};
GameObject* wall2Down{};
GameObject* wall3Down{};
GameObject* wall4Down{};
GameObject* wall5Down{};
GameObject* wall6SlicedDown{};
GameObject* wall7Down{};
GameObject* wall8Down{};
GameObject* Pillar1Left{};
GameObject* Pillar1HeadLeft{};
GameObject* Pillar2Left{};
GameObject* Pillar2HeadLeft{};
GameObject* Pillar3Left{};
GameObject* Pillar3HeadLeft{};
GameObject* Pillar1Right{};
GameObject* Pillar1HeadRight{};
GameObject* Pillar2Right{};
GameObject* Pillar2HeadRight{};
GameObject* Pillar3Right{};
GameObject* Pillar3HeadRight{};
GameObject* wall1MidUp{};
GameObject* wall2MidUp{};
GameObject* wall3MidUp{};
GameObject* wall1MidDown{};
GameObject* wall2MidDown{};
GameObject* wall3MidDown{};
GameObject* Pillar1MidLeft{};
GameObject* Pillar1MidLeftHead{};
GameObject* Pillar2MidLeft{};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();

  player1 = new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 500, 100, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 500, 745, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest");
  light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 120, 175, b2BodyType::b2_staticBody, world, window);
  light1->SetTagName("light1");
  light2 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 130, 775, b2BodyType::b2_staticBody, world, window);
  light2->SetTagName("light2");
  light3 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 835, 175, b2BodyType::b2_staticBody, world, window);
  light3->SetTagName("light3");
  light4 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 835, 775, b2BodyType::b2_staticBody, world, window);
  light4->SetTagName("light4");
  lightMiddle = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 500, 525, b2BodyType::b2_staticBody, world, window);
  lightMiddle->SetTagName("lightMiddle");
  enemy1 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 275, 250, 100.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy1->SetTagName("enemy");
  enemy2 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 275, 400, 150.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy2->SetTagName("enemy2");
  enemy3 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 275, 550, 200.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy3->SetTagName("enemy3");
  enemy4 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 275, 700, 225.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy4->SetTagName("enemy4");
  enemy5 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 760, 250, 200.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy5->SetTagName("enemy5");
  enemy6 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 760, 400, 175.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy6->SetTagName("enemy6");
  enemy7 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 760, 550, 150.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy7->SetTagName("enemy7");
  enemy8 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 3, 760, 700, 110.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy8->SetTagName("enemy8");
  wall1 = new Enemy(ASSETS_TILES, 4.f, 32, 32, 0, 0, 100, 65, 2.f, b2BodyType::b2_staticBody, world, window, 2.f, sf::Vector2f(1, 0));
  wall1->SetTagName("WallHorUp1");
  wall2 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 225, 65, b2BodyType::b2_staticBody, world, window);
  wall2->SetTagName("WallHorUp2");
  wall3 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 350, 65, b2BodyType::b2_staticBody, world, window);
  wall3->SetTagName("WallHorUp3");
  wall4 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 475, 65, b2BodyType::b2_staticBody, world, window);
  wall4->SetTagName("WallHorUp4");
  wall5 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 600, 65, b2BodyType::b2_staticBody, world, window);
  wall5->SetTagName("WallHorUp5");
  wall6Sliced = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 725, 65, b2BodyType::b2_staticBody, world, window);
  wall6Sliced->SetTagName("WallHor6UpSliced");
  wall7Up = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 850, 65, b2BodyType::b2_staticBody, world, window);
  wall7Up->SetTagName("Wall7HorUp");
  wall8Up = new GameObject(ASSETS_TILES, 4.f, 8, 32, 0, 0, 928, 65, b2BodyType::b2_staticBody, world, window);
  wall8Up->SetTagName("Wall8HorUp");
  wall1Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 100, 875, b2BodyType::b2_staticBody, world, window);
  wall1Down->SetTagName("WallHorDown1");
  wall2Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 225, 875, b2BodyType::b2_staticBody, world, window);
  wall2Down->SetTagName("WallHorDown2");
  wall3Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 350, 875, b2BodyType::b2_staticBody, world, window);
  wall3Down->SetTagName("WallHorDown3");
  wall4Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 475, 875, b2BodyType::b2_staticBody, world, window);
  wall4Down->SetTagName("WallHorDown4");
  wall5Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 600, 875, b2BodyType::b2_staticBody, world, window);
  wall5Down->SetTagName("WallHorDown5");
  wall6SlicedDown = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 725, 875, b2BodyType::b2_staticBody, world, window);
  wall6SlicedDown->SetTagName("WallHor6DownSliced");
  wall7Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 850, 875, b2BodyType::b2_staticBody, world, window);
  wall7Down->SetTagName("Wall7DownHor");
  wall8Down = new GameObject(ASSETS_TILES, 4.f, 8, 32, 0, 0, 928, 875, b2BodyType::b2_staticBody, world, window);
  wall8Down->SetTagName("Wall8HorDown");
  Pillar1Left = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 100, 300, b2BodyType::b2_staticBody, world, window);
  Pillar1Left->SetTagName("Pillar1Left");
  Pillar1HeadLeft = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 11, 100, 205, b2BodyType::b2_staticBody, world, window);
  Pillar1HeadLeft->SetTagName("Pillar1HeadLeft");
  Pillar2Left = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 100, 475, b2BodyType::b2_staticBody, world, window);
  Pillar2Left->SetTagName("Pillar2Left");
  Pillar2HeadLeft = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 11, 100, 380, b2BodyType::b2_staticBody, world, window);
  Pillar2HeadLeft->SetTagName("Pillar2HeadLeft");
  Pillar3Left = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 100, 650, b2BodyType::b2_staticBody, world, window);
  Pillar3Left->SetTagName("Pillar3Left");
  Pillar3HeadLeft = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 11, 100, 555, b2BodyType::b2_staticBody, world, window);
  Pillar3HeadLeft->SetTagName("Pillar3HeadLeft");
  Pillar1Right = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 900, 275, b2BodyType::b2_staticBody, world, window);
  Pillar1Right->SetTagName("Pillar1Right");
  Pillar1HeadRight = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 11, 900, 180, b2BodyType::b2_staticBody, world, window);
  Pillar1HeadRight->SetTagName("Pillar1HeadRight");
  Pillar2Right = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 900, 475, b2BodyType::b2_staticBody, world, window);
  Pillar2Right->SetTagName("Pillar2Right");
  Pillar2HeadRight = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 11, 900, 380, b2BodyType::b2_staticBody, world, window);
  Pillar2HeadRight->SetTagName("Pillar2HeadRight");
  Pillar3Right = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 900, 650, b2BodyType::b2_staticBody, world, window);
  Pillar3Right->SetTagName("Pillar3Right");
  Pillar3HeadRight = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 11, 900, 555, b2BodyType::b2_staticBody, world, window);
  Pillar3HeadRight->SetTagName("Pillar3HeadRight");
  wall1MidUp = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 375, 375, b2BodyType::b2_staticBody, world, window);
  wall1MidUp->SetTagName("Wall1MidUp");
  wall2MidUp = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 500, 375, b2BodyType::b2_staticBody, world, window);
  wall2MidUp->SetTagName("Wall2MidUp");
  wall3MidUp = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 625, 375, b2BodyType::b2_staticBody, world, window);
  wall3MidUp->SetTagName("Wall3MidUp");
  wall1MidDown = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 375, 650, b2BodyType::b2_staticBody, world, window);
  wall1MidDown->SetTagName("Wall1MidDown");
  wall2MidDown = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 500, 650, b2BodyType::b2_staticBody, world, window);
  wall2MidDown->SetTagName("Wall2MidDown");
  wall3MidDown = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 625, 650, b2BodyType::b2_staticBody, world, window);
  wall3MidDown->SetTagName("Wall3MidDown");
  kaboomMiddleLeft = new GameObject(ASSETS_SPRITES, 12.f, 16, 16, 6, 2, 400, 535, b2BodyType::b2_staticBody, world, window);
  kaboomMiddleLeft->SetTagName("kaboomMiddleLeft");
  kaboomMiddleRight = new GameObject(ASSETS_SPRITES, 12.f, 16, 16, 6, 2, 600, 535, b2BodyType::b2_staticBody, world, window);
  kaboomMiddleRight->SetTagName("kaboomMiddleRight");

  tileGroup = new TileGroup(window, 12, 12, ASSETS_MAPS, 5.3f, 16, 16, ASSETS_TILES);
  contactEventManager = new ContactEventManager(gameObjects, gameObjectsDeleteList);
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);

  AddGameObject(player1);
  AddGameObject(chest1);
  AddGameObject(light1);
  AddGameObject(light2);
  AddGameObject(light3);
  AddGameObject(light4);
  AddGameObject(lightMiddle);
  AddGameObject(enemy1);
  AddGameObject(enemy2);
  AddGameObject(enemy3);
  AddGameObject(enemy4);
  AddGameObject(enemy5);
  AddGameObject(enemy6);
  AddGameObject(enemy7);
  AddGameObject(enemy8);
  AddGameObject(wall1);
  AddGameObject(wall2);
  AddGameObject(wall3);
  AddGameObject(wall4);
  AddGameObject(wall5);
  AddGameObject(wall6Sliced);
  AddGameObject(wall7Up);
  AddGameObject(wall8Up);
  AddGameObject(wall1Down);
  AddGameObject(wall2Down);
  AddGameObject(wall3Down);
  AddGameObject(wall4Down);
  AddGameObject(wall5Down);
  AddGameObject(wall6SlicedDown);
  AddGameObject(wall7Down);
  AddGameObject(wall8Down);
  AddGameObject(Pillar1Left);
  AddGameObject(Pillar1HeadLeft);
  AddGameObject(Pillar2Left);
  AddGameObject(Pillar2HeadLeft);
  AddGameObject(Pillar3Left);
  AddGameObject(Pillar3HeadLeft);
  AddGameObject(Pillar1Right);
  AddGameObject(Pillar1HeadRight);
  AddGameObject(Pillar2Right);
  AddGameObject(Pillar2HeadRight);
  AddGameObject(Pillar3Right);
  AddGameObject(Pillar3HeadRight);
  AddGameObject(wall1MidUp);
  AddGameObject(wall2MidUp);
  AddGameObject(wall3MidUp);
  AddGameObject(wall1MidDown);
  AddGameObject(wall2MidDown);
  AddGameObject(wall3MidDown);
  AddGameObject(kaboomMiddleLeft);
  AddGameObject(kaboomMiddleRight);
  

  textObj1->SetTextStr("Arde mi Poderoso Cosmo Dorado!!!");

  /*circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);*/
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

  //circle->setPosition(player1->GetSprite()->getPosition());

  //lightIdle->Play(deltaTime);

  /*if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }*/
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  for(auto& gameobject: *gameObjectsDeleteList)
  {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameobject), gameObjects->end());
      delete gameobject;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  //player1->Draw();
  //window->draw(*circle);

  tileGroup->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
  //world->DebugDraw();
}

//Keyboard, joysticks, etc.
void Game::Input()
{
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}