#ifndef _SCENE_OBJECT_INCLUDED

    #define _SCENE_OBJECT_INCLUDED
        
    #include <string>
    #include <iostream>
    #include <vector>
    #include <glm/glm.hpp>
    #include <glm/gtc/type_ptr.hpp>

    using glm::vec3,
        glm::vec4,
        glm::mat4,
        glm::value_ptr;

    // template <class BaseSceneObject>
    class SceneObject{
        protected:
            vec3 position;
            vec4 direction;
        
        public:
            bool is_active = true;
            
        public:
            SceneObject(float x=0 , float y=0, float z=0);
            ~SceneObject();
            virtual void translate(float x, float y, float z);
            void rotate(float degrees, float x=0, float y=1, float z=0);
            void scale(float x=1, float y=1, float z=1);
            virtual void render();

        public:
            float get_x();
            float get_y();
            float get_z();
            void set_x(float x);
            void set_y(float y);
            void set_z(float z);

    };
#endif

