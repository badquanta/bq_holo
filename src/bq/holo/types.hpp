/*
 * types.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef HOLO_TYPES_HPP_
#define HOLO_TYPES_HPP_
#include <inttypes.h>
#include <typeinfo>
#include <typeindex>
#include <set>
#include <map>
#include <vector>
#include <functional>
#include <glm/vec4.hpp>
namespace bq {
  namespace holo {
    typedef glm::ivec4 Origin;
    typedef glm::ivec4 Velocity;
    typedef uint32_t GramID;
    typedef uint32_t ComponentValueID;
    typedef std::type_index ComponentTypeIDX;
    typedef std::vector<ComponentTypeIDX> ComponentTypeList;
  }
}




#endif /* HOLO_TYPES_HPP_ */
