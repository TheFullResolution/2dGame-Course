//
// Created by Jedrzej Lewandowski on 04/11/2019.
//

#ifndef INC_2DGAMEENGINE_MAP_H
#define INC_2DGAMEENGINE_MAP_H

#include <string>

class Map {
public:
  Map(std::string textureId, int scale, int tileSize);

  void LoadMap(std::string filePath, int mapSizeX, int MapSizeY);

  void AddTile(int sourceX, int sourceY, int x, int y);

private:
  std::string textureId;
  int scale;
  int tileSize;
};

#endif // INC_2DGAMEENGINE_MAP_H
