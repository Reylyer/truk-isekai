#ifndef _SCENE_INCLUDED
    #define _SCENE_INCLUDED

    #include "SceneObject.hpp"
    #include <map>
    #include <string>

    using   std::map,
            std::string;

    class Game;

    class Scene{
        public:
            map<string, SceneObject*> objects;
            Game *game;
            bool is_active = false;
            string name;

        public:
            Scene(Game &game, string name);
            /*
             * This method will be called per frame
             * @param none
            **/
            virtual void update();
            /*
             * This will be called once after initializing
             * @param none
            **/
            virtual void setup();
            virtual void reset();

        private:
            void render();
            void view();
    };
#endif
