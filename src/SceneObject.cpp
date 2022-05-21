#include <string>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SceneObject.hpp>

using   glm::vec3,
        glm::vec4,
        glm::mat4,
        glm::value_ptr;

// template <class BaseSceneObject>
SceneObject::SceneObject(float x/*=0*/ , float y/*=0*/, float z/*=0*/){

    position = vec4(x, y, z, 0);
    printf("%f %f %f \n", position[0], position[1], position[2]);
}
SceneObject::~SceneObject(){}
SceneObject & SceneObject::translate(float x, float y, float z){
    // translate position by x, y, z
    //         <       translation matrix          > * <vecpos>
    position = glm::translate(mat4(), vec3(x, y, z)) * position;
    return *this;
}

SceneObject & SceneObject::rotate(float degrees, float x/*=0*/, float y/*=1*/, float z/*=0*/){
    direction = glm::rotate(mat4(), glm::radians(degrees), vec3(x, y, z)) * direction;
    return *this;
}

SceneObject & SceneObject::scale(float x /*=1*/, float y/*=1*/, float z/*=1*/){
    position = glm::scale(mat4(), vec3(x, y, z)) * position;
    return *this;
}

void SceneObject::render(){}

float SceneObject::get_x(){ return this->position[0];}
float SceneObject::get_y(){ return this->position[1];}
float SceneObject::get_z(){ return this->position[2];}

