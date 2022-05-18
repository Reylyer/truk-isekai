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

// void draw_asphalt(){
//     glColor3f(0.1, 0.1, 0.1);
//     glPushMatrix();
//         glRotatef(-90, 1, 0, 0);
//         glTranslatef(0, 0.01, 0);
//         glRectf(-5, -50, 5, 150);
//     glPopMatrix();
// }

void initGL() {
    glClearColor(0., .5, 0.5, 1.0);

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glEnable(GL_DEPTH_TEST);
    // glutSetCursor(GLUT_CURSOR_NONE);
    
    main_game = new Game();
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIN_SIZE[0], WIN_SIZE[1]);
    glutCreateWindow("fuck mee");
    glutIgnoreKeyRepeat(0); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)
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

