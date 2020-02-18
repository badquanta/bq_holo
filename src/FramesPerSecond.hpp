/*
 * FramesPerSecond.hpp
 *
 *  Created on: Feb 9, 2020
 *      Author: badquanta
 */

#ifndef BQ_HOLO_FRAMESPERSECOND_HPP_
#define BQ_HOLO_FRAMESPERSECOND_HPP_
#include <bq/sdl2/Timer.hpp>
namespace bq {
  namespace holo {
    class FramesPerSecond {
      private:
        long int fFrameCount = 0;
        sdl2::Timer fFrameTime;
        sdl2::Timer fTotalTime;
        int fTargetFPS;
      public:
        FramesPerSecond(int targetFPS);
        virtual ~FramesPerSecond();
        void newFrame(bool sleep=true);
        Uint32 getFrameStartTicks();
        float getFPS();
        // May be a negative number.
        int ticksPerFrameLeft();
        Uint32 ticksPerFrame();
        Uint32 getTargetFPS();
        Uint32 setTargetFPS();

        // copy/assignment not used.
        FramesPerSecond(const FramesPerSecond &other)=delete;
        FramesPerSecond(FramesPerSecond &&other)=delete;
        FramesPerSecond& operator=(const FramesPerSecond &other)=delete;
        FramesPerSecond& operator=(FramesPerSecond &&other)=delete;

    };

  } /* namespace holo */
} /* namespace bq */

#endif /* BQ_HOLO_FRAMESPERSECOND_HPP_ */
