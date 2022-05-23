#define FREEGLUT_STATIC

#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>

#include <GL/freeglut.h>
#include <Scene.hpp>
#include <Game.hpp>

#include <objects/car.hpp>
#include <objects/truck.hpp>
#include <objects/truck_vico.hpp>
#include <objects/truck_david.hpp>
#include <objects/truck_dimas.hpp>

// dirty 
// https://www.geeksforgeeks.org/how-to-check-whether-a-number-is-in-the-rangea-b-using-one-comparison/
                
#define INRANGE(low, high, x) ((x-high)*(x-low) <= 0)

using   std::string,
        std::min,
        std::max,
        std::fmin,
        std::fmax;

class SelectScene: public Scene{
    private:
        int select_truck;
        int prev_truck;
        int key_select;
        int move = 0;
        float t2t = 20; // truck 2 truck
        int lock = 0;

    public:
        SelectScene(Game &game, string name): Scene(game, name){
            Truck      *truck1 = new Truck(0, 0, 0);
            TruckVico  *truck2 = new TruckVico(t2t, 0, 0);
            TruckDavid *truck3 = new TruckDavid(2*t2t, 0, 0);
            TruckDimas *truck4 = new TruckDimas(3*t2t, 0, 0);

            object_vect.push_back(truck1);
            object_vect.push_back(truck2);
            object_vect.push_back(truck3);
            object_vect.push_back(truck4);

            setup();
        }

        void setup() override{
            this->lock = 60;
            this->select_truck = game->player_truck;
            this->prev_truck = this->select_truck;
        }

        void update() override{
            if(!lock){

                if(game->KEY_PRESSED['d']){
                    printf("d pressed\n");
                    key_select = 'd';
                } else if(game->KEY_PRESSED['a']){
                    printf("a pressed\n");
                    key_select = 'a';
                } else if(game->KEY_PRESSED[13]){
                    key_select = 13;
                }

                if(!game->KEY_PRESSED[key_select] && key_select){
                    this->prev_truck = this->select_truck;
                    switch (key_select){
                        case 'd':
                            this->select_truck++;
                            this->move = -60;
                            break;
                        case 'a':
                            this->select_truck--;
                            this->move = 60;
                            break;
                        case 13:
                            game->player_truck = this->select_truck;
                            game->change_scene("Menu");
                    }   
                    key_select = 0;
                    if(this->select_truck < 0){
                        this->select_truck = 0;
                        this->move = 0;
                    } else if(this->select_truck > 3){
                        this->select_truck = 3;
                        this->move = 0;
                    }
                }
            }
            if(lock) lock--; 
            render();
        }

    private:
        void render(){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0., .5, 0.5, 1.0);
            view();

            glPushMatrix();
                // geser
                glScalef(0.3, 0.3, 0.3);

                // std::cout << move << "\n";
                float interpolated_position = select_truck + move/60.;
                std::cout << this->move << " " << interpolated_position<< "\n";
                interpolated_position = fmin(3, fmax(0, interpolated_position));
                if(move){
                    printf("succc");
                    if(move > 0) move-=4;
                    if(move < 0) move+=4;
                }
                glTranslatef(-interpolated_position*t2t, 0, 0);

                // gambar semua sceneObject
                for(auto & scene_object: this->object_map){
                    if(scene_object.second->is_active){
                        scene_object.second->render();
                    }
                }
                for(auto & scene_object: this->object_vect){
                    if(scene_object->is_active){
                        scene_object->render();
                    }
                }

            glPopMatrix();

            glColor3f(1,1,1);
            glBegin(GL_QUADS);
                glVertex3f(-100, 0, -100);
                glVertex3f(-100, 0, 100);
                glVertex3f(100, 0, 100);
                glVertex3f(100, 0, -100);
            glEnd();
        }

        void view(){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0, 0, game->WIN_SIZE_W, game->WIN_SIZE_H);
            gluPerspective(45, game->RATIO, 0.1, 1000);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(
                -10, 5, 10,
                0, 2, 0,
                0., 1., 0.
            );
        }
        void reset(){}

        void grid(){
                double i; 
                const float Y_MIN = -50, Y_MAX = 50; 
                const float X_MIN = -50, X_MAX = 50; 
                const float Z_MIN = -50, Z_MAX = 50;
                const float gap = 1.0; 
                glColor3f(0.5, 0.5, 0.5); 
                glBegin(GL_LINES); 
                for(i=Y_MIN;i<Y_MAX;i+=gap) 
                { 
                    glVertex3f(i, Y_MIN, 0); 
                    glVertex3f(i, Y_MAX, 0); 
                } 
                for(i=X_MIN;i<X_MAX;i+=gap) 
                { 
                glVertex3f(X_MIN, i, 0); 
                glVertex3f(X_MAX, i, 0); 
                } 
                
                glColor3f(0.5, 0.0, 0.0); 
                glBegin(GL_LINES);
                for(i=Z_MIN;i<Z_MAX;i+=gap) 
                { 
                    glVertex3f(i, 0, Z_MIN); 
                    glVertex3f(i, 0, Z_MAX); 
                } 
                for(i=X_MIN;i<X_MAX;i+=gap) 
                { 
                glVertex3f(X_MIN, 0, i); 
                glVertex3f(X_MAX, 0, i); 
                } 
                
                glColor3f(0.0, 0.5, 0.0); 
                glBegin(GL_LINES);
                for(i=Y_MIN;i<Y_MAX;i+=gap) 
                { 
                    glVertex3f(0, Y_MIN, i); 
                    glVertex3f(0, Y_MAX, i); 
                } 
                for(i=Z_MIN;i<Z_MAX;i+=gap) 
                { 
                    glVertex3f(0, i, Z_MIN); 
                    glVertex3f(0, i, Z_MAX); 
                }
                glEnd(); 
        }
};
