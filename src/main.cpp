/*
    rainic by hampercat.
    you may distribute modified versions of this code.
*/

#define SDL_MAIN_USE_CALLBACKS 1

#include "core/animations/Animation.h"

#include "SDL3/SDL_error.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_keyboard.h"
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"

#include <iostream>

using namespace std;

static SDL_Renderer *renderer;
static SDL_Window *window;
static string currentInput;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
  SDL_SetAppMetadata("Rainic Launcher", "v0.0.1", "com.hamperlord.rainic");

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    cout << "Could not initialize video. Error: %s" << SDL_GetError();
    return SDL_APP_FAILURE;
  }

  if (!SDL_Init(SDL_INIT_AUDIO)) {
    cout << "Could not initialize audio. Error: %s" << SDL_GetError();
    return SDL_APP_FAILURE;
  }

  SDL_CreateWindowAndRenderer("Rainic Launcher", 720, 1280,
                              SDL_WINDOW_FULLSCREEN, &window, &renderer);

  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
  SDL_RenderClear(renderer);

  // LOOP IS HERE -------------------
  
  // --------------------------------

  SDL_RenderPresent(renderer);
  return SDL_APP_CONTINUE;
  // code
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {

  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }

  if (event->type == SDL_EVENT_KEY_DOWN) {
    currentInput = SDL_GetKeyName(event->key.key);
  }

  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {}