/*
 * Program.h
 *
 *  Created on: Feb 1, 2020
 *      Author: badquanta
 */

#ifndef PROGRAM_HPP_
#define PROGRAM_HPP_
#include "bq/sdl2/EventDispatch.hpp"
#include "bq/sdl2/shared_ptrs.hpp"

namespace bq { namespace holo {

  bool ensureWindowCreated(sdl2::Window_sptr &win, int w, int h,
      std::string_view str);
  bool ensureRendererCreated(const sdl2::Window_sptr &win, sdl2::Renderer_sptr &ren);
  bool ensureRendererCreated(const sdl2::Window_sptr &win, sdl2::Renderer_sptr &ren, int flags);
  bool ensureBmpLoaded(sdl2::Surface_sptr&surf,std::string_view);
  bool ensureImageLoaded(sdl2::Surface_sptr&sruf,std::string_view);
  bool ensureImageLoaded(const sdl2::Renderer_sptr& ren, sdl2::Texture_sptr&text,std::string_view);
  bool ensureTTFLoaded(sdl2::TTF_sptr&ttf,std::string_view,int ptSize,int idx=0);
  bool ensureTextSolid(const sdl2::TTF_sptr&ttf,sdl2::Surface_sptr&, std::string_view, SDL_Color);
  bool ensureTextSolid(const sdl2::Renderer_sptr&ren, const sdl2::TTF_sptr&ttf,sdl2::Texture_sptr&, std::string_view, SDL_Color);
  class Program {
    protected:
      bool fQuitRequested;

    public:
      sdl2::events::ProgramHandler events;
      sdl2::EventHandler quitHandler;
      Program();
      virtual ~Program();
      Program(const Program &other);
      Program(Program &&other);
      Program& operator=(const Program &other);
      Program& operator=(Program &&other);
      virtual bool init();
      virtual bool load();
      virtual void close();
      virtual bool updateFrame(bool refresh = false);
      virtual int frameLoop();
      virtual bool quitRequested();
      virtual void quit();

  };
}
} /* namespace bq */

#endif /* PROGRAM_HPP_ */
