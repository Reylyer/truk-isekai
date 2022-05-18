#include <windows.h>
#include <Game.hpp>
#include <map>
#include <string>
#include <MainScene.hpp>
#include <Menu.hpp>
#include <iostream>
#include <chrono>

using std::map,
      std::string,
      std::pair;

using namespace std::chrono;

// core methods
// initialization, binding all scenes
Game::Game(){
    MainScene *main_scene = new MainScene(*this, string("MainScene"));
    Menu *menu = new Menu(*this, string("Menu"));
    scenes.insert({"MainScene", main_scene});
    scenes.insert({"Menu", menu});

    // set MainScene menjadi scene yang utama
    std::cout << main_scene->name << std::endl;
    std::cout << menu->name << std::endl;
    printf("Sebelum change scene\n");
    printf("menu %d\n", menu->is_active);
    printf("main %d\n", main_scene->is_active);

    change_scene("Menu");

    std::cout << active_scene->name << std::endl;

    printf("setelah change scene\n");
    printf("menu %d\n", menu->is_active);
    printf("main %d\n", main_scene->is_active);

    printf("Initialized\n");
    last_time = high_resolution_clock::now();
}
void Game::update(){
    //auto active_scene = scenes.find(ACTIVE_SCENE); //.render();
    active_scene->update();
    high_resolution_clock::time_point now = high_resolution_clock::now();
    milliseconds time_span = duration_cast<milliseconds>(now - last_time);
    last_time = now;
    std::cout << time_span.count() << std::endl;
    
    // 33 for 30 fps, 16 for 60 fps
    int time_sleep = 16 - time_span.count();
    if(time_sleep > 0) Sleep(time_sleep);

}

// scenes methods
void Game::change_scene(Scene &scene){
    if(active_scene) active_scene->is_active = false;
    active_scene = &scene;
    active_scene->is_active = true;
}
void Game::change_scene(string scene_name){
    if(active_scene) active_scene->is_active = false;
    active_scene = scenes.find(scene_name)->second;
    active_scene->is_active = true;
}

// callback methods
void Game::reshapeCallback(int w, int h){
    WIN_SIZE_W = w;
    WIN_SIZE_H = h;
    RATIO = (float)WIN_SIZE_W / WIN_SIZE_H;
}
void Game::passiveMouseCallback(int x, int y){
    MOUSE_POSITION_X = x;
    MOUSE_POSITION_Y = y;
}
void Game::keyboardPressCallback(unsigned char key, int xn, int yn){
    KEY_PRESSED[key] = true;
}
void Game::keyboardReleaseCallback(unsigned char key, int xn, int yn){
    KEY_PRESSED[key] = false;
}