#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <Game.hpp>
#include <string>
#include <iostream>

using std::string;

class Menu: public Scene{
    private:
        int select = 0;

    public:
        Menu(Game &game, string name): Scene(game, name){
            printf("Selamat datang di menu\n");
        };
        void update() override{
            if(game->KEY_PRESSED['w']){
                printf("w pressed\n");
                game->change_scene("MainScene");
                reset();
            }
            printf("p");
            render();
        }
        void setup() override{}

    private:
        void render(){
            view();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for(auto & scene_object: this->objects){
                if(scene_object.second->is_active)
                    scene_object.second->render();
            }

            glClearColor(0.2, 0.3, 0.4, 1);
            glColor4f(0.0f, 0.0f, 1.0f, 1.0f);  //RGBA values of text color
            glRasterPos2f(0, 0);            //Top left corner of text
            const unsigned char* t = reinterpret_cast<const unsigned char *>("text to render");
            // Since 2nd argument of glutBitmapString must be const unsigned char*
            glutBitmapString(GLUT_BITMAP_HELVETICA_18,t);

        }
        void reset(){}
        void view(){}
};
