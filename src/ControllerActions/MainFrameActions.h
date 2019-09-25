#ifndef _MAIN_FRAME_ACTIONS_H_
#define _MAIN_FRAME_ACTIONS_H_


#include "Arduino.h"
#include "../AbstractClasses/ControllerAction.h"


namespace MainFrameAction {
  class Up : public ControllerAction {
    public:
    void execute( ) override;
  };
  class Down : public ControllerAction {
    public:
    void execute( ) override;
  };
  class Click : public ControllerAction {
    public:
    void execute( ) override;
  };
  class Press : public ControllerAction {
    public:
    void execute( ) override;
  };
  class Null : public ControllerAction {
    public:
    void execute( ) override;
  };
} // namespace MainFrameAction

// namespace MainFrameActions

#endif // !_MAIN_FRAME_ACTIONS_H_
