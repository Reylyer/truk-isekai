#ifndef _GAME_INCLUDED
    #define _GAME_INCLUDED

    #include <map>
    #include <string>
    #include <chrono>

    #include "Scene.hpp"

    using std::map,
        std::string;

    class Game{
        // public vars
        public:
            // https://stackoverflow.com/a/866716/14052716
            bool  KEY_PRESSED[255];
            int   MOUSE_POSITION_X,
                MOUSE_POSITION_Y;
            int   WIN_SIZE_W,
                WIN_SIZE_H;
            float RATIO;
            // https://stackoverflow.com/a/21385166/14052716
            map<string, Scene *> scenes;
            Scene *active_scene;
            
            std::chrono::high_resolution_clock::time_point last_time;

        // core methods
        public:
            // initialization, binding all scenes
            Game();
            void update();

        // scenes methods
        public:
            void add_scene(Scene &Scene);
            void change_scene(Scene &scene);
            void change_scene(string scene_name);

        // callback methods
        public:
            void reshapeCallback(int w, int h);
            void passiveMouseCallback(int x, int y);
            void keyboardPressCallback(unsigned char key, int xn, int yn);
            void keyboardReleaseCallback(unsigned char key, int xn, int yn);
    };
#endif