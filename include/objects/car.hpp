#include <SceneObject.hpp>
#include <LoadBmp.hpp>
#include <LoadObj.hpp>
#include <vector>
#include <glm/glm.hpp>
#include <GL/freeglut.h>
#include <glm/gtc/type_ptr.hpp>


using   std::vector;
using   glm::vec3,
        glm::vec2;

#ifndef _CAR
#define _CAR


class Car: public SceneObject{
    private:
        vector<vec3> vertices;
        vector<vec2> uvs;
        vector<vec3> normals;
        GLuint texid;

    public:
        Car(const char* obj_path, const char* imagepath, float x=0, float y=0, float z=0):
            SceneObject(x, y, z){
            ezLoader(obj_path, vertices, uvs, normals);
            texid = loadBMP(imagepath);
        }
        void render() override{
            printf("rendered car\n"); 
            glutWireCube(1);   
            glPushMatrix();
                scale().rotate(0).translate(0,0,0);
                float *tpos = value_ptr(position);
                float *verts;
                glTranslatef(tpos[0], tpos[1], tpos[2]);
                glBindTexture(GL_TEXTURE_2D, texid);
                glBegin(GL_TRIANGLES);
                    for(int i = 0; i < vertices.size(); i++){
                        verts = value_ptr(vertices[i]);
                            glVertex3f(verts[0], verts[1], verts[2]);
                            glTexCoord2fv(value_ptr(uvs[i]));  
                    }
                glEnd();
            glPopMatrix();
        }

    private:

};

#endif