#ifndef _TRUCK_DIMAS
#define _TRUCK_DIMAS

#define PI 3.1415926

class TruckDimas: public SceneObject{
    private:
        float radius;
        int jumlah_titik;
        float x_tengah;
        float y_tengah;
    public:
        TruckDimas(float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
        }
        void render() override{
            glPushMatrix();
                float *tpos = value_ptr(position);
                glTranslatef(tpos[0], tpos[1], tpos[2]);

                Head();
                //container pertama
                Container();
                //container kedua
                glPushMatrix();
                    glTranslatef(0,0,-22);
                    Container();
                glPopMatrix();
                //pengait
                Hook();

            glPopMatrix();
        }
    private:
        
        void wheel(){
            //fungsi membuat roda
            glPushMatrix();
                for(int j=0; j<=360; j++) {
                    glPushMatrix();
                        glTranslatef(1,0,-0.5);
                        glRotated(90,1,0,0);
                        glRotated(j,0,1,0);
                        glTranslatef(0,3,0.8);
                        glColor3f(0.1,0.1,0.1);
                        glBegin(GL_QUADS);
                        glVertex3f(0,0,0);
                        glVertex3f(0.1,0,0);
                        glVertex3f(0.1,0.6,0);
                        glVertex3f(0,0.6,0);
                        glEnd();
                    glPopMatrix();
                }
            glPopMatrix();

            // lingkaran depan
            glPushMatrix();
                glTranslatef(0,0,3.1);
                glColor3f(0.1,0.1,0.1);
                glBegin(GL_TRIANGLE_FAN);
                radius=80;
                jumlah_titik=100;
                x_tengah=100;
                y_tengah=0;
                for (int i=0; i<=360; i++) {
                    float sudut=i*(2*PI/jumlah_titik);
                    float x=x_tengah+radius*cos(sudut);
                    float y=y_tengah+radius*sin(sudut);
                    glVertex2f(x/100,y/100);
                }
                glEnd();
            glPopMatrix();

            // lingkaran belakang
            glPushMatrix();
                glTranslatef(0,0,2.5);
                glRotated(180,1,0,0);
                glColor3f(0.1,0.1,0.1);
                glBegin(GL_TRIANGLE_FAN);
                radius=80;
                jumlah_titik=100;
                x_tengah=100;
                y_tengah=0;
                for (int i=0; i<=360; i++) {
                    float sudut=i*(2*PI/jumlah_titik);
                    float x=x_tengah+radius*cos(sudut);
                    float y=y_tengah+radius*sin(sudut);
                    glVertex2f(x/100,y/100);
                }
                glEnd();
            glPopMatrix();
        }

        void Head() 
        { 
            //sisi depan
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(-5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(-5.0f,6.0f,0.0f); 
                glEnd(); 
            glPopMatrix(); 

            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(-5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,11.0f,-2.0f);
                glVertex3f(-5.0f,11.0f,-2.0f);
                glEnd(); 
            glPopMatrix(); 
        
            //sisi samping
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
        
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,11.0f,-7.0f);
                glVertex3f(5.0f,11.0f,-2.0f);
                glEnd(); 
            glPopMatrix();  
        
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
        
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,11.0f,-7.0f);
                glVertex3f(5.0f,11.0f,-2.0f);
                glEnd(); 
            glPopMatrix();
        
            //sisi bawah
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS);
                glColor3f(0.75,0.58,0.56);
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,1.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,0.0f);
                glEnd(); 
            glPopMatrix();
        
            //sisi belakang 
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS);
                glColor3f(0.75,0.58,0.56); 
                glVertex3f(5.0f,11.0f,-2.0f); 
                glVertex3f(5.0f,11.0f,-7.0f);
                glVertex3f(-5.0f,11.0f,-7.0f);
                glVertex3f(-5.0f,11.0f,-2.0f);
                glEnd(); 
            glPopMatrix();
            
            //sisi atas
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS);
                glColor3f(0.75,0.58,0.56); 
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,11.0f,-7.0f);
                glVertex3f(-5.0f,11.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            //roda
            glPushMatrix();
                glTranslatef(0.3, 1.3, 1);
                glRotatef(90, 0.0, 1.0, 0.0);
                glScalef(1.7,1.7,1.7);
                wheel();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-9.7, 1.3, 1);
                glRotatef(90, 0.0, 1.0, 0.0);
                glScalef(1.7,1.7,1.7);
                wheel();
            glPopMatrix();
        } 

        void Container() {
            //sisi kanan kiri
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.0,0.5,0.5);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,13.0f,-27.0f);
                glVertex3f(5.0f,13.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.0,0.5,0.5);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,13.0f,-27.0f);
                glVertex3f(5.0f,13.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            //sisi depan belakang
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.53,0.83,0.82);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(5.0f,13.0f,-7.0f);
                glVertex3f(-5.0f,13.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,-17); 
                glBegin(GL_QUADS); 
                glColor3f(0.53,0.83,0.82);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(5.0f,13.0f,-7.0f);
                glVertex3f(-5.0f,13.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            //sisi atas bawah
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.53,0.83,0.82);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(-5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,2.0f,-27.0f); 
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,10,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.53,0.83,0.82);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(-5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,2.0f,-27.0f); 
                glEnd(); 
            glPopMatrix();
            
            //bagian bawah container
            //sisi depan belakang
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,-17); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            //sisi kanan kiri
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-7.0f);
                glVertex3f(5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,1.0f,-27.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-7.0f);
                glVertex3f(5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,1.0f,-27.0f);
                glEnd(); 
            glPopMatrix();
            
            //sisi atas bawah
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(-5.0f,1.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-27.0f);
                glVertex3f(5.0f,1.0f,-27.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,1,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(-5.0f,1.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-27.0f);
                glVertex3f(5.0f,1.0f,-27.0f);
                glEnd(); 
            glPopMatrix();
            
            //roda
            glPushMatrix();
                glTranslatef(0.3, 1.3, -7);
                glRotatef(90, 0.0, 1.0, 0.0);
                glScalef(1.7,1.7,1.7);
                wheel();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-9.7, 1.3, -7);
                glRotatef(90, 0.0, 1.0, 0.0);
                glScalef(1.7,1.7,1.7);
                wheel();
            glPopMatrix();
            
            glPushMatrix();
                glTranslatef(0.3, 1.3, -18);
                glRotatef(90, 0.0, 1.0, 0.0);
                glScalef(1.7,1.7,1.7);
                wheel();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-9.7, 1.3, -18);
                glRotatef(90, 0.0, 1.0, 0.0);
                glScalef(1.7,1.7,1.7);
                wheel();
            glPopMatrix();
        }

        void Hook() {
            //penyambung
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(1.0f,2.0f,-27.0f);
                glVertex3f(1.0f,2.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-2,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.65,0.39,0.38);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(1.0f,2.0f,-27.0f);
                glVertex3f(1.0f,2.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(-1.0f,1.0f,-27.0f);
                glVertex3f(-1.0f,1.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,1,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.75,0.58,0.56);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(-1.0f,1.0f,-27.0f);
                glVertex3f(-1.0f,1.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
        }

};

#endif