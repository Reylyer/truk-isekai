#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <MainScene.hpp>
#include <Scene.hpp>
#include <Game.hpp>
#include <objects/car.hpp>
#include <objects/truck.hpp>
#include <string>
#include <chrono>
#include <iostream>

using std::string;


MainScene::MainScene(Game &game, string name): Scene(game, name){
    setup();
    Truck * truck1 = new Truck();
    objects.insert({"truck", truck1});

    // Car *car1 = new Car("res/obj/car.obj", "res/bmp/car_2.bmp");
    // objects.insert({"mobil", car1});
};

void MainScene::setup(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, game->WIN_SIZE_W, game->WIN_SIZE_H);
    gluPerspective(45, game->RATIO, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0, 10, -20,
        0, 0, 5,
        0., 1., 0.
    );
}

/* TODO:
 * engine
 * 
*/
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

    view();

    // gambar semua sceneObject
    for(auto & scene_object: this->objects){
        if(scene_object.second->is_active){
            scene_object.second->render();
        }
    }
    
    glClearColor(0., .5, 0.5, 1.0);

    glColor3ub(255, 255, 255);
    // glutWireCube(1);

    // //https://stackoverflow.com/a/34470897/14052716
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char *>( "ini main scene bang"));
}

void MainScene::view(){

}

void MainScene::reset(){

}