#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

#include "./EntityManager.h"
#include "./Component.h"

class EntityManager;

class Component;

class Entity {
private:
    EntityManager &manager;
    bool isActive;
    std::vector<Component *> components;

public:
    Entity(EntityManager &manager);

    Entity(EntityManager &manager, std::string name);

    ~Entity();

    void Update(float deltaTime);

    void Render();

    void Destroy();

    bool IsActive() const;

    std::string name;

    template<typename T, typename... TArgs>
    T &AddComponent(TArgs &&... args) {
        T *newComponent(new T(std::forward<TArgs>(args)...));

        newComponent->owner = this;
        components.emplace_back(newComponent);
        newComponent->Initialize();
        return *newComponent;
    }
};

#endif // ENTITY_H