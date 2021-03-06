#define FREEGLUT_STATIC

#include <string>
#include <random>
#include <vector>
#include <map>
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
#include <RowOfObstacle.hpp>


using std::string,
      std::vector,
      std::map;

//https://stackoverflow.com/a/7114482/14052716
typedef std::mt19937 RNG;  // the Mersenne Twister with a popular choice of parameters
uint32_t seed_val;           // populate somehow


class MainScene: public Scene{
    private:
        map<int, SceneObject*> trucks;
        SceneObject* player;
        Asphalt * asphalt;
        vector<RowOfObstacle*> row_of_obstacless;

        int lock = 0;
        float speed = 1.5;
        short player_lane = 0;
        int truck_steer_direction = 0;
        int row_active = 0;
        int frame_count = 0;
        int repeat_segment = 20;
        int segment_length = 33;

        int score = 0;
        bool nabrak = false;
        

    public:
        MainScene(Game &game, string name): Scene(game, name){
            // objects.insert({"truck1", truck1});
            Truck      * truck1 = new Truck();
            TruckVico  * truck2 = new TruckVico();
            TruckDavid * truck3 = new TruckDavid();
            TruckDimas * truck4 = new TruckDimas();
            this->asphalt = new Asphalt("res/bmp/car_2.bmp",
                                         segment_length, segment_length, 
                                         3, repeat_segment,
                                         0, 0, -90);

            trucks.insert({0, truck1});
            trucks.insert({1, truck2});
            trucks.insert({2, truck3});
            trucks.insert({3, truck4});

            for(int i = 0; i < repeat_segment; i++){
                row_of_obstacless.push_back(new RowOfObstacle(23, 0, 0, 90 + i*segment_length*4));
            }

            srand(time(NULL));

            setup();
            // Car *car1 = new Car("res/obj/car.obj", "res/bmp/car_2.bmp");
            // object_map.insert({"mobil", car1});
        }
        void setup() override{
            player = trucks.find(game->player_truck)->second;
            player_lane = 0;
            frame_count = 0;
            speed = 1.5;
            score = 0;
            player->set_x(0);
            for(auto & row_of_obstacles: row_of_obstacless){
                row_of_obstacles->translate(0, 0, 300);
            }
        }
        void update() override{
            if(!lock){
                // i know right? its weird
                // steer direction
                //  1 = kiri
                // -1 = kanan
                // lane
                //  1 kiri
                //  0 tengah
                // -1 kanan
                if(game->KEY_PRESSED['a']){
                    printf("a pressed\n");
                    lock = 30;
                    truck_steer_direction = 1;
                    if(player_lane == 1) truck_steer_direction = 0; // lock in left lane
                    player_lane += truck_steer_direction;
                }
                else if(game->KEY_PRESSED['d']){
                    printf("d pressed\n");
                    lock = 30;
                    truck_steer_direction = -1;
                    if(player_lane == -1) truck_steer_direction = 0; // lock in right lane
                    player_lane += truck_steer_direction;
                }
                else if(game->KEY_PRESSED['q']){
                    game->change_scene("Menu");
                }
            }

            if(checkCollision()){
                speed = 0;
                lock = 0;
                nabrak = true;
            } else{
                player->translate(lock/30.*1.5 * truck_steer_direction, 0, 0);
                asphalt->translate(0, 0, -speed);
                for(auto & row_of_obstacles: row_of_obstacless){
                    row_of_obstacles->translate(0, 0, -speed);
                }
                if(row_of_obstacless[row_active]->get_z() < -50){
                    row_of_obstacless[row_active]->translate(0, 0, segment_length*4*repeat_segment);
                    row_of_obstacless[row_active]->randomize();
                    row_active = (row_active + 1) % repeat_segment;
                    printf("%d\n",  row_active);
                }

                if(frame_count*speed >= segment_length*2){
                    asphalt->translate(0, 0, segment_length*2);
                    frame_count = 0;
                }
                score++;
            }


            render();

            if(lock) lock--; 
            else truck_steer_direction = 0;
            frame_count++;
            std::cout << "SCORE: " << score << "\n";
        }

    private:
        bool checkCollision(){
            if(row_of_obstacless[row_active]->get_z() < 0){
                float xpos = player->get_x();
                for(auto &obstacle: row_of_obstacless[row_active]->lane){
                    if(obstacle == NULL) continue;
                    std::cout << player->get_x() - segment_length << " < " <<  obstacle->get_x() << " < " << player->get_x() + segment_length << "\n";
                    if(obstacle->get_x() > player->get_x() - segment_length/2 && 
                       obstacle->get_x() < player->get_x() + segment_length/2){
                        return true;
                       }
                }
            }
            return false;
        }

        void render(){
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            view();
            glClearColor(1, 0.643, 0.286, 1.0);

            glPushMatrix();
                glBegin(GL_LINES);
                    glVertex3f(-30, 0, 0);
                    glVertex3f( 30, 0, 0);
                glEnd();

                glMatrixMode(GL_PROJECTION);
                glPushMatrix();
                    glLoadIdentity();
                    gluOrtho2D(0.0f, game->WIN_SIZE_W, game->WIN_SIZE_H, 0.0f);
                    glMatrixMode(GL_MODELVIEW);
                    glPushMatrix();
                        glLoadIdentity();
                        glColor3f(1, 1, 1);
                        glRasterPos2f(30, 160);
                        char skor[72];
                        sprintf(skor, "%d", score);
                        glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *) skor);
                        glMatrixMode(GL_PROJECTION);
                    glPopMatrix();
                glMatrixMode(GL_MODELVIEW);
                glPopMatrix();

                asphalt->render();
                player->render();

                for(auto & scene_object: this->object_map){
                    if(scene_object.second->is_active){
                        scene_object.second->render();
                    }
                }
                for(auto & row_of_obstacles: row_of_obstacless){
                    row_of_obstacles->render();
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
                0, 40, -70,
                0, 0, 30,
                0., 1., 0.
            );
        }
        void reset(){}
};
