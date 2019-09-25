#ifndef _STARTUP_FRAME_H_
#define _STARTUP_FRAME_H_

#include "../AbstractClasses/LcdFrame.h"

#define STARTING_MESSAGE "Booting System!"

class StartUpFrame : public LcdFrame {

  void setup( ) override;
  void draw( ) override;
};

#endif // STARTUP_FRAME_H_