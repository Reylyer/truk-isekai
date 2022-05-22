#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <Game.hpp>
#include <string>
#include <iostream>
#include <algorithm>
using   std::string,
        std::min,
        std::max;

class Menu: public Scene{
    private:
    // quit 0
        int select = 3;
        int key_select;

    public:
        Menu(Game &game, string name): Scene(game, name){
            setup();
            printf("Selamat datang di menu\n");
        }
        void update() override{

            if(game->KEY_PRESSED['w']){
                printf("w pressed\n");
                key_select = 'w';
            } else if(game->KEY_PRESSED['s']){
                printf("s pressed\n");
                key_select = 's';
            } else if(game->KEY_PRESSED[13]){
                printf("enter pressed\n");
                key_select = 13;
            }

            if(!game->KEY_PRESSED[key_select] && key_select){
                switch (key_select){
                    case 'w':
                        this->select++;
                        break;
                    case 's':
                        this->select--;
                        break;
                    case 13:
                        switch (select){
                            // quit
                            case 0:
                                glutLeaveMainLoop();
                                break;
                            // option
                            case 1:
                                break;
                            // select trug
                            case 2:
                                game->change_scene("SelectScene");
                                break;
                            // play
                            case 3:
                                game->change_scene("MainScene");
                        }
                }   

                key_select = 0;
                this->select = min(3, max(0, this->select));
            }

            render();
        }

        void setup() override{
            view();
        }

    private:
        void render(){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            view();

            glClearColor(0.2, 0.3, 0.4, 1);

            // active background
            glColor4f(1, 1, 1, 0.1);
            int container_height= game->WIN_SIZE_H*4/5;
            glRectf(game->WIN_SIZE_W/3,   container_height/5*(select + 1) + container_height/5/2, 
                    game->WIN_SIZE_W/3*2, container_height/5*(select + 1) - container_height/5/2);

            glColor4f(0.0f, 0.0f, 1.0f, 1.0f);  //RGBA values of text color
            drawCenteredString(GLUT_BITMAP_HELVETICA_18,
                                (unsigned char*)"PLAY", 
                                game->WIN_SIZE_W/2, 
                                container_height/5*4);
            drawCenteredString(GLUT_BITMAP_HELVETICA_18,
                                (unsigned char*)"SELECT TRUGGG", 
                                game->WIN_SIZE_W/2, 
                                container_height/5*3);
            drawCenteredString(GLUT_BITMAP_HELVETICA_18,
                                (unsigned char*)"OPTION", 
                                game->WIN_SIZE_W/2, 
                                container_height/5*2);
            drawCenteredString(GLUT_BITMAP_HELVETICA_18,
                                (unsigned char*)"QUIT", 
                                game->WIN_SIZE_W/2, 
                                container_height/5);

        }

        void reset(){
            select = 0;
            key_select = 0;
        }

        void view(){
            glMatrixMode(GL_PROJECTION);
            // setup biar pakai koordinat cartesian
            // dimana 0, 0 kiri bawah
            glLoadIdentity();
            glViewport(0, 0, game->WIN_SIZE_W, game->WIN_SIZE_H);
            gluOrtho2D(0, game->WIN_SIZE_W, 0, game->WIN_SIZE_H);

            // bersihin matrix model view
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }

        void drawCenteredString(void *font, const unsigned char *string, int x, int y){
            glRasterPos2i(x - glutBitmapLength(font, string)/2,
                          y - glutBitmapHeight(font)/2);            //Top left corner of text
                // Since 2nd argument of glutBitmapString must be const unsigned char*
            glutBitmapString(font, string);
        }
};
