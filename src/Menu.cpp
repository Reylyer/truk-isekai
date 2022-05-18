#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <Menu.hpp>
#include <Scene.hpp>
#include <Game.hpp>
#include <string>
#include <iostream>

using std::string;


Menu::Menu(Game &game, string name): Scene(game, name){
    printf("MENUUUU\n");
};
void Menu::update(){
    printf("Menu Updating\n");

    if(game->KEY_PRESSED['w']){
        printf("w pressed\n");
        game->change_scene("MainScene");
        reset();
    }
    render();
}
void Menu::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    printf("Menu\n");

    for(auto & scene_object: this->objects){
        if(scene_object.second.is_active)
            scene_object.second.render();
    }

    glClearColor(0.2, 0.3, 0.4, 1);
    // glColor3ub(255, 255, 255);
    // glBegin(GL_TRIANGLE_FAN);

    // glEnd();
    // glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char *>( "ini menu ya memek"));
}
void Menu::reset(){}