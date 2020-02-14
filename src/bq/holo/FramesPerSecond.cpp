/*
 * FramesPerSecond.cpp
 *
 *  Created on: Feb 9, 2020
 *      Author: badquanta
 */

#include "FramesPerSecond.hpp"

namespace bq {
  namespace pd {

    FramesPerSecond::FramesPerSecond(int target):fTargetFPS(target) {
      // TODO Auto-generated constructor stub
      fTotalTime.start(true);
      fFrameTime.start(true);
    }

    FramesPerSecond::~FramesPerSecond() {
      // TODO Auto-generated destructor stub
    }

    void FramesPerSecond::newFrame(bool sleep){
      fTotalTime.start(); fFrameCount++;
      int ticksLeft = ticksPerFrameLeft();
      if(sleep && (ticksLeft>0))SDL_Delay(ticksLeft);
      fFrameTime.start(true);
    }

    float FramesPerSecond::getFPS(){
      Uint32 elapsed = fTotalTime.getElapsed();
      return fFrameCount / (elapsed/1000.f);
    }
    Uint32 FramesPerSecond::ticksPerFrame(){
      return 1000/fTargetFPS;
    }
    inline int FramesPerSecond::ticksPerFrameLeft(){
      return ticksPerFrame()-fFrameTime.getElapsed();
    }

  } /* namespace pd */
} /* namespace bq */
