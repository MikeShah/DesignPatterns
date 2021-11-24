#include <iostream>
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

class FactoryGameObjects{
    public:

    static std::shared_ptr<IGameObject> CreateObject(ObjectType type){
        if(ObjectType::PLANE==type){
            s_plane++;
            return std::make_shared<Plane>();
        }else if(ObjectType::BOAT==type){
            s_boats++;
            return std::make_shared<Boat>();
        } 
        return nullptr;
    }


    static void PrintCounts(){
        std::cout << "planes: " << s_plane << std::endl;
        std::cout << "boats : " << s_boats << std::endl;
    }

    private:
        FactoryGameObjects(){}
        ~FactoryGameObjects() {}
        FactoryGameObjects(const FactoryGameObjects& o){}

    static int s_plane;
    static int s_boats;
};




int FactoryGameObjects::s_plane = 0;
int FactoryGameObjects::s_boats= 0;

int main(){

//    std::shared_ptr<IGameObject> myObject = MakeGameObjectFactory(ObjectType::PLANE);
//    std::shared_ptr<IGameObject> myObject2 = MakeGameObjectFactory(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myObject = FactoryGameObjects::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myObject2 = FactoryGameObjects::CreateObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myObject3 = FactoryGameObjects::CreateObject(ObjectType::BOAT);

    FactoryGameObjects::PrintCounts();

    return 0;
}
