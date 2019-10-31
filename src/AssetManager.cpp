//
// Created by Jedrzej Lewandowski on 30/10/2019.
//

#include "./AssetManager.h"

AssetManager::AssetManager(EntityManager *manager) : manager(manager) {

}

void AssetManager::ClearData() {
    textures.clear();
}

void AssetManager::AddTexture(std::string textureId, const char *filePath) {
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

SDL_Texture * AssetManager::GetTexture(const std::string& textureId) {
    return textures[textureId];
}