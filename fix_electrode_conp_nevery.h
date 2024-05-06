/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   LAMMPS development team: developers@lammps.org

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing authors: Ludwig Ahrens-Iwers (TUHH), Shern Tee (UQ), Robert Meißner (TUHH)
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

// clang-format off
FixStyle(electrode/conp/nevery, FixElectrodeConpNevery);
// clang-format on

#else

#ifndef LMP_FIX_ELECTRODE_CONP_NEVERY_H
#define LMP_FIX_ELECTRODE_CONP_NEVERY_H

#include "fix.h"

#include "fix_electrode_conp.h"

#include <map>
#include <unordered_map>


namespace LAMMPS_NS {

class FixElectrodeConpNevery : public FixElectrodeConp {

 public:
  FixElectrodeConpNevery(class LAMMPS *, int, char **);
  ~FixElectrodeConpNevery() override;
  int everynum;
  virtual void pre_force(int) override
};

}    // namespace LAMMPS_NS

#endif
#endif
