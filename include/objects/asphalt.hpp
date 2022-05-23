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
        GLuint texid;
    public:
        Asphalt(const char* imagepath, float w = 1, float h = 1, float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
            this->w = w;
            this->h = h;
            // printf("PPPPPPPPPPPPP");
            // this->texid = loadBMP(imagepath);
            std::cout << w << " " << h << " " << texid << "\n";

        }
        void render() override{
            printf("render asphalt\n");
            std::cout << w << " " << h << " " << texid << "\n";
            // glColor3ub(0, 0, 0);
            glPushMatrix();
                // glBindTexture(GL_TEXTURE_2D, this->texid);
                float *tpos = value_ptr(position);
                glTranslatef(tpos[0], tpos[1], tpos[2]);

                for(int i = 0; i < 10; i++){
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
                    glColor3f(1, 1, 1);
                    glBegin(GL_QUADS);
                        //tengah
                        glVertex3f(-w/10, 0.1, h/5*3);
                        glVertex3f(-w/10, 0.1, -h/5*3);
                        glVertex3f(w/10, 0.1, -h/5*3);
                        glVertex3f(w/10, 0.1, h/5*3);
                        // kiri
                        glVertex3f(-w, 0.1, h);
                        glVertex3f(-w, 0.1, -h);
                        glVertex3f(-w*5/4, 0.1, -h);
                        glVertex3f(-w*5/4, 0.1, h);
                        // kanan
                        glVertex3f(w*5/4, 0.1, h);
                        glVertex3f(w*5/4, 0.1, -h);
                        glVertex3f(w, 0.1, -h);
                        glVertex3f(w, 0.1, h);
                    glEnd();
                }

            glPopMatrix();
        }
    private:
        
};

#endif