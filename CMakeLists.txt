project(fpocket)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_STANDARD 99)

set(qhullSrc src/qhull/src)

set(
    qhullFiles
        ${qhullSrc}/libqhull/libqhull.h
        ${qhullSrc}/libqhull/geom.h
        ${qhullSrc}/libqhull/io.h
        ${qhullSrc}/libqhull/mem.h
        ${qhullSrc}/libqhull/merge.h
        ${qhullSrc}/libqhull/poly.h
        ${qhullSrc}/libqhull/qhull_a.h
        ${qhullSrc}/libqhull/qset.h
        ${qhullSrc}/libqhull/random.h
        ${qhullSrc}/libqhull/stat.h
        ${qhullSrc}/libqhull/user.h
        ${qhullSrc}/libqhull/global.c
        ${qhullSrc}/libqhull/stat.c
        ${qhullSrc}/libqhull/geom2.c
        ${qhullSrc}/libqhull/poly2.c
        ${qhullSrc}/libqhull/merge.c
        ${qhullSrc}/libqhull/libqhull.c
        ${qhullSrc}/libqhull/geom.c
        ${qhullSrc}/libqhull/poly.c
        ${qhullSrc}/libqhull/qset.c
        ${qhullSrc}/libqhull/mem.c
        ${qhullSrc}/libqhull/random.c
        ${qhullSrc}/libqhull/usermem.c
        ${qhullSrc}/libqhull/userprintf.c
        ${qhullSrc}/libqhull/io.c
        ${qhullSrc}/libqhull/user.c
        ${qhullSrc}/libqhull/rboxlib.c
        ${qhullSrc}/libqhull/userprintf_rbox.c
        ${qhullSrc}/qvoronoi/qvoronoi.c
        ${qhullSrc}/qconvex/qconvex.c
        ${qhullSrc}/qvoronoi/qvoronoi.h
        ${qhullSrc}/qconvex/qconvex.h
)

set(
    fpocketFiles
        headers/psorting.h
        headers/pscoring.h
        headers/utils.h
        headers/pertable.h
        headers/memhandler.h
        headers/voronoi.h
        headers/sort.h
        headers/calc.h
        headers/writepdb.h
        headers/rpdb.h
        headers/fparams.h
        headers/pocket.h
        headers/refine.h
        headers/descriptors.h
        headers/aa.h
        headers/fpocket.h
        headers/write_visu.h
        headers/fpout.h
        headers/atom.h
        headers/writepocket.h
        headers/voronoi_lst.h
        headers/asa.h
        headers/clusterlib.h
        headers/energy.h
        headers/read_mmcif.h
        headers/neighbor.h
        headers/tparams.h
        headers/topology.h
        headers/tpocket.h
        headers/dpocket.h
        headers/dparams.h
        headers/mdpocket.h
        headers/mdpbase.h
        headers/mdpout.h
        headers/mdparams.h
        src/psorting.c
        src/pscoring.c
        src/utils.c
        src/pertable.c
        src/memhandler.c
        src/voronoi.c
        src/sort.c
        src/calc.c
        src/writepdb.c
        src/rpdb.c
        src/fparams.c
        src/pocket.c
        src/refine.c
        src/descriptors.c
        src/aa.c
        src/fpocket.c
        src/write_visu.c
        src/fpout.c
        src/atom.c
        src/writepocket.c
        src/voronoi_lst.c
        src/asa.c
        src/clusterlib.c
        src/energy.c
        src/read_mmcif.c
        src/neighbor.c
        src/tparams.c
        src/topology.c
        src/tpocket.c
        src/dpocket.c
        src/dparams.c
        src/mdpocket.c
        src/mdpbase.c
        src/mdpout.c
        src/mdparams.c
)

# Set include paths for VMD
set(molfileLib "$ENV{CONAN_VMD_ROOT}/lib/vmdMolFilePlugins.lib")
set(molfileHeaders "$ENV{CONAN_VMD_ROOT}/include")

# Include getopt for Windows
if(WIN32)
  set(getoptFiles getopt_long/getopt.h getopt_long/getopt.c)
  add_library(getopt STATIC ${getoptFiles})
  set(getoptLib "getopt")
  set(getoptInclude "getopt_long")
  set(winsockLib "ws2_32")
else()
  set(getoptLib "")
  set(getoptInclude "")
  set(winsockLib "")
endif()

# Create library of object files
add_library(qhullLib STATIC ${qhullFiles})
target_include_directories(qhullLib PRIVATE ${qhullSrc})

add_library(fpocketLib STATIC ${fpocketFiles})
target_include_directories(fpocketLib PRIVATE ${molfileHeaders} ${getoptInclude})
target_link_libraries(fpocketLib ${molfileLib} ${getoptLib})

# Make qhull ?

# Make all pocket executables and link with static libraries
add_executable(pcheck src/check.c)
target_include_directories(pcheck PRIVATE ${molfileHeaders} ${getoptInclude})
target_link_libraries(pcheck fpocketLib qhullLib)

add_executable(fpocket src/fpmain.c)
target_include_directories(fpocket PRIVATE ${molfileHeaders} ${getoptInclude})
target_link_libraries(fpocket fpocketLib qhullLib)

add_executable(tpocket src/tpmain.c)
target_include_directories(tpocket PRIVATE ${molfileHeaders} ${getoptInclude})
target_link_libraries(tpocket fpocketLib qhullLib)

add_executable(dpocket src/dpmain.c)
target_include_directories(dpocket PRIVATE ${molfileHeaders} ${getoptInclude})
target_link_libraries(dpocket fpocketLib qhullLib)

add_executable(mdpocket src/mdpmain.c)
target_include_directories(mdpocket PRIVATE ${molfileHeaders} ${getoptInclude})
target_link_libraries(mdpocket fpocketLib qhullLib ${winsockLib})

