#ifndef _LCD_FRAME_H_
#define _LCD_FRAME_H_

#include "../GlobalMenuStates.h"
#include "../Managers/FrameManager.h"
#include "Arduino.h"
#include "U8glib.h"

class LcdFrame { // State of a State Machine
  public:
  // Initialize the frame
  virtual void setup( ) = 0;

  // Draw the frame into the lcd
  virtual void draw( ) = 0;

  // Set a new frame manager
  void setFrameManager(FrameManager* newManager);

  // Pass a new state (enum) in order to manage the logic of the frame
  template <typename machineState> void setState(machineState newMachineState) {
    this->currentMachineState = newMachineState;
  };

  // Return the manager
  FrameManager* getManager( );

  protected:
  /*Lcd which this frame is from */
  FrameManager* manager;

  // State based on the enum passed through setState
  uint8_t currentMachineState;
};

#endif // !_LCD_FRAME_H_
