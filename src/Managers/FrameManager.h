#ifndef _FRAME_MANAGER_H_
#define _FRAME_MANAGER_H_

/* Frame Manager Class will manage the frames and its draws, it has a state
 * machine with lots of states inside (Frames)*/

#include "../Common.h"
#include "../GlobalMenuStates.h"
#include "U8glib.h"

#define FPS 30
#define LCD_WIDTH 128
#define LCD_HEIGHT 64

class LcdFrame;
class LcdManager;

class FrameManager {

  public:
  void setup( );
  void draw( );

  void setupCurrentFrame( );

  // Use an enum to point to a new Frame, be sure the indexes are the same
  template <typename frameName> void setFrame(frameName frame) {
    this->currentFrame = this->framePool[frame];
  };

  void addFrame(uint8_t position, LcdFrame* newFrame);

  // TODO define goNextFrame()
  void goNextFrame( );

  // TODO define goPreviousFrame()
  void goPreviousFrame( );

  // Get a pointer to the current frame
  LcdFrame* getFrame( );

  // Get a pointer to the current Screen
  U8GLIB_ST7920_128X64* getScreen( );

  // Return lcd manager
  LcdManager* getLcdManager( );

  private:
  uint32_t currentTime; // Current time to mesure fps

  LcdFrame** framePool;    // Group of frames
  LcdFrame*  currentFrame; // Current fame being displayed

  // Screen of library U8glib
  U8GLIB_ST7920_128X64 screen =
      U8GLIB_ST7920_128X64(LCD_SCK, LCD_MOSI, LCD_CS, U8G_PIN_NONE);

  LcdManager* manager;
};

#endif // !_FRAME_MANAGER_H_
