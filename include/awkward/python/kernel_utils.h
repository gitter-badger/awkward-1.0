// BSD 3-Clause License; see https://github.com/scikit-hep/awkward-1.0/blob/master/LICENSE

#ifndef AWKWARD_KERNEL_UTILS_H
#define AWKWARD_KERNEL_UTILS_H

#include <string>

#include <pybind11/pybind11.h>

#include "awkward/kernel.h"

namespace py = pybind11;
namespace ak = awkward;

py::enum_<kernel::Lib>
make_Libenum(const py::handle& m, const std::string& name);


#endif //AWKWARD_KERNEL_UTILS_H
