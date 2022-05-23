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
#include <objects/asphalt.hpp>

#include <string>
#include <vector>
#include <map>

using std::string,
      std::vector,
      std::map;

class MainScene: public Scene{
    private:
        map<int, SceneObject*> trucks;
        SceneObject* player;

        int lock = 0;
        float truck_steer_direction = 0;

        int aspal_loop_index = 0;
        int aspal_max_loop   = 0;

        Asphalt * asphalt;


    public:
        MainScene(Game &game, string name): Scene(game, name){
            // objects.insert({"truck1", truck1});
            Truck      * truck1 = new Truck();
            TruckVico  * truck2 = new TruckVico();
            TruckDavid * truck3 = new TruckDavid();
            TruckDimas * truck4 = new TruckDimas();
            std::cout << asphalt << std::endl;
            this->asphalt = new Asphalt("res/bmp/car_2.bmp", 50, 50);
            std::cout << asphalt << std::endl;

            if(!asphalt){
                printf("ERROR\n");
            }

            trucks.insert({0, truck1});
            trucks.insert({1, truck2});
            trucks.insert({2, truck3});
            trucks.insert({3, truck4});

            setup();
            // Car *car1 = new Car("res/obj/car.obj", "res/bmp/car_2.bmp");
            // object_map.insert({"mobil", car1});
        }
        void setup() override{
            player = trucks.find(game->player_truck)->second;
        }
        void update() override{
            if(!lock){
                // 1  = kiri
                // -1 = kanan
                if(game->KEY_PRESSED['a']){
                    printf("a pressed\n");
                    lock = 30;
                    truck_steer_direction = 1;
                }
                else if(game->KEY_PRESSED['d']){
                    printf("d pressed\n");
                    lock = 30;
                    truck_steer_direction = -1;
                }
                else if(game->KEY_PRESSED['q']){
                    game->change_scene("Menu");
                }
            }
            
            render();
            if(lock) lock--; 
            else truck_steer_direction = 0;
        }

    private:
        void render(){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            view();
            glClearColor(0., .5, 0.5, 1.0);

            glPushMatrix();
                player->translate(lock/30.*1.3 * truck_steer_direction, 0, 0);
                asphalt->translate(0, 0, -1);
                player->render();
                asphalt->render();
                for(auto & scene_object: this->object_map){
                    if(scene_object.second->is_active){
                        scene_object.second->render();
                    }
                }
            glPopMatrix();
            

        }

        void view(){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0, 0, game->WIN_SIZE_W, game->WIN_SIZE_H);
            gluPerspective(45, game->RATIO, 0.1, 1000);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(
                0, 120, -70,
                0, 0, 120,
                0., 1., 0.
            );
        }
        void reset(){}
};
