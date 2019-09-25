#ifndef _FRAME_MANAGER_H_
#define _FRAME_MANAGER_H_

/* Frame Manager Class will manage the frames and its draws, it has a state
 * machine with lots of states inside (Frames)*/

#include "../Common.h"
#include "U8glib.h"

#define FPS 30
#define LCD_WIDTH 128
#define LCD_HEIGHT 64

class LcdFrame;

class FrameManager {

  public:
  void setup( );
  void draw( );

  void setupCurrentFrame( );

  // Point to new frame
  void setFrame(LcdFrame* frame);

  void addFrame(LcdFrame* newFrame);

  void goNextFrame( );
  void goPreviousFrame( );

  // Get current frame
  LcdFrame* getFrame( );

  U8GLIB_ST7920_128X64* getScreen( );

  private:
  uint32_t currentTime; // Current time to mesure fps

  LcdFrame** framePool;
  LcdFrame*  currentFrame; // Current fame being displayed
  uint32_t   totalFrames = 0;

  U8GLIB_ST7920_128X64 screen =
      U8GLIB_ST7920_128X64(LCD_SCK, LCD_MOSI, LCD_CS, U8G_PIN_NONE);
};

#endif // !_FRAME_MANAGER_H_
