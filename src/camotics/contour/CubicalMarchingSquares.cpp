/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#include "CubicalMarchingSquares.h"

using namespace CAMotics;


void CubicalMarchingSquares::doSlice(FieldFunction &func,
                                     const CubeSlice &slice, unsigned z) {
}


void CubicalMarchingSquares::doCell(const CubeSlice &slice, unsigned x,
                                    unsigned y) {
  //uint8_t index = slice.getEdges(x, y, edges);
  //Vector3R vertices[3];
}
