/*
 * Gram.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef HOLO_FIELD_HPP_
#define HOLO_FIELD_HPP_
#include "types.hpp"
#include "IField.hpp"
namespace bq {
  namespace holo {
    /** holo::Gram(s) are the "Entity" in
     * Proto-deck's "Entity-Component-System":
     * `holo::Grid`
     ***/
    template<class T>
    class Field : public IField {
      protected:
        ComponentValueID nextValueID = 1;
      private:
        std::vector<T> fValues;
        std::map<GramID, ComponentValueID> EID2IDX;
        std::map<ComponentValueID, GramID> IDX2EID;
      public:
        const static std::type_index ID;
        const T nullValue;
        Field(T nv)
            : nullValue(nv) {
          fValues = std::vector<T>(8, nullValue);
          fValues[0] = nullValue;
          nextValueID = 1;
        }
        virtual ~Field() {
          //TODO: Gram Destruction?
        }
        virtual std::type_index getID() override {
          return ID;
        }
        virtual bool has(GramID eid) override {
          return (EID2IDX[eid] != 0);
        }
        bool set(GramID eid, const T &value) {
          if (eid == 0) return false;
          ComponentValueID idx;
          if (has(eid)) {
            idx = EID2IDX[eid];
          } else {
            nextValueID = (idx = nextValueID) + 1;
            EID2IDX[eid] = idx;
            IDX2EID[idx] = eid;
          }
          if (!idx < fValues.size()) {
            fValues.reserve(8);
          }
          fValues[idx] = value;
          return true;
        }
        const T* get(GramID eid) {
          if (EID2IDX[eid] != 0) {
            return &fValues[EID2IDX[eid]];
          } else {
            return &fValues[0];
          }
        }

        virtual bool forget(GramID eraseEID) override {

          if (!eraseEID || !EID2IDX[eraseEID]) return false;
          ComponentValueID lastCVID = --nextValueID;
          if (eraseEID && EID2IDX[eraseEID]) {
            ComponentValueID eraseCVID = EID2IDX[eraseEID];
            // Since we are removing one; we'll decrese the nextValueID by one.

            //It now should be the same as the last value ID in the vector
            if (eraseCVID != (lastCVID)) { //if the cvID2erase for eID is not that last value ID
              // Then we should copy that last value to where this value was.
              // but first we need to know what entity this was for too:
              GramID lastEID = IDX2EID[lastCVID];
              if (lastEID != 0) {              //did we find it?
                fValues[eraseCVID] = fValues[lastCVID];
                // Update the index of that value we just copied.
                EID2IDX[lastEID] = eraseCVID;
                IDX2EID[eraseCVID] = lastCVID;

              } else {

              }
            }
          }
          fValues[lastCVID] = nullValue;
          EID2IDX.erase(eraseEID);
          IDX2EID.erase(lastCVID);
          return true;
        }
        Field(const Field &other) = delete;
        Field(Field &&other) = delete;
        Field& operator=(const Field &other) = delete;
        Field& operator=(Field &&other) = delete;
    };


    template<typename T> const std::type_index Field<T>::ID = std::type_index(typeid(T));

  } /* namespace holo */
} /* namespace bq */

#endif /* HOLO_FIELD_HPP_ */
