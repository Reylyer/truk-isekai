#define FREEGLUT_STATIC

#include <SceneObject.hpp>
#include <LoadBmp.hpp>
#include <GL/freeglut.h>
#include <string>
#include <iostream>

#ifndef _ASPHALT
#define _ASPHALT


class Asphalt: public SceneObject{
    private:
        float w;
        float h;
        float lane_width;
        int repeat;
        GLuint texid;
    public:
        Asphalt(const char* imagepath, float w = 1, float h = 1, int lane = 3, int repeat = 20, float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
            this->w = w;
            this->h = h;
            this->lane_width = w/lane*2;
            this->repeat = repeat;
            // this->texid = loadBMP("res/bmp/asphalt.bmp");
        }
        void render() override{
            // std::cout << w << " " << h << " " << texid << "\n";
            glPushMatrix();
                // glBindTexture(GL_TEXTURE_2D, this->texid);
                float *tpos = value_ptr(position);
                glTranslatef(tpos[0], tpos[1], tpos[2]);

                for(int i = 0; i < this->repeat; i++){
                    glTranslatef(0, 0, h*2);
                    // hitam
                    glColor3f(0, 0, 0);
                    glBegin(GL_QUADS);
                        // glTexCoord2f(0, 1);
                        glVertex3f(-w, 0, h);
                        // glTexCoord2f(0, 0);
                        glVertex3f(-w, 0, -h);
                        // glTexCoord2f(1, 0);
                        glVertex3f(w, 0, -h);
                        // glTexCoord2f(1, 1);
                        glVertex3f(w, 0, h);
                    glEnd();
                    // marka
                    glColor3f(0.7, 0.7, 0.7);
                    glBegin(GL_QUADS);
                        // kiri
                        glVertex3f(-w, 0.1, h);
                        glVertex3f(-w, 0.1, -h);
                        glVertex3f(-w*10/9, 0.1, -h);
                        glVertex3f(-w*10/9, 0.1, h);
                        // kanan
                        glVertex3f(w*10/9, 0.1, h);
                        glVertex3f(w*10/9, 0.1, -h);
                        glVertex3f(w, 0.1, -h);
                        glVertex3f(w, 0.1, h);
                        
                    glEnd();
                    // pembagi lane
                    glPushMatrix();
                        glTranslatef(-w, 0, 0);
                        for(float l = lane_width; l < w*2; l += lane_width){
                            glTranslatef(lane_width, 0, 0);
                            glBegin(GL_QUADS);
                                glVertex3f(-w/15, 0.1, h/5*2);
                                glVertex3f(-w/15, 0.1, -h/5*2);
                                glVertex3f(w/15, 0.1, -h/5*2);
                                glVertex3f(w/15, 0.1, h/5*2);
                            glEnd();
                        }
                    glPopMatrix();
                }

            glPopMatrix();
        }
    private:
        
};

#endif