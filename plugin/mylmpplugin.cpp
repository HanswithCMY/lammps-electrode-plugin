// SPDX-License-Identifier: LGPL-3.0-or-later
/**
 * See https://docs.lammps.org/Developer_plugins.html
 */
#include "lammpsplugin.h"
#include "version.h"

#include "fix_electrode_conp_nevery.h"

using namespace LAMMPS_NS;


static Fix *FixElectrodeConpNevery_creator(LAMMPS *lmp, int narg, char **arg) {
  return new FixElectrodeConpNevery(lmp, narg, arg);
}

extern "C" void lammpsplugin_init(void *lmp, void *handle, void *regfunc) 
{
  lammpsplugin_t plugin;
  lammpsplugin_regfunc register_plugin = (lammpsplugin_regfunc) regfunc;

  plugin.version = LAMMPS_VERSION;
  plugin.author = "None";

  plugin.style = "fix";
  plugin.name = "electrode/conp/nevery";
  plugin.info = "fix electrode/conp/nevery";
  plugin.creator.v1 = (lammpsplugin_factory1 *) &FixElectrodeConpNevery_creator;
  (*register_plugin)(&plugin, lmp);
}
