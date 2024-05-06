#include "fix_electrode_conp.h"
#include "fix_electrode_conp_nevery.h"

#include "atom.h"
#include "citeme.h"
#include "comm.h"
#include "domain.h"
#include "electrode_math.h"
#include "electrode_matrix.h"
#include "electrode_vector.h"
#include "error.h"
#include "force.h"
#include "group.h"
#include "input.h"
#include "math_const.h"
#include "memory.h"
#include "modify.h"
#include "neigh_list.h"
#include "neigh_request.h"
#include "neighbor.h"
#include "pair.h"
#include "text_file_reader.h"
#include "variable.h"

#include "update.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <exception>
#include <memory>
#include <utility>

using namespace LAMMPS_NS;
using namespace MathConst;
static constexpr double SMALL = 1e-16;

extern "C" {
void dgetrf_(const int *M, const int *N, double *A, const int *lda, int *ipiv, int *info);
void dgetri_(const int *N, double *A, const int *lda, const int *ipiv, double *work,
             const int *lwork, int *info);
}

static const char cite_fix_electrode[] =
    "fix electrode command:\n\n"
    "@article{Ahrens2022\n"
    "author = {Ahrens-Iwers, Ludwig J.V. and Janssen, Mahijs and Tee, Shern R. and Mei{\\ss}ner, "
    "Robert H.},\n"
    "doi = {10.1063/5.0099239},\n"
    "title = {{ELECTRODE: An electrochemistry package for LAMMPS}},\n"
    "journal = {The Journal of Chemical Physics},\n"
    "year = {2022}\n"
    "volume = {157},\n"
    "pages = {084801},\n"
    "}\n";

//     0        1      2              3    4
//     // fix fxupdate group1 electrode/conp pot1 eta couple group2 pot2

FixElectrodeConpNevery::FixElectrodeConpNevery(LAMMPS *lmp, int narg, char **arg) :FixElectrodeConp(lmp, narg, arg)
{
   everynum = 1;
   int iarg = 5;
   while (iarg < narg) {
    if ((strcmp(arg[iarg], "nevery") == 0)) {
      if (iarg + 2 > narg) error->all(FLERR, "Need one arguments after nevery keyword");
      everynum = utils::numeric(FLERR, arg[iarg+1], false, lmp);
      if (everynum <= 0) error->all(FLERR, "nevery must be a positive integer");
      iarg += 1;
    } else {
      error->all(FLERR, "Invalid keyword in fix electrode/conp/nevery command");
    }
    iarg++;
  } 
}
FixElectrodeConpNevery::~FixElectrodeConpNevery() {}
 void FixElectrodeConpNevery::pre_force(int  vflag )
{
  if(update->ntimestep % everynum == 0) {
  FixElectrodeConp::pre_force(vflag);
  }
} 
