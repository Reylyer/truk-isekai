#define FREEGLUT_STATIC

#include <string>
#include <chrono>
#include <iostream>

#include <GL/freeglut.h>
#include <Scene.hpp>
#include <Game.hpp>

#include <objects/car.hpp>
#include <objects/truck.hpp>
#include <objects/truck_vico.hpp>
#include <objects/truck_david.hpp>
#include <objects/truck_dimas.hpp>



using std::string;

class SelectScene: public Scene{
    public:
        SelectScene(Game &game, string name): Scene(game, name){
            setup();
            Truck * truck1 = new Truck();
            objects.insert({"truck1", truck1});

            TruckVico * truck2 = new TruckVico();
            objects.insert({"truck2", truck2});

            TruckVico * truck3 = new TruckVico(20, 0, 0);
            objects.insert({"truck3", truck3});

            TruckVico * truck4 = new TruckVico(-20, 0, 0);
            objects.insert({"truck4", truck4});

            Car *car1 = new Car("res/obj/car.obj", "res/bmp/car_2.bmp");
            objects.insert({"mobil", car1});
        }
        void setup() override{
            view();
        }
        void update() override{
            if(game->KEY_PRESSED['q']){
                printf("q pressed\n");
                game->change_scene("Menu");
                reset();
            }
            render();
        }

    private:
        void render(){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            view();

            // gambar semua sceneObject
            for(auto & scene_object: this->objects){
                if(scene_object.second->is_active){
                    scene_object.second->render();
                }
            }
            glutWireCube(1);
            
            glClearColor(0., .5, 0.5, 1.0);
        }

        void view(){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0, 0, game->WIN_SIZE_W, game->WIN_SIZE_H);
            gluPerspective(45, game->RATIO, 0.1, 1000);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(
                2, 2, -2,
                0, 2, 0,
                0., 1., 0.
            );
        }
        void reset(){}
};
