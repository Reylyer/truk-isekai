#include <SceneObject.hpp>
#include <Scene.hpp>
#include <Game.hpp>
#include <map>
#include <string>

using   std::map,
        std::string;

Scene::Scene(Game &game, string name){
    this->game = &game;
    this->name = name;
}
void Scene::update(){
    printf("Me terpanggil\n");
    render();
}
void Scene::setup(){}
void Scene::reset(){}
void Scene::render(){
    view();
}
void Scene::view(){}
