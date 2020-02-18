/*
 * Button.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: badquanta
 */

#include "Button.hpp"
#include <SDL2/SDL_rect.h>

#include <bq/sdl2/Log.hpp>
#include <bq/sdl2/Texture.hpp>
namespace bq { namespace holo {
  int Button::trigger(const SDL_Event &e) {
    int count = 0;
    sdl2::Log::Custom.info(__PRETTY_FUNCTION__);
    static bool mouseWasOver = false;
    static bool wasPressed = false;
    SDL_Point mPos;
    switch (e.type) {
      case SDL_MOUSEMOTION:
        mPos = { e.motion.x, e.motion.y };
        if (SDL_PointInRect(&mPos, &fPosition)){
          if (!mouseWasOver) {
            mouseWasOver = true;
            count+=onMouseIn.trigger(e);
          } else {
            count+=onMouseOver.trigger(e);
          }
        } else {
          if (mouseWasOver) {
            mouseWasOver = false;
            count+=onMouseOut.trigger(e);
          }
        }

        break;

      case SDL_MOUSEBUTTONDOWN:
        if (mouseWasOver) {
          if (!wasPressed) {
            wasPressed = true;
            count+=pressed.trigger(e);
          }

        }

        break;

      case SDL_MOUSEBUTTONUP:
        if(wasPressed){
          wasPressed = false;
          if(mouseWasOver){
            count+=clicked.trigger(e);
          }
          count+=released.trigger(e);
        }

        break;

      default:
        sdl2::Log::Custom.info("button trigger ignored event.");

    }
    return count;
  }

  bool Button::render() const {

    return (texture) && (texture->render(fPosition));
  }
  Button::Button(const SDL_Rect &pos, sdl2::Texture_sptr &f)
      : fPosition(pos),texture(f) {

    // TODO Auto-generated constructor stub

  }

  Button::Button()
      : fPosition { 0, 0, 0, 0 }, texture(nullptr) {

  }

  Button::~Button() {

    texture = nullptr;
  }
/**
  Button::Button(const Button &other) {
    // TODO Auto-generated constructor stub

  }

  Button::Button(Button &&other) {
    // TODO Auto-generated constructor stub

  }

  Button& Button::operator=(const Button &other) {
    // TODO Auto-generated method stub

  }

  Button& Button::operator=(Button &&other) {
    // TODO Auto-generated method stub

  }
**/
} } /* namespace bq */
