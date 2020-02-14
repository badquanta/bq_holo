/*
 * Grid.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef HOLO_GRID_HPP_
#define HOLO_GRID_HPP_

namespace bq {
  /**
   * Holo-* Terms:
   * * holo-__grid__ == "World"
   * container of holo-graphic systems
   * * holo-__graphic__ == "System<Renderer>"
   * subsystem dedicated to rendering visualizations
   * ** holo-__diodes__: == "???" ?SDL?Windows?
   * omnidirectional emitters
   * ** holo-__projections__: maco object replications
   * * holo-__grams__ = "Entity"
   * virtual/logical subunits projected by holo-grid
   * * holo-__base__: Database-like structure holding details of holo-sim
   * * holo-__arch__: Internal user-interface control system.
   * *
   */
  namespace holo {
    /**
     * A Grid is an implementation of an "Entity Component System"
     */
    class Grid {
      public:
        Grid();
        virtual ~Grid();
        Grid(const Grid &other)=delete;
        Grid(Grid &&other)=delete;
        Grid& operator=(const Grid &other)=delete;
        Grid& operator=(Grid &&other)=delete;
    };

  } /* namespace holo */
} /* namespace bq */

#endif /* HOLO_GRID_HPP_ */
