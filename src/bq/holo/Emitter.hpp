/*
 * Emitter.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef HOLO_EMITTER_HPP_
#define HOLO_EMITTER_HPP_

namespace bq {
  namespace holo {
    
    class Emitter {
      public:
        Emitter();
        virtual ~Emitter();
        Emitter(const Emitter &other);
        Emitter(Emitter &&other);
        Emitter& operator=(const Emitter &other);
        Emitter& operator=(Emitter &&other);
    };
  
  } /* namespace holo */
} /* namespace bq */

#endif /* HOLO_EMITTER_HPP_ */
