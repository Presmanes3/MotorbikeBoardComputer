#ifndef _LCD_FRAME_H_
#define _LCD_FRAME_H_

#include "../GlobalMenuStates.h"
#include "../Managers/FrameManager.h"
#include "Arduino.h"
#include "U8glib.h"

class LcdFrame { // State of a State Machine
  public:
  virtual void setup( ) = 0;
  virtual void draw( )  = 0;

  void setFrameManager(FrameManager* newManager);

  virtual void setState(GlobalMenuStates* newState) = 0;

  FrameManager* getManager( );

  protected:
  /*Lcd which this frame is from */
  FrameManager*     manager;
  GlobalMenuStates* globalMenuStates;
};

#endif // !_LCD_FRAME_H_
