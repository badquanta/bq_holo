/*
 * Protocol.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef HOLO_PROTOCOL_HPP_
#define HOLO_PROTOCOL_HPP_
#include "IProtocol.hpp"
namespace bq {
  namespace holo {
    /**
     * TODO: Better documentation
     * @note Protocols is to `holo::Deck` as "System" is to "Entity-Component-Systems"
     */
    class Protocol : public IProtocol {
      public:
        const Callback callback;
        Protocol(std::function<void(void)> c);
        virtual ~Protocol() override;
        virtual void process() override {
          callback();
        }

      public:

        Protocol(const Protocol &other)=delete;
        Protocol(Protocol &&other)=delete;
        Protocol& operator=(const Protocol &other)=delete;
        Protocol& operator=(Protocol &&other)=delete;
    };

  } /* namespace holo */
} /* namespace bq */

#endif /* HOLO_PROTOCOL_HPP_ */
