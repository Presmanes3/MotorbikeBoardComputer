#ifndef _MAIN_FRAME_H_
#define _MAIN_FRAME_H_

#include "../AbstractClasses/LcdFrame.h"
#include "../GlobalMenuStates.h"
#include "Arduino.h"

class MainFrame : public LcdFrame {

  public:
  void draw( ) override;
  void setup( ) override;

  void setState(GlobalMenuStates* newState) override;

  private:
};

#endif // !_MAIN_FRAME_H_
