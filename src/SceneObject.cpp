#define FREEGLUT_STATIC

#include <string>
#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SceneObject.hpp>

using   glm::vec3,
        glm::vec4,
        glm::mat4,
        glm::value_ptr;

// template <class BaseSceneObject>
SceneObject::SceneObject(float x/*=0*/ , float y/*=0*/, float z/*=0*/){

    position = vec3(x, y, z);
    // printf("%f %f %f \n", position[0], position[1], position[2]);
}
SceneObject::~SceneObject(){}
void SceneObject::translate(float x, float y, float z){
    // translate position by x, y, z
    position = position + vec3(x, y, z);
}

void SceneObject::rotate(float degrees, float x/*=0*/, float y/*=1*/, float z/*=0*/){
    // direction = glm::rotate(mat4(), glm::radians(degrees), vec3(x, y, z)) * direction;
}

void SceneObject::scale(float x /*=1*/, float y/*=1*/, float z/*=1*/){
    // position = glm::scale(mat4(), vec3(x, y, z)) * position;
}

void SceneObject::render(){
    glColor3ub(255, 255, 255);
    glPushMatrix();
        // glBindTexture(GL_TEXTURE_2D, this->texid);
        float *tpos = value_ptr(position);
        glTranslatef(tpos[0], tpos[1], tpos[2]);
        glBegin(GL_QUADS);
            float BOX_SIZE = 20;
            //Sisi atas
            glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);

            //Sisi bawah
            glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

            //Sisi kiri
            glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);

            //Sisi kanan
            glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

            //Sisi depan
            glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);

            //Sisi belakang
            glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
            glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
        glEnd();
    glPopMatrix();

}

float SceneObject::get_x(){ return this->position[0];}
float SceneObject::get_y(){ return this->position[1];}
float SceneObject::get_z(){ return this->position[2];}

void SceneObject::set_x(float x){this->position[0] = x;}
void SceneObject::set_y(float y){this->position[1] = y;}
void SceneObject::set_z(float z){this->position[2] = z;}

