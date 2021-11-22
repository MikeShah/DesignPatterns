#include <iostream>
#include <string>
#include <memory>

class IGameObject{
    public:

        virtual ~IGameObject() {}
        virtual void Update() = 0;
        virtual void Render() = 0;
};

class Plane: public IGameObject{
    public:
        Plane(){}
        void Update(){}
        void Render(){}
};
class Boat: public IGameObject{
    public:
        Boat(){}
        void Update(){}
        void Render(){}
};

enum class GameObjectTypes { PLANE, BOAT};

// Our factory pattern
std::shared_ptr<IGameObject> GameObjectFactory(GameObjectTypes object){

    if(GameObjectTypes::PLANE == object){
        return std::make_shared<Plane>();
    }
    else if(GameObjectTypes::PLANE == object){
        return std::make_shared<Boat>();
    }

    return nullptr;

}

int main(){

    std::shared_ptr<IGameObject> myObject = GameObjectFactory(GameObjectTypes::PLANE);

    return 0;
}
