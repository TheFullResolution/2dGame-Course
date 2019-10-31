#include "./EntityManager.h"
#include <iostream>

void EntityManager::ClearData() {
    for (auto &entity: entities) {
        entity->Destroy();
    }
}

bool EntityManager::HasNoEntities() {
    return entities.size() == 0;
}

void EntityManager::Update(float deltaTime) {
    for (auto &entity: entities) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (auto &entity: entities) {
        entity->Render();
    }
}

Entity &EntityManager::AddEntity(std::string entityName) {
    auto *entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity *> EntityManager::GetEntities() const {
    return entities;
}

unsigned int EntityManager::GetEntityCount() {
    return entities.size();
}

void EntityManager::ListAllEntities() {
    for (auto &entity: entities) {
        std::cerr << "Entity Name: " << entity->name << std::endl;
        entity->ListAllComponents();
    }
}