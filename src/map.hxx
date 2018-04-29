#ifndef MAP_HXX_
#define MAP_HXX_


#include <string>
#include <cmath>
#include <vector>

//#include "yaml-cpp/yaml.h"
#include "SDL.h"

#include "sprite.hxx"
#include "point.hxx"
#include "vectorMatrix.hxx"


class Map
{
public:

  int _width = 16;
  int _height = 16;
  int mmap[16][16];

  Map(SDL_Renderer *renderer, SDL_Window *window);
  virtual ~Map();

  void parseMapFile();

  void render();

  void Map::centerScreenOnPoint(Point isoCoordinates);

  Point getIsoCoords(Point screenCoordinates, bool calcWithoutOffset = false);
  Point getScreenCoords(Point isoCoordinates, bool calcWithoutOffset = false);
  void Map::findNeighbors(Point isoCoords);

  Point getCameraOffset();
  void setCameraOffset(Point offset);

  bool checkBoundaries(Point isoCoordinates);

  float getZoomLevel();
  void setZoomLevel(float zoomLevel);

  void toggleGrid();

private:
  bool _drawGrid = false;

  int _screen_width;
  int _screen_height;

  float _zoom = 1.0;
  Point _cameraOffset;
  Point _centerScreenCoords;

  vectorMatrix _floorTilesMatrix;
  vectorMatrix _gridTilesMatrix;
};


#endif 