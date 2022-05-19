#include "Scene.hpp"
#include "Game.hpp"
#include <string>

using std::string;

class Menu: public Scene{

    public:
        Menu(Game &game, string name);
        void update() override;
        void setup() override;
    private:
        int select = 0;
    private:
        void render();
        void reset();
};