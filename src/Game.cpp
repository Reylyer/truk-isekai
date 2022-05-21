#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include <chrono>

#include <Game.hpp>
#include "MainScene.hpp"
#include "SelectScene.hpp"
#include "Menu.hpp"

using std::map,
      std::string,
      std::pair;

using namespace std::chrono;

// core methods
// initialization, binding all scenes
Game::Game(int w, int h){
    WIN_SIZE_W = w;
    WIN_SIZE_H = h;

    MainScene *main_scene = new MainScene(*this, string("MainScene"));
    scenes.insert({"MainScene", main_scene});

    Menu *menu = new Menu(*this, string("Menu"));
    scenes.insert({"Menu", menu});

    SelectScene *select_scene = new SelectScene(*this, string("SelectScene"));
    scenes.insert({"SelectScene", select_scene});

    // set MainScene menjadi scene yang utama
    change_scene("Menu");

    std::cout << active_scene->name << std::endl;

    // untuk menghitung frame time
    last_time = high_resolution_clock::now();
}

void Game::update(){
    // call update for scene yang sedang active
    active_scene->update();

    // limiting fps, hard coded for now
    high_resolution_clock::time_point now = high_resolution_clock::now();
    milliseconds time_span = duration_cast<milliseconds>(now - last_time);
    last_time = now;
    // std::cout << time_span.count() << std::endl;
    // 33 for 30 fps, 16 for 60 fps, actual: 16 ms sleep is 90 fps
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