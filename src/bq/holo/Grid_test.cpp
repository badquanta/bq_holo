/*
 * Grid_test.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#include "Grid.hpp"
#include "fields.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
namespace bq {
  namespace holo {
    /*
     * Grid_test.cpp
     *
     * * [ ] TODO: Test `Grams`
     * * [ ] TODO: Test `Fields`
     * ** [ ] TODO: Test `Emitter`
     * * [ ] TODO: Test `Protocols`
     * @link http://slashdot.org
     */

    TEST_CASE("bq::pd::GameSpace::Field<Origin>")
    {

      OriginField origins(Origin { 0.0, 0.0, 0.0, 0.0 });
      VelocityField componentVelocity(Velocity { 0 });
      Origin origin = { 1.0, 123.0, 1.0, 1.0 };
      Velocity velocity = { 1.0, -1.0, 0.0, 1.0 };
      GramID fake = 1;
      CHECK_FALSE(origins.has(fake))
      ;
      CHECK_FALSE(origins.forget(fake))
      ;
      origins.set(fake, origin);
      CHECK(origins.has(fake))
      ;
      const Origin *readFakeOrigin = origins.get(fake);
      CHECK((fabs(readFakeOrigin->y-123.0f)< 0.1))
      ;
      CHECK(origins.forget(fake))
      ;
      CHECK_FALSE(origins.has(fake))
      ;
      const Origin *readZero = origins.get(0);
      readFakeOrigin = origins.get(fake);
      CHECK_EQ(readZero,readFakeOrigin)
      ;
      SUBCASE("System") {
        //System<physics,origins,componentVelocity>
      }
    }

    TEST_CASE("learn about type info..."){
      std::type_index mine = std::type_index(typeid(Origin));

    }

  } /* namespace holo */
} /* namespace bq */
