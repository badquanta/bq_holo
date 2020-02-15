/*
 * Button.h
 *
 *  Created on: Feb 5, 2020
 *      Author: badquanta
 */

#ifndef BUTTON_HPP_
#define BUTTON_HPP_
#include <bq/sdl2/EventDispatch.hpp>
#include <bq/sdl2/shared_ptrs.hpp>
#include "SDL2/SDL.h"


namespace bq { namespace holo {
  class Button : public sdl2::EventDispatch {
    public:
      sdl2::EventDispatch onMouseOver;
      sdl2::EventDispatch onMouseIn;
      sdl2::EventDispatch onMouseOut;
      sdl2::EventDispatch pressed;
      sdl2::EventDispatch released;
      sdl2::EventDispatch clicked;
      sdl2::Texture_sptr texture;
      SDL_Rect fPosition;
      Button();
      Button(const SDL_Rect &pos, sdl2::Texture_sptr &f);
      virtual ~Button();
      Button(const Button &other);
      Button(Button &&other);
      Button& operator=(const Button &other);
      Button& operator=(Button &&other);

      virtual int trigger(const SDL_Event&) override;
      virtual bool render() const;

    protected:


  };

} } /* namespace bq */

#endif /* BUTTON_HPP_ */
