/*
 * IProtocol.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef BQ_HOLO_IPROTOCOL_HPP_
#define BQ_HOLO_IPROTOCOL_HPP_
#include "types.hpp"
namespace bq {
  namespace holo {

    class IProtocol {
      public:
        IProtocol();
        virtual ~IProtocol();
      protected:
        ComponentTypeList requirements;
        ComponentTypeList uses;
        ComponentTypeList excludes;
      public:
        typedef std::function<void(void)> Callback;
        virtual void process()=0;
        virtual ComponentTypeList getRequired() {
          return requirements;
        }
        ;
        virtual ComponentTypeList getUses() {
          return uses;
        }
        ;
        virtual ComponentTypeList getExcludes() {
          return excludes;
        }
        ;
        IProtocol(const IProtocol &other) = delete;
        IProtocol(IProtocol &&other) = delete;
        IProtocol& operator=(const IProtocol &other) = delete;
        IProtocol& operator=(IProtocol &&other) = delete;
    };

  } /* namespace holo */
} /* namespace bq */

#endif /* BQ_HOLO_IPROTOCOL_HPP_ */
