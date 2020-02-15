/*
 * Sprite.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: badquanta
 */

#include "Sprite.hpp"

#include "bq/sdl2/Log.hpp"
#include "bq/sdl2/Renderer.hpp"
#include "bq/sdl2/Texture.hpp"
namespace bq { namespace holo {
    using namespace sdl2;
    bool Sprite::nextFrame() {

      if (fFrames.size() > 0) {
        Log::Render.info("FrameNo#%d of %d",fFrame,fFrames.size());
        fFrame++;
        if (fFrame >= fFrames.size()) fFrame = 0;
        fClip = fFrames[fFrame];
        return true;
      } else {
        Log::Render.info("No Frames");
      }

    }
    Sprite::Sprite() {// @suppress("Class members should be properly initialized")
    }
    bool Sprite::renderAt(const SDL_Point& p, const double angle,
        const SDL_RendererFlip flip){
      SDL_Rect dstRect=fClip;
      dstRect.x = p.x;
      dstRect.y = p.y;
      return fTexture->fRenderer->copyEx(fTexture, &fClip, &dstRect, angle, nullptr, flip);
    }
    bool Sprite::renderAt(const SDL_Point &p) const {
      SDL_Rect at = fClip;
      at.x = p.x;
      at.y = p.y;
      return fTexture->fRenderer->copy(fTexture, &fClip, &at);
    }

    bool Sprite::renderAt(const SDL_Rect &dstRect) const {
      return fTexture->fRenderer->copy(fTexture, &fClip, &dstRect);
    }
    /** Add's sprite's clip origins to src rect; leaves src rect w&h alone.**/
    bool Sprite::renderAt(const SDL_Rect &src,
        const SDL_Rect &dst) const {
      SDL_Rect srcPlus = { fClip.x + src.x, fClip.y + src.y,
          src.w, src.h };
      return fTexture->fRenderer->copy(fTexture, &srcPlus, &dst);
    }
    Sprite::Sprite(Texture_sptr t,
        const std::vector<SDL_Rect> clipFrames)
        : fFrame { 0 }, fTexture { t }, fFrames { clipFrames }, fClip {
} {

    }

    Sprite::Sprite(Texture_sptr t)
        : fFrame { 0 }, fTexture { t }, fClip { 0, 0, t->bounds.x,
            t->bounds.y } {
      // TODO Auto-generated constructor stub
      Log::Render.info("Sprite Created.");
    }

    Sprite::Sprite(Texture_sptr t, const SDL_Rect c)
        : fFrame { 0 }, fTexture { t }, fClip { c } {
      Log::Render.info("Sprite Created.");
    }

    Sprite::~Sprite() {
      Log::Render.info("Sprite Destroyed.");
    }

    Sprite::Sprite(const Sprite &other) {// @suppress("Class members should be properly initialized")
      // TODO Auto-generated constructor stub

    }

    Sprite::Sprite(Sprite &&other) {// @suppress("No return") // @suppress("Class members should be properly initialized")
      // TODO Auto-generated constructor stub

    }

    Sprite& Sprite::operator=(const Sprite &other) {// @suppress("No return")
      // TODO Auto-generated method stub

    }

    Sprite& Sprite::operator=(Sprite &&other) {
      if(&other==this){return *this;}
      Log::Render.info("Sprite::operator= Copy&&other");
      fTexture = other.fTexture;
      fFrame = other.fFrame;
      fClip = other.fClip;
      fFrames = other.fFrames;
      return *this;
    }
  }

} /* namespace bq */
