#include "Scene.hpp"
#include "Game.hpp"
#include <string>

using std::string;

class Menu: public Scene{
    public:
        Menu(Game &game, string name);
        void update() override;
    private:
        void render();
        void reset();
};