#include <SceneObject.hpp>
#include <GL/freeglut.h>
#include <random>
#include <iostream>

class RowOfObstacle : public SceneObject{
    public:
        SceneObject *lane[3] = {NULL};
        float gap;

    public:
        RowOfObstacle(float gap, float x, float y, float z):
            SceneObject(x, y, z){

            this->gap = gap;
            for(int i = 0; i < 3; i++){
                if(rand() % 3)
                    lane[i] = new SceneObject(x + (i-1)*gap, y, z);
            }
            int p = rand() % 3;
            delete lane[p];
            lane[p] = NULL;
        }

        void render() override{
            for(auto &objek : lane){
                // std::cout << objek << " ";
                if(objek != NULL) objek->render();
            }
        }

        void translate(float x, float y, float z) override{
            position += vec3(x, y, z);
            for(auto &objek : lane){
                // std::cout << objek << " ";
                if(objek != NULL) objek->translate(x, y, z);
            }
        }

        void randomize(){
            for(int i = 0; i < 3; i++){
                delete lane[i];
                lane[i] = NULL;
                if(rand() % 3)
                    lane[i] = new SceneObject(position[0] + (i-1)*gap, position[1], position[2]);
            }
            int p = rand() % 3;
            delete lane[p];
            lane[p] = NULL;

        }



};