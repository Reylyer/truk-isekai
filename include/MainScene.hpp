#ifndef _MAINSCENE_INCLUDED
    #define _MAINSCENE_INCLUDED

    #include "Scene.hpp"
    #include "Game.hpp"
    #include <string>

    using std::string;

    class MainScene: public Scene{
        public:
            MainScene(Game &game, string name);
            void setup() override;
            void update() override;
        private:
            void render();
            void view();
            void reset();
    };
#endif