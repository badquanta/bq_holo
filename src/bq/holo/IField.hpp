/*
 * IField.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef BQ_HOLO_IFIELD_HPP_
#define BQ_HOLO_IFIELD_HPP_
#include "types.hpp"
namespace bq {
  namespace holo {

    class IField {
      public:
        IField();
        virtual ~IField();
        virtual bool forget(GramID eraseEID)=0;
        virtual std::type_index getID()=0;
        virtual bool has(GramID eid)=0;
        IField(const IField &other)=delete;
        IField(IField &&other)=delete;
        IField& operator=(const IField &other)=delete;
        IField& operator=(IField &&other)=delete;
    };

  } /* namespace holo */
} /* namespace bq */

#endif /* BQ_HOLO_IFIELD_HPP_ */
