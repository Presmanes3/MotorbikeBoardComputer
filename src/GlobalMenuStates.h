#ifndef _GLOBAL_MENU_STATES_H_
#define _GLOBAL_MENU_STATES_H_

namespace GlobalMenu {

  enum FrameNames {startUpFrame = 0, mainFrame};

  namespace Frames {
    enum Main { LedStrip = 0, Accelerometer, Time }; // namespace Main

  } // namespace Frames
} // namespace GlobalMenu

#endif