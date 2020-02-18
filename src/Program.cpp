/*
 * Program.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: badquanta
 */

#include "Program.hpp"
#include "bq/sdl2/EventDispatch.hpp"
#include "bq/sdl2/Subsystem.hpp"
#include <SDL2/SDL.h>

#include "bq/sdl2/image.hpp"
#include "bq/sdl2/Log.hpp"
#include "bq/sdl2/Renderer.hpp"
#include "bq/sdl2/Surface.hpp"
#include "bq/sdl2/ttf/TTF.hpp"
#include "bq/sdl2/Window.hpp"
namespace bq { namespace holo {
  bool ensureWindowCreated(sdl2::Window_sptr &win, int w,
      int h, std::string_view str) {
    return ((win != nullptr)
        || ((win = sdl2::Window::create(w, h, str)) != nullptr));
  }
  bool ensureRendererCreated(const sdl2::Window_sptr &win,
      sdl2::Renderer_sptr &ren) {
    return ((ren != nullptr)
        || ((win != nullptr) && (ren = win->createRenderer())));
  }
  bool ensureRendererCreated(const sdl2::Window_sptr &win,
        sdl2::Renderer_sptr &ren, int flags) {
      return ((ren != nullptr)
          || ((win != nullptr) && (ren = win->createRenderer(-1, flags))));
  }
  bool ensureImageLoaded(const sdl2::Renderer_sptr &ren,
      sdl2::Texture_sptr &tex, std::string_view path) {
    return ((tex != nullptr)
        || ((ren != nullptr)
            && (tex = ren->loadTextureFromImage(path))));
  }
  bool ensureImageLoaded(sdl2::Surface_sptr &surf,
      std::string_view path) {
    return ((surf != nullptr) || (surf = sdl2::image::load(path)));
  }
  bool ensureBmpLoaded(sdl2::Surface_sptr &surf,
      std::string_view path) {
    return ((surf != nullptr)
        || (surf = sdl2::Surface::loadBMP(path)));
  }
  bool ensureTTFLoaded(sdl2::TTF_sptr &ttf,
      std::string_view path, int ptSize, int idx) {
    return ((ttf != nullptr)
        || (ttf = sdl2::TTF::open(path, ptSize, idx)));
  }
  bool ensureTextSolid(const sdl2::TTF_sptr &ttf,
      sdl2::Surface_sptr &surf, std::string_view str,
      SDL_Color &color) {
    return ((surf != nullptr)
        || ((ttf != nullptr)
            && (surf = ttf->renderText_Solid(str, color))));
  }
  bool ensureTextSolid(const sdl2::Renderer_sptr &ren,
      const sdl2::TTF_sptr &ttf,
      sdl2::Texture_sptr &texture,  std::string_view str,
      SDL_Color color) {
    return ((texture != nullptr)
        || ((ren != nullptr) && (ttf != nullptr)
            && (texture = ren->createTextureFromSurface(
                ttf->renderText_Solid(str, color)))));
  }
  Program::Program()
      : fQuitRequested(false), quitHandler(
          [this](const SDL_Event &e) -> bool {
            sdl2::Log::Application.info("Built in quit handler...");
            quit();
            return true;
          }) {
    events.quit.on(quitHandler);
  }

  Program::~Program() {
    close();
  }

  bool Program::init() {
    return (sdl2::init());
  }

  bool Program::load() {
    return (true);
  }

  void Program::close() {
    if (!SDL_QuitRequested()) sdl2::quit();
  }

  bool Program::updateFrame(bool refresh) {
    return (refresh);
  }

  int Program::frameLoop() {
    if (init() && load()) {
      fQuitRequested = false;
      while (!quitRequested()) {
        SDL_Event e;
        while (sdl2::pollEvent(&e)) {
          if (events.trigger(e)) {
            // event handled
            continue;
          } else {
            // TODO: event ignored.
          };
        }
        updateFrame(false);
      }
    }
    return 0;
  }

  bool Program::quitRequested() {
    return (fQuitRequested || SDL_QuitRequested());
  }

  void Program::quit() {
    fQuitRequested = true;
  }

  Program::Program(const Program &other)
      : fQuitRequested(false) {
    // TODO Auto-generated constructor stub
  }

  Program::Program(Program &&other)
      : fQuitRequested(false) {
    // TODO Auto-generated constructor stub

  }

  Program& Program::operator=(const Program &other) {
    // TODO Auto-generated method stub

  }

  Program& Program::operator=(Program &&other) {
    // TODO Auto-generated method stub

  }
}
} /* namespace bq */
