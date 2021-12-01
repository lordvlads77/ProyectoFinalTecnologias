#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& gameObjects, std::vector<GameObject*>*& gameObjectsDeleteList)
{
  this->gameObjects = gameObjects;
  this->gameObjectsDeleteList = gameObjectsDeleteList;
}

ContactEventManager::~ContactEventManager()
{
  
}

void ContactEventManager::BeginContact(b2Contact* contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(actorA && actorB)
  {
    std::cout << "Collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    if(actorB->GetTagName().compare("chest")==0)
    {
      gameObjectsDeleteList->push_back(actorB);
      std::cout<< "Felicidades Caballero Dorado! Has Ganado" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matación, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy2")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matacion, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy3")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matacion, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy4")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matación, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy5")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matacion, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy6")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matacion, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy7")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matacion, suerte para la proxima" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy8")==0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<< "wuah wuaah wuaaah, te han echo la matacion, suerte para la proxima" << std::endl;
    }
  }
}

void ContactEventManager::EndContact(b2Contact* contact)
{

}