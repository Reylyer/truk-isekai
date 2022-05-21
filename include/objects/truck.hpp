#include <SceneObject.hpp>
#include <GL/freeglut.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

#ifndef _TRUCK_GIVANDRA
#define _TRUCK_GIVANDRA


class Truck: public SceneObject{
    private:
        const float compass[4][3] = {
            { 1,  1, 0},
            { 1, -1, 0},
            {-1, -1, 0},
            {-1,  1, 0}
        };
    public:
        Truck(float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
        }
        void render() override{
            glPushMatrix();
                scale().rotate(0).translate(0,0,0);
                float *tpos = value_ptr(position);
                glTranslatef(tpos[0], tpos[1], tpos[2]);
                
                // kepala
                glColor3ub(100, 100, 100);
                glPushMatrix();
                    glTranslatef(0, 2/2, 2*1.25);
                    glPushMatrix();
                        glScalef(2.5, 1.75, 1.5);
                        draw_custom_cube(1);   
                    glPopMatrix();

                    glTranslatef(0, -2/2.5, 2);
                    glPushMatrix();
                        glScalef(2.5, 2.5, 0.5);
                        draw_custom_cube(1);   
                    glPopMatrix();
                    
                    // decor

                    // kaca depan
                    glColor3ub(0,0,0);
                    glTranslatef(0, 2/1.5, 0);
                    glPushMatrix();
                        glScalef(2, 1, 0.55);
                        draw_custom_cube(1);
                    glPopMatrix();
                    
                    // kaca samping
                    glTranslatef(0, 0, -2/2.5);
                    glPushMatrix();
                        glScalef(2.55, 1, 1);
                        draw_custom_cube(1);
                    glPopMatrix();

                    // gagang pintu
                    glTranslatef(0, -2/1.5, -2/2.5);
                    glPushMatrix();
                        glScalef(2.55, 0.05, 0.1);
                        draw_custom_cube(1);
                    glPopMatrix();

                    // bemper
                    glTranslatef(0, -2*1.25, 2);
                    glPushMatrix();
                        glScalef(2.55, 0.25, 0.25);
                        draw_custom_cube(1);
                    glPopMatrix();

                    // lampu
                    glTranslatef(0, 2/3, 0);
                    for(int i = -1; i < 2; i+=2){
                        glPushMatrix();
                            glColor3ub(255,255,255);
                            glTranslatef(i*2, 0, 0);
                            glPushMatrix();
                                glScalef(0.2, 0.25, 0.2);
                                draw_custom_cube(1);
                            glPopMatrix();

                            glColor3ub(255,255,0);
                            glTranslatef(-i*2/5, 0, 0);
                            glPushMatrix();
                                glScalef(0.2, 0.25, 0.2);
                                draw_custom_cube(1);
                            glPopMatrix();
                        glPopMatrix();
                    }

                    // spion
                    glTranslatef(0, 2*1.5, -2/10);
                    for(int i = -1; i < 2; i+=2){
                        glPushMatrix();
                            glColor3ub(0,0,0);
                            glTranslatef(i*2*1.4, 0, 0);
                            glPushMatrix();
                                glScalef(0.2, 0.6, 0.1);
                                draw_custom_cube(1);
                            glPopMatrix();
                            glTranslatef(0, 0, -2/100);
                            glColor3ub(255,255,255);
                            glPushMatrix();
                                glScalef(0.18, 0.55, 0.09);
                                draw_custom_cube(1);
                            glPopMatrix();
                        glPopMatrix();
                    }

                    // stiker
                    char ded_string[] = "SUS";
                    glTranslatef(-2/1.75, -2*1.2, 2/5);
                    glLineWidth(10);
                    glColor3ub(0,0,0);
                    glPushMatrix();
                        glScalef(0.007, 0.01, 0.01);
                        int len = (int) strlen(ded_string);
                        for (int i = 0; i < len; i++) {
                            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, ded_string[i]);
                        }
                    glPopMatrix();


                glPopMatrix();
                
                glColor3ub(100, 100, 100);
                draw_slate();


                //roda karet
                glColor3ub(0, 0, 0);
                for(auto com: compass){
                    glPushMatrix();
                        glTranslatef(2*com[0], -2, 2*1.4*com[1]);
                        glRotatef(90, 0, 1, 0);
                        draw_roda(2/2.5);
                    glPopMatrix();
                }

                //roda velg
                glColor3ub(200, 200, 200);
                int i = 0;
                for(auto com: compass){
                    glPushMatrix();
                        glTranslatef(2*com[0]*1.1, -2, 2*1.4*com[1]);
                        glRotatef(90, 0, 1, 0);
                        if(i > 1){
                            glRotatef(180, 0, 1, 0);
                        }
                        draw_roda(2/5.);
                    glPopMatrix();
                    i++;
                }
            glPopMatrix();
        }

    private:
        void draw_custom_cube(float sisi){
            float rot[] = {0, -90, -180, 90, -90, 90};
            float vect[][3] = {
                {1, 0, 0},
                {0, 1, 0}
            };
            int select = 0;
            for(int i = 0; i < 6; i++){
                glPushMatrix();
                    glRotatef(rot[i], vect[select][0], vect[select][1], vect[select][2]);
                    glTranslatef(0, 0, sisi);
                    glBegin(GL_QUADS);
                        for(auto com: compass) glVertex3f(sisi*com[0], sisi*com[1], 0);
                    glEnd();
                glPopMatrix();
                if(i == 3) select++;
            }
        }
        void draw_roda(float r){
            float rad, tebel, pcos, psin;
            tebel = r/2.;
            glPushMatrix();
                glTranslatef(0, 0, -tebel/2.);
                for(int i = 0; i < 2; i += 1){
                    glPushMatrix();
                        glTranslatef(0, 0, tebel*i);
                        draw_linkeran(r);
                    glPopMatrix();
                }
                glBegin(GL_QUAD_STRIP);
                    for(int i = 0; i <= 370; i+=10){
                        rad = i * 3.1415926 / 180.;
                        pcos = cos(rad)*r;
                        psin = sin(rad)*r;
                        glVertex3f(pcos, psin, 0);
                        glVertex3f(pcos, psin, tebel);
                    }
                glEnd();
            glPopMatrix();
        }
        void draw_slate(){
            glPushMatrix();
                glTranslatef(0, -1, 0);
                glPushMatrix();
                    glScalef(2*1.25, 0.25, 2*2.4);
                    draw_custom_cube(1);
                glPopMatrix();
                glTranslatef(0, -.75, 0);
                glPushMatrix();
                    glScalef(2*1.25, 0.5, 2*0.75);
                    draw_custom_cube(1);
                glPopMatrix();
                glPushMatrix();
                    glScalef(2*0.75, 0.5, 2*2);
                    draw_custom_cube(1);
                glPopMatrix();
            glPopMatrix();
        }
        void draw_linkeran(float r){
            float rad;
            glBegin(GL_TRIANGLE_FAN);
                for(int i = 0; i < 360; i+=10){
                    rad = i * 3.1415926 / 180.;
                    glVertex3f(cos(rad)*r, sin(rad)*r, 0);
                }
            glEnd();
        }
};


#endif