
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
#include <iostream>

namespace LAMMPS_NS {

class FixElectrodeConpNevery : public FixElectrodeConp {

 public:
  FixElectrodeConpNevery(class LAMMPS *, int, char **);
  ~FixElectrodeConpNevery() ;
  int everynum;
  virtual void pre_force(int) override;
};

}    // namespace LAMMPS_NS

#endif
#endif

