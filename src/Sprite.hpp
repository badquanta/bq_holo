/*
 * Sprite.h
 *
 *  Created on: Feb 5, 2020
 *      Author: badquanta
 */

#ifndef SDL2_SPRITE_HPP_
#define SDL2_SPRITE_HPP_
#include <SDL2/SDL.h>
#include <vector>

#include <bq/sdl2/shared_ptrs.hpp>
namespace bq {
  namespace holo {

    class Sprite {
      public:
        Sprite();
        Sprite(sdl2::Texture_sptr t);
        Sprite(sdl2::Texture_sptr t, const SDL_Rect c);
        Sprite(sdl2::Texture_sptr t,
            const std::vector<SDL_Rect> clipFrames);
        virtual ~Sprite();
        virtual bool nextFrame();

        virtual bool renderAt(const SDL_Point&) const;
        virtual bool renderAt(const SDL_Rect&) const;
        virtual bool renderAt(const SDL_Rect &src,
            const SDL_Rect &dst) const;
        virtual bool renderAt(const SDL_Point&, const double,
            const SDL_RendererFlip);

        int fFrame;
        SDL_Rect fClip;
        std::vector<SDL_Rect> fFrames;
        sdl2::Texture_sptr fTexture;

        Sprite(const Sprite &other) = delete;
        Sprite(Sprite &&other) = delete;
        Sprite& operator=(const Sprite &other) = delete;
        Sprite& operator=(Sprite &&other) = delete;
      protected:
    };

  } /* namespace sdl2 */
} /* namespace bq */

#endif /* SDL2_SPRITE_HPP_ */
