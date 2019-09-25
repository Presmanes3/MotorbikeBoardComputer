#ifndef LCD_H_
#define LCD_H_

/* This class will be the manager of managers, its aim is to access the managers
 * trough a common class*/

#include "../Common.h"
#include "U8glib.h"

class Controller;
class FrameManager;

#define FPS 30
#define LCD_WIDTH 128
#define LCD_HEIGHT 64

class LcdManager {

  public:
  void setup( );
  void draw( );
  void update( );

  // Point to new frame
  FrameManager* getFrameManager( );
  Controller*   getController( );

  private:
  FrameManager* frameManager;
  Controller*   controller;
};

#endif // !LCD_H_
