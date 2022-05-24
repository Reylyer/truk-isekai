#define FREEGLUT_STATIC

#include <cmath>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string.h>
#include <iomanip>
#include <chrono>

#include <Game.hpp>

#define M_PI        3.14159265358979323846
#define onii        using
#define oniichan    using
#define suki        std::cout
#define hentai      std::endl
#define chan        namespace
#define mendokusai  std::chrono

oniichan suki;
oniichan hentai;
onii chan mendokusai;

Game *main_game;

int WIN_SIZE[] = {1280, 720};

void initGL() {

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND); 

    main_game = new Game(WIN_SIZE[0], WIN_SIZE[1]);
}

void handleKeyPress(unsigned char key, int x, int y){
    main_game->keyboardPressCallback(key, x, y);
}
void handleKeyRelease(unsigned char key, int x, int y){
    main_game->keyboardReleaseCallback(key, x, y);
}
void handleReshape(int new_w, int new_h){
    main_game->reshapeCallback(new_w, new_h);
}
void handleMousePosition(int mouse_x, int mouse_y){
    main_game->passiveMouseCallback(mouse_x, mouse_y);
}
void display(){
    main_game->update();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIN_SIZE[0], WIN_SIZE[1]);
    glutCreateWindow("fuck mee");
    glutIgnoreKeyRepeat(0);
    initGL();

    // callbacks
    glutKeyboardFunc(handleKeyPress);
    glutKeyboardUpFunc(handleKeyRelease);
    glutReshapeFunc(handleReshape);
    glutPassiveMotionFunc(handleMousePosition);

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop(); 
    return 0;
} 

