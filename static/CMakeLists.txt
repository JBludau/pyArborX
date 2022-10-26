project(arborx_static LANGUAGES CXX)

#choose modules that should be included in the build
set(PY_STATIC_MODULES Point Box Sphere)

# get source files for selected static modules
foreach(PY_MODULE IN LISTS PY_STATIC_MODULES)
  list(APPEND PY_SRC ${PROJECT_SOURCE_DIR}/src/arborx_${PY_MODULE}.cpp)
  list(APPEND MODULE_INCLUDES "\n#include \"arborx_${PY_MODULE}.hpp\"" )
  list(APPEND MODULE_GENERATORS "\narborx::generate${PY_MODULE}Wrapper(m)")
endforeach()

string(REPLACE ";" " " MODULE_INCLUDES "${MODULE_INCLUDES}")

configure_file(arborx_static.cpp.in generated_files/arborx_static.cpp)

PYBIND11_ADD_MODULE(arborx_static generated_files/arborx_static.cpp ${PY_SRC})
target_include_directories(arborx_static PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(arborx_static PUBLIC ${PROJECT_BINARY_DIR}/generated_files)
target_link_libraries(arborx_static PUBLIC ArborX::ArborX)
set_target_properties(arborx_static PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../arborx)

