#include <string>
#include <memory>

class IGameObject{
    public:

        virtual ~IGameObject() {}
        virtual void Update() = 0;
        virtual void Render() = 0;
};

class Plane : public IGameObject{
    public:
        Plane() {}
        void Update() {}
        void Render() {}
};

class Boat: public IGameObject{
    public:
        Boat() {}
        void Update() {}
        void Render() {}

};

enum class ObjectType {PLANE, BOAT};

std::shared_ptr<IGameObject> MakeGameObjectFactory(ObjectType type){
    if(ObjectType::PLANE==type){
        return std::make_shared<Plane>();
    }else if(ObjectType::BOAT==type){
        return std::make_shared<Boat>();
    } 
    return nullptr;
}


int main(){

    std::shared_ptr<IGameObject> myObject = MakeGameObjectFactory(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myObject2 = MakeGameObjectFactory(ObjectType::BOAT);
    return 0;
}
