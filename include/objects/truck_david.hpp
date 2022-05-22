#ifndef _TRUCK_DAVID
#define _TRUCK_DAVID

#define PI 3.1415926

class TruckDavid: public SceneObject{
    private:
        float radius;
        int jumlah_titik;
        float x_tengah;
        float y_tengah;
    public:
        TruckDavid(float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
        }
        void render() override{
            glPushMatrix();
                float *tpos = value_ptr(position);
                glTranslatef(tpos[0], tpos[1], tpos[2]);
                int coba = Head();
                //container pertama
                Container();
                //container kedua
                glPushMatrix();
                    glTranslatef(0,0,-22);
                    Container();
                glPopMatrix();
                //pengait
                Hook();
                //dekorasi
                Decoration();
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

        int Head() 
        { 
            //sisi depan
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.8,0.0,0.0);
                glVertex3f(-5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(-5.0f,6.0f,0.0f); 
                glEnd(); 
            glPopMatrix(); 

            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.8,0.0,0.0);
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
                glColor3f(0.55,0.0,0.0);
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
        
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.55,0.0,0.0);
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,11.0f,-7.0f);
                glVertex3f(5.0f,11.0f,-2.0f);
                glEnd(); 
            glPopMatrix();  
        
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.55,0.0,0.0);
                glVertex3f(5.0f,1.0f,0.0f); 
                glVertex3f(5.0f,6.0f,0.0f); 
                glVertex3f(5.0f,6.0f,-7.0f);
                glVertex3f(5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
        
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.55,0.0,0.0);
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
                glColor3f(0.0,0.0,0.8);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,13.0f,-27.0f);
                glVertex3f(5.0f,13.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.0,0.0,0.8);
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
                glColor3f(0.0,0.0,0.55);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(5.0f,13.0f,-7.0f);
                glVertex3f(-5.0f,13.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,-17); 
                glBegin(GL_QUADS); 
                glColor3f(0.0,0.0,0.55);
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
                glColor3f(0.0,0.0,0.8);
                glVertex3f(5.0f,2.0f,-7.0f); 
                glVertex3f(-5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,2.0f,-27.0f); 
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,10,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.0,0.0,0.8);
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
                glColor3f(0.1,0.1,0.1);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,2.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-7.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,-17); 
                glBegin(GL_QUADS); 
                glColor3f(0.1,0.1,0.1);
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
                glColor3f(0.2,0.2,0.2);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(5.0f,2.0f,-7.0f);
                glVertex3f(5.0f,2.0f,-27.0f);
                glVertex3f(5.0f,1.0f,-27.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-10,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.2,0.2,0.2);
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
                glColor3f(0.2,0.2,0.2);
                glVertex3f(5.0f,1.0f,-7.0f); 
                glVertex3f(-5.0f,1.0f,-7.0f);
                glVertex3f(-5.0f,1.0f,-27.0f);
                glVertex3f(5.0f,1.0f,-27.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,1,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.1,0.1,0.1);
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
                glColor3f(0.1,0.1,0.1);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(1.0f,2.0f,-27.0f);
                glVertex3f(1.0f,2.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-2,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.1,0.1,0.1);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(1.0f,2.0f,-27.0f);
                glVertex3f(1.0f,2.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.1,0.1,0.1);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(-1.0f,1.0f,-27.0f);
                glVertex3f(-1.0f,1.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,1,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.1,0.1,0.1);
                glVertex3f(1.0f,1.0f,-27.0f); 
                glVertex3f(-1.0f,1.0f,-27.0f);
                glVertex3f(-1.0f,1.0f,-29.0f);
                glVertex3f(1.0f,1.0f,-29.0f);
                glEnd(); 
            glPopMatrix();
        }


        void Decoration() {
            //dekorasi
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.6,0.3,0.0);
                glVertex3f(-4.0f,6.0f,0.1f); 
                glVertex3f(4.0f,6.0f,0.1f);
                glVertex3f(4.0f,2.0f,0.1f);
                glVertex3f(-4.0f,2.0f,0.1f);
                glEnd(); 
            glPopMatrix();
            
            //kaca depan
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.5,0.5,0.5);
                glVertex3f(4.0f,7.0f,-0.3f); 
                glVertex3f(-4.0f,7.0f,-0.3f);
                glVertex3f(-4.0f,10.0f,-1.4f);
                glVertex3f(4.0f,10.0f,-1.4f);
                glEnd(); 
            glPopMatrix();
            
            //pintu
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.6,0.3,0.0);
                glVertex3f(5.1f,2.0f,-1.0f); 
                glVertex3f(5.1f,6.0f,-1.0f);
                glVertex3f(5.1f,6.0f,-6.0f);
                glVertex3f(5.1f,2.0f,-6.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-10.2,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.6,0.3,0.0);
                glVertex3f(5.1f,2.0f,-1.0f); 
                glVertex3f(5.1f,6.0f,-1.0f);
                glVertex3f(5.1f,6.0f,-6.0f);
                glVertex3f(5.1f,2.0f,-6.0f);
                glEnd(); 
            glPopMatrix();
            
            //kaca samping
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.5,0.5,0.5);
                glVertex3f(5.1f,10.0f,-2.5f); 
                glVertex3f(5.1f,7.0f,-1.5f);
                glVertex3f(5.1f,7.0f,-6.0f);
                glVertex3f(5.1f,10.0f,-6.0f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(-10.2,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.5,0.5,0.5);
                glVertex3f(5.1f,10.0f,-2.5f); 
                glVertex3f(5.1f,7.0f,-1.5f);
                glVertex3f(5.1f,7.0f,-6.0f);
                glVertex3f(5.1f,10.0f,-6.0f);
                glEnd(); 
            glPopMatrix();
            
            //plat
            glPushMatrix(); 
                glTranslatef(0,0,3); 
                glBegin(GL_QUADS); 
                glColor3f(0.1,0.1,0.1);
                glVertex3f(1.5f,1.1f,0.1f); 
                glVertex3f(1.5f,1.8f,0.1f);
                glVertex3f(-1.5f,1.8f,0.1f);
                glVertex3f(-1.5f,1.1f,0.1f);
                glEnd(); 
            glPopMatrix();
            
            glPushMatrix(); 
                glTranslatef(0,0,-46.2); 
                glBegin(GL_QUADS); 
                glColor3f(0.2,0.2,0.2);
                glVertex3f(1.5f,1.1f,0.1f); 
                glVertex3f(1.5f,1.8f,0.1f);
                glVertex3f(-1.5f,1.8f,0.1f);
                glVertex3f(-1.5f,1.1f,0.1f);
                glEnd(); 
            glPopMatrix();
        }
};

#endif