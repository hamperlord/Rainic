#ifndef CORE_INPUT_HANDLEKBM_H
#define CORE_INPUT_HANDLEKBM_H

#include <SDL3/SDL.h>

class HandleKBM {
public:
  static HandleKBM &getInstance();

  void initialize();
  void uninitialize();

  void handleEvent(const SDL_Event &event);
};

#endif