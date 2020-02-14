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
namespace bq {namespace pd {

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
        Sprite(const Sprite &other);
        Sprite(Sprite &&other);
        Sprite& operator=(const Sprite &other);
        Sprite& operator=(Sprite &&other);
        int fFrame;
        std::vector<SDL_Rect> fFrames;
        SDL_Rect fClip;
        sdl2::Texture_sptr fTexture;
      protected:
    };

  } /* namespace sdl2 */
} /* namespace bq */

#endif /* SDL2_SPRITE_HPP_ */
