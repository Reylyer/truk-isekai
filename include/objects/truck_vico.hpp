#include <SceneObject.hpp>
#include <GL/freeglut.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>


class TruckVico: public SceneObject{
    public:
        TruckVico(float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
        }
        void render() override{
            glPushMatrix();
                // scale().rotate(0).translate(0,0,0);
                float *tpos = value_ptr(position);
                // printf("%f %f %f \n", tpos[0], tpos[1], tpos[2]);
                glTranslatef(tpos[0], tpos[1], tpos[2]);

                // membuat Kepala Truk
                glPushMatrix();		
                    // Kepala bagian bawah
                    glPushMatrix();	
                        
                        // vent atas
                        glPushMatrix();
                            glColor3ub(0, 0, 0);
                            glTranslatef(2.0f, 4.0f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(-2.5f, 0.0f, 0.0f);
                                glVertex3f(-3.0f, 0.5f, 0.0f);
                                glVertex3f(3.0f, 0.5f, 0.0f);
                                glVertex3f(2.5f, 0.0f, 0.0f);
                                
                            glEnd();
                        glPopMatrix();
                        
                        //vent tengah
                        glPushMatrix();
                            glColor3ub(0, 0, 0);
                            glTranslatef(2.0f, 3.0f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.0f, 0.75f, 0.0f);
                                glVertex3f(-2.5f, 0.25f, 0.0f);
                                glVertex3f(2.5f, 0.25f, 0.0f);
                                glVertex3f(3.0f, 0.75f, 0.0f);
                                
                            glEnd();
                        glPopMatrix();
                                    
                        //vent bawah
                        glPushMatrix();
                            glColor3ub(0, 0, 0);
                            glTranslatef(2.0f, 3.0f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.0f, 0.0f, 0.0f);
                                glVertex3f(-2.5f, -0.5f, 0.0f);
                                glVertex3f(2.5f, -0.5f, 0.0f);
                                glVertex3f(3.0f, 0.0f, 0.0f);
                                
                            glEnd();
                        glPopMatrix();
                        
                        //lampu depan kiri
                        glPushMatrix();
                            glColor3ub(255, 128, 0);
                            glTranslatef(2.0f, 3.8f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -1.5f, 0.0f);
                                glVertex3f(-4.0f, -2.5f, 0.0f);
                                glVertex3f(-3.5f, -2.5f, 0.0f);
                                glVertex3f(-3.5f, -1.5f, 0.0f);
                                
                            glEnd();
                        glPopMatrix();
                        
                        glPushMatrix();
                            glColor3ub(255, 255, 0);
                            glTranslatef(2.0f, 3.8f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.5f, -1.5f, 0.0f);
                                glVertex3f(-2.5f, -1.5f, 0.0f);
                                glVertex3f(-2.5f, -2.5f, 0.0f);
                                glVertex3f(-3.5f, -2.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        //lampu depan kanan
                        glPushMatrix();
                            glColor3ub(255, 128, 0);
                            glTranslatef(2.0f, 3.8f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(4.0f, -1.5f, 0.0f);
                                glVertex3f(4.0f, -2.5f, 0.0f);
                                glVertex3f(3.5f, -2.5f, 0.0f);
                                glVertex3f(3.5f, -1.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        glPushMatrix();
                            glColor3ub(255, 255, 0);
                            glTranslatef(2.0f, 3.8f, 0.51f);
                            glBegin(GL_QUADS);
                                glVertex3f(3.5f, -1.5f, 0.0f);
                                glVertex3f(2.5f, -1.5f, 0.0f);
                                glVertex3f(2.5f, -2.5f, 0.0f);
                                glVertex3f(3.5f, -2.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // depan
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glTranslatef(2.0f, 4.0f, 0.5f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 2.0f, 0.0f);
                                glVertex3f(-4.0f, 2.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // belakang
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glTranslatef(2.0f, 4.0f, -6.5f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 2.0f, 0.0f);
                                glVertex3f(-4.0f, 2.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // bawah
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glRotated(90, 1, 0, 0);
                            glTranslatef(2.0f, -2.5f, -1.0f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -4.0f, 0.0f);
                                glVertex3f(4.0f, -4.0f, 0.0f);
                                glVertex3f(4.0f, 3.0f, 0.0f);
                                glVertex3f(-4.0f, 3.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        //handle pintu kiri
                        glPushMatrix();
                            glColor3ub(0, 0, 0);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, 6.03f);
                            glBegin(GL_QUADS);
                                glVertex3f(1.2f, 0.4f, 0.0f);
                                glVertex3f(1.2f, 0.2f, 0.0f);
                                glVertex3f(1.8f, 0.2f, 0.0f);
                                glVertex3f(1.8f, 0.4f, 0.0f);
                            glEnd();
                        glPopMatrix();			
                        

                        //pintu kiri
                        glPushMatrix();
                        glColor3ub(0, 0, 150);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, 6.01f);
                            glBegin(GL_QUADS);
                                glVertex3f(-2.0f, 1.5f, 0.0f);
                                glVertex3f(-2.0f, -2.5f, 0.0f);
                                glVertex3f(2.5f, -2.5f, 0.0f);
                                glVertex3f(2.5f, 1.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // kiri					
                        glPushMatrix();
                        glColor3ub(10, 0, 150);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, 6.0f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 2.0f, 0.0f);
                                glVertex3f(-3.0f, 2.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        //handle pintu kanan
                        glPushMatrix();
                            glColor3ub(0, 0, 0);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, -2.02f);
                            glBegin(GL_QUADS);
                                glVertex3f(1.2f, 0.4f, 0.0f);
                                glVertex3f(1.2f, 0.2f, 0.0f);
                                glVertex3f(1.8f, 0.2f, 0.0f);
                                glVertex3f(1.8f, 0.4f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        //pintu kanan
                        glPushMatrix();
                            glColor3ub(0, 0, 150);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, -2.01f);
                            glBegin(GL_QUADS);
                                glVertex3f(-2.0f, 1.5f, 0.0f);
                                glVertex3f(-2.0f, -2.5f, 0.0f);
                                glVertex3f(2.5f, -2.5f, 0.0f);
                                glVertex3f(2.5f, 1.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // kanan
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, -2.0f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 2.0f, 0.0f);
                                glVertex3f(-3.0f, 2.0f, 0.0f);
                            glEnd();
                        glPopMatrix();	
                    glPopMatrix();
                        
                    // Kepala bagian atas
                    glPushMatrix();
                    glColor3ub(10, 0, 150);
                    glTranslatef(0.0f, 5.0f, 0.0f);	
                        // depan
                        // kaca
                        glPushMatrix();
                            glColor3ub(224, 224, 224);
                            glTranslatef(2.0f, 4.0f, 0.4f);
                            glRotated(-30, 1, 0, 0);
                            glTranslatef(0.0f, 0.4f, -1.4f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.5f, -2.5f, 0.0f);
                                glVertex3f(3.5f, -2.5f, 0.0f);
                                glVertex3f(3.5f, 1.0f, 0.0f);
                                glVertex3f(-3.5f, 1.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glTranslatef(2.0f, 4.0f, 0.5f);
                            glRotated(-30, 1, 0, 0);
                            glTranslatef(0.0f, 0.4f, -1.5f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 1.6f, 0.0f);
                                glVertex3f(-4.0f, 1.6f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // atas
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glRotated(90, 1, 0, 0);
                            glTranslatef(2.0f, -2.5f, -5.0f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -4.0f, 0.0f);
                                glVertex3f(4.0f, -4.0f, 0.0f);
                                glVertex3f(4.0f, 0.715f, 0.0f);
                                glVertex3f(-4.0f, 0.715f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // belakang
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glTranslatef(2.0f, 4.0f, -6.5f);
                            glBegin(GL_QUADS);
                                glVertex3f(-4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 1.0f, 0.0f);
                                glVertex3f(-4.0f, 1.0f, 0.0f);
                            glEnd();
                        glPopMatrix();			
                                    
                        // kaca kiri
                        glPushMatrix();
                            glColor3ub(224, 224, 224 );
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, 6.01f);
                            glBegin(GL_QUADS);
                                glVertex3f(2.5f, 0.5f, 0.0f);
                                glVertex3f(0.0f, 0.5f, 0.0f);
                                glVertex3f(-2.0f, -2.5f, 0.0f);
                                glVertex3f(2.5f, -2.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                        
                        // kiri
                        glPushMatrix();
                            glColor3ub(10, 0, 150);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, 6.0f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 1.0f, 0.0f);
                                glVertex3f(-0.7f, 1.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                
                        //kaca kanan
                        glPushMatrix();
                            glColor3ub(224, 224, 224);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, -2.01f);
                            glBegin(GL_QUADS);
                                glVertex3f(2.5f, 0.5f, 0.0f);
                                glVertex3f(0.0f, 0.5f, 0.0f);
                                glVertex3f(-2.0f, -2.5f, 0.0f);
                                glVertex3f(2.5f, -2.5f, 0.0f);
                            glEnd();
                        glPopMatrix();
                
                    // kanan
                        glPushMatrix();
                        glColor3ub(10, 0, 150);
                            glRotated(90, 0, 1, 0);
                            glTranslatef(2.5f, 4.0f, -2.0f);
                            glBegin(GL_QUADS);
                                glVertex3f(-3.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, -3.0f, 0.0f);
                                glVertex3f(4.0f, 1.0f, 0.0f);
                                glVertex3f(-0.7f, 1.0f, 0.0f);
                            glEnd();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
                                    
                    
            // ------------------------------------------------------------------------------------------------
            // Membuat Badan truk utama
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, -4.0f);
                glColor3ub(120, 120, 120);
                    // depan
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -2.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // atas
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // belakang
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -20.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // bawah
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -1.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kiri
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, 6.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kanan
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                glPopMatrix();

            // ------------------------------------------------------------------------------------------------

                // Sambungan
                glPushMatrix();
                glTranslatef(2.0f, 0.0f, -20.0f);
                glColor3f(0.0f, 0.0f, 0.);
                    // atas
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(0.5f, -6.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-0.5f, -1.0f, 0.0f);
                            glVertex3f(0.0f, -1.0f, 0.0f);
                            glVertex3f(0.0f, 2.5f, 0.0f);
                            glVertex3f(-0.5f, 2.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // bawah
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(0.5f, -6.5f, -1.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-0.5f, -1.0f, 0.0f);
                            glVertex3f(0.0f, -1.0f, 0.0f);
                            glVertex3f(0.0f, 2.5f, 0.0f);
                            glVertex3f(-0.5f, 2.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kiri
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(5.0f, 1.5f, 0.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-1.0f, -0.5f, 0.0f);
                            glVertex3f(2.5f, -0.5f, 0.0f);
                            glVertex3f(2.5f, 0.5f, 0.0f);
                            glVertex3f(-1.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kanan
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(5.0f, 1.5f, 0.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-1.0f, -0.5f, 0.0f);
                            glVertex3f(2.5f, -0.5f, 0.0f);
                            glVertex3f(2.5f, 0.5f, 0.0f);
                            glVertex3f(-1.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                glPopMatrix();

            // ------------------------------------------------------------------------------------------------

                // Badan truk gandengan
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, -25.0f);
                glColor3ub(120, 120, 120);
                    // depan
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -2.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // atas
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // belakang
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -20.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // bawah
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -1.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kiri
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, 6.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kanan
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 0.5f, 0.0f);
                            glVertex3f(-4.0f, 0.5f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                glPopMatrix();	
                
            // ------------------------------------------------------------------------------------------------

                // Container pertama
                glPushMatrix();
                glTranslatef(0.0f, 1.0f, -4.0f);
                glColor3ub(100, 100, 100);
                    // depan
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -2.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // atas
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -11.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // belakang
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -20.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // bawah
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -1.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kiri
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, 6.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kanan
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                glPopMatrix();

            // ------------------------------------------------------------------------------------------------
                
                // Container kedua
                glPushMatrix();
                glTranslatef(0.0f, 1.0f, -25.0f);
                glColor3ub(100, 100, 100);
                    // depan
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -2.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // atas
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -11.5f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // belakang
                    glPushMatrix();
                        glTranslatef(2.0f, 1.5f, -20.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // bawah
                    glPushMatrix();
                        glRotated(90, 1, 0, 0);
                        glTranslatef(2.0f, -19.5f, -1.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, -0.5f, 0.0f);
                            glVertex3f(4.0f, 17.0f, 0.0f);
                            glVertex3f(-4.0f, 17.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kiri
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, 6.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                    // kanan
                    glPushMatrix();
                        glRotated(90, 0, 1, 0);
                        glTranslatef(6.5f, 1.5f, -2.0f);
                        glBegin(GL_QUADS);
                            glVertex3f(-4.0f, -0.5f, 0.0f);
                            glVertex3f(13.5f, -0.5f, 0.0f);
                            glVertex3f(13.5f, 10.0f, 0.0f);
                            glVertex3f(-4.0f, 10.0f, 0.0f);
                        glEnd();
                    glPopMatrix();
                    
                glPopMatrix();
                
            // ------------------------------------------------------------------------------------------------
                
                // membuat Roda
                float a;
                float b;
                
                // Roda badan utama depan
                glPushMatrix();	
                glColor3f(0.05f, 0.05f, 0.05f);
                    
                    // Roda Kanan
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, 0.5f, -3.3f);
                            
                        // Sisi roda
                        
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                    // Roda kiri
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, -7.5f, -3.3f);
                            
                        // Sisi roda
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                glPopMatrix();
                

                
                // Roda badan utama belakang
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, -18.0f);
                glColor3f(0.05f, 0.05f, 0.05f);
                    
                    // Roda Kanan
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, 0.5f, -3.3f);
                            
                        // Sisi roda
                        
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                    // Roda kiri
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, -7.5f, -3.3f);
                            
                        // Sisi roda
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                glPopMatrix();
                
            // ------------------------------------------------------------------------------------------------
                
                // Roda badan sambungan depan
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, -26.5f);	
                glColor3f(0.05f, 0.05f, 0.05f);
                    
                    // Roda Kanan
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, 0.5f, -3.3f);
                            
                        // Sisi roda
                        
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                    // Roda kiri
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, -7.5f, -3.3f);
                            
                        // Sisi roda
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                glPopMatrix();
                
                
                // Roda badan sambungan belakang
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, -39.0f);
                glColor3f(0.05f, 0.05f, 0.05f);
                    
                    // Roda Kanan
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, 0.5f, -3.3f);
                            
                        // Sisi roda
                        
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                    // Roda kiri
                    glPushMatrix();
                        glRotated(90, 0, 0, 1);
                        glTranslatef(1.0f, -7.5f, -3.3f);
                            
                        // Sisi roda
                        glPushMatrix();
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        glPushMatrix();
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_TRIANGLE_FAN);
                            for (a = 0; a <= 360; a+=20){
                                
                                glVertex3f(cos(glm::radians(a)), 1, sin(glm::radians(a)));
                            }
                            glEnd();
                        glPopMatrix();
                            
                        // Selubung roda
                        glPushMatrix();	
                            glTranslatef(0.0f, 1.0f, 0.0f);
                            glBegin(GL_QUAD_STRIP);
                            for (b=0; b<=360; b+=20){
                                glVertex3f(cos(glm::radians(b)), +1, sin(glm::radians(b)));
                                glVertex3f(cos(glm::radians(b)), 0, sin(glm::radians(b)));
                            }
                            glEnd();
                        glPopMatrix();
                        
                    glPopMatrix();
                
                glPopMatrix();
            glPopMatrix();       
        }

    private:
        
};