#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <MainScene.hpp>
#include <Scene.hpp>
#include <Game.hpp>
#include <string>
#include <chrono>

using std::string;


MainScene::MainScene(Game &game, string name): Scene(game, name){};
void MainScene::update(){
    if(game->KEY_PRESSED['q']){
        printf("q pressed\n");
        game->change_scene("Menu");
        reset();
    }
    render();
}

void MainScene::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    printf("main scene\n");
    for(auto & scene_object: this->objects){
        if(scene_object.second.is_active)
            scene_object.second.render();
    }
    
    glClearColor(0., .5, 0.5, 1.0);

    // glColor3ub(255, 255, 255);
    // glutWireCube(1);

    // //https://stackoverflow.com/a/34470897/14052716
    // glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char *>( "ini main scene bang"));
}

void MainScene::reset(){

}