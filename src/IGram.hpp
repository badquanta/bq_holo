/*
 * IArch.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: badquanta
 */

#ifndef BQ_HOLO_IGRAM_HPP_
#define BQ_HOLO_IGRAM_HPP_
#include "types.hpp"
namespace bq {
  namespace holo {
    /**
     * Interface to `holo::Gram`s:
     *
     * These are the "Entity" in pd's Entity-Component-System.
     *
     * Here is some ascii art about it:┛║╝╛╕╔═╰─╛┛║╝╛╕╔═╰─┒┃╚┛
     * ─━
     * │┃
     * ┄┅
     * ┆┇
     * ┈┉
     * ┊┋
     * ┌┍┎┏ ┐┑┒┓  └┕┖┗  ┘┙┚┛
     * ├┝┞┟┠┡┢┣ ┤┥┦┧┨┩┪┫  ┬┭┮┯┰┱┲┳  ┴┵┶┷┸┹┺┻
     * ┼┽┾┿╀╁╂╃╄╅╆╇╈╉╊╋
     * ╌╍
     * ╎╏
     * ═║ ╒╓╔ ╕╖╗ ╘╙╚ ╛╜╝ ╞╟╠ ╡╢╣ ╤╥╦ ╧╨╩ ╪╫╬
     * ╭╮ ╯╰╱ ╲╳╴╵╶╷╸╹╺╻  ╼╽╾╿
     *    ╔════════╕
     *    ║        ╰───────────────────╮
     *    ║ Entity      Components     │
     *    ║        ┌───┐┄┎─╖┄╓─╮┄╭─────╯
     *    ╚════════╛   ╽P┃ ║F║ │T|
     *                 ╏H╏ ║R║ │E|
     *                 ┇Y┇ ║A║ |X|
     *                 ╹S╹ ║M║ |T|
     *                 ╿I╿ ║E║ |U|
     *                 ╰C╯ ╚═╝ |R|
     *                  S      |E|
     *                         ╘═╛
     *
     ***************************************************************/
    class IGram {
      public:
        IGram();
        virtual ~IGram();
      public:
        virtual std::type_index getID()=0;
        virtual bool has(GramID)=0;
        virtual bool forget(GramID)=0;

        IGram(const IGram &other) = delete;
        IGram(IGram &&other) = delete;
        IGram& operator=(const IGram &other) = delete;
        IGram& operator=(IGram &&other) = delete;
    };

  } /* namespace holo */
} /* namespace bq */

#endif /* BQ_HOLO_IGRAM_HPP_ */
