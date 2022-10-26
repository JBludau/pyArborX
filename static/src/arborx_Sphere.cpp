#ifndef PYARBORX_SPHERE_CPP
#define PYARBORX_SPHERE_CPP

#include "arborx_Sphere.hpp"

#include "arborx_Point.hpp"

namespace py = pybind11;

namespace arborx
{
namespace helper
{
std::string pyPrintSphere(ArborX::Sphere const &s)
{
  return "<arborx::Sphere with centroid \n" + pyPrintPoint(s.centroid()) +
         "and radius \n" + std::to_string(s.radius()) + ">";
}
} // namespace helper

void generateSphereWrapper(py::module &m)
{

  py::class_<ArborX::Sphere>(m, "Sphere")
      .def(py::init<>())
      .def(py::init<ArborX::Point, double>(), py::arg("centroid"),
           py::arg("radius"))

      .def("centroid",
           py::overload_cast<>(&ArborX::Sphere::centroid, py::const_),
           py::return_value_policy::reference)
      .def("centroid", py::overload_cast<>(&ArborX::Sphere::centroid),
           py::return_value_policy::reference)
      .def("radius", py::overload_cast<>(&ArborX::Sphere::radius, py::const_),
           py::return_value_policy::move)

      .def("__repr__", py::overload_cast<ArborX::Sphere const &>(
                           &arborx::helper::pyPrintSphere));
}
} // namespace arborx

#endif
