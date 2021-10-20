#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Character{
    int x;
    int y;
    std::string name;
    Character(std::string _name) : name(_name){
    }
    void move(int _x, int _y){
        x = _x;
        y = _y;
    }
};

class Command{
    public:
    virtual ~Command(){}
    virtual void execute(Character& c) = 0;
    virtual void undo(Character&c) = 0;
};

class Move: public Command{
    public:
    void execute(Character& c){
        int randomx = rand() %4; 
        int randomy = rand() %4; 
        c.move(randomx,randomy);
        x = randomx;
        y = randomy;
        std::cout << c.name << " moved " << x << "," << y << std::endl;
    }
    void undo(Character& c){
        c.move(-x,-y);
        std::cout << c.name << " undo " << -x << "," << -y << std::endl;
    }
    private:
    int x;
    int y;
};



int main(){
    srand(time(NULL));

    Character mike("mike");;
    std::vector<Command*> command_queue;

    Move* m1 = new Move;
    command_queue.push_back(m1);
    Move* m2 = new Move;
    command_queue.push_back(m2);
    Move* m3 = new Move;
    command_queue.push_back(m3);
    Move* m4 = new Move;
    command_queue.push_back(m4);

    for(int i=0; i < command_queue.size(); i++){
        command_queue[i]->execute(mike); 
    }

    for(int i=command_queue.size()-1; i > -1; i--){
        command_queue[i]->undo(mike); 
    }

    // And of course some cleanup...
    for(int i=0; i < command_queue.size(); i++){
        delete command_queue[i];
    }

    return 0;
}
