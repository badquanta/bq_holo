/*
 * Arch.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef BQ_HOLO_ARCH_HPP_
#define BQ_HOLO_ARCH_HPP_

namespace bq {
  namespace holo {
    /**
     * The `holo::Arch` is to a ProtoDeck `holo::Grid`
     * what a "factory/loader" is to an "Entity-Component-System"
     */
    class Arch {
      public:
        Arch();
        virtual ~Arch();
        Arch(const Arch &other)=delete;
        Arch(Arch &&other)=delete;
        Arch& operator=(const Arch &other)=delete;
        Arch& operator=(Arch &&other)=delete;
    };

  } /* namespace holo */
} /* namespace bq */

#endif /* BQ_HOLO_ARCH_HPP_ */
