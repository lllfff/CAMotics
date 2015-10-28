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

#include "RenderJob.h"

#include <camotics/contour/MarchingCubes.h>
#include <camotics/contour/MarchingSlices.h>
#include <camotics/contour/DualContouring.h>
#include <camotics/contour/CubicalMarchingSquares.h>

#include <cbang/Exception.h>
#include <cbang/time/Timer.h>
#include <cbang/util/DefaultCatch.h>

using namespace cb;
using namespace CAMotics;


RenderJob::RenderJob(FieldFunction &func, RenderMode mode,
                     real resolution, const Rectangle3R &bbox) :
  func(func), resolution(resolution), bbox(bbox) {
  switch (mode) {
  case RenderMode::MCUBES_MODE: generator = new MarchingSlices; break;
  case RenderMode::CMS_MODE: generator = new CubicalMarchingSquares; break;
  case RenderMode::OLD_MCUBES_MODE: generator = new MarchingCubes(false); break;
  case RenderMode::MTETRA_MODE: generator = new MarchingCubes(true); break;
  case RenderMode::DC_MODE: generator = new DualContouring; break;
  default: THROWS("Invalid or unsupported render mode " << mode);
  }
}


void RenderJob::run() {
  try {
    generator->run(func, bbox, resolution);
  } CATCH_WARNING;
}


void RenderJob::stop() {
  if (!generator.isNull()) generator->interrupt();
}
