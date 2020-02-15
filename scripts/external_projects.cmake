include(ExternalProject)
find_package(Git REQUIRED)
ExternalProject_Add(
    doctest
    PREFIX ${CMAKE_BINARY_DIR}/lib/doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)
ExternalProject_Get_Property(doctest source_dir)
set(DOCTEST_INCLUDE_DIR ${source_dir} CACHE INTERNAL "Path to include folder for doctest")


#######################################################################
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
ExternalProject_Add(
    bq_utils
    PREFIX ${CMAKE_BINARY_DIR}/prefix/bq_utils
    GIT_REPOSITORY /home/badquanta/bq_utils++ #https://github.com/badquanta/bq_utils.git
    TIMEOUT 10
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    #CONFIGURE_COMMAND ""
    #BUILD_COMMAND ""
    #INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
ExternalProject_Get_Property(bq_utils source_dir)
set(BQ_UTILS_INCLUDE_DIRS ${source_dir}/src CACHE INTERNAL "Path to include folder for bq_utils")

#######################################################################
 
ExternalProject_Add(
    BQ_SDL2_PROJ
    PREFIX ${CMAKE_BINARY_DIR}/prefix/bq_sdl2
    GIT_REPOSITORY /home/badquanta/bq_sdl2++ #https://github.com/badquanta/BQ_SDL2_PROJ.git
    TIMEOUT 10
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    #CONFIGURE_COMMAND ""
    #BUILD_COMMAND ""
    #INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_UPDATE ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    LOG_TEST ON
    LOG_INSTALL ON
    TEST_BEFORE_INSTALL OFF
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
ExternalProject_Get_Property(BQ_SDL2_PROJ source_dir)
set(BQ_SDL2_INCLUDE_DIRS ${source_dir}/src/)
link_directories(${CMAKE_BINARY_DIR}/external/bq_sdl2)


#######################################################################
 
ExternalProject_Add(
    GLM_PROJ
    #PREFIX ${CMAKE_BINARY_DIR}/prefix/glm
    GIT_REPOSITORY https://github.com/g-truc/glm #https://github.com/badquanta/BQ_SDL2_PROJ.git
    TIMEOUT 10
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_UPDATE ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    LOG_TEST ON
    LOG_INSTALL ON
    TEST_BEFORE_INSTALL OFF
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
ExternalProject_Get_Property(GLM_PROJ source_dir)
set(GLM_INCLUDE_DIRS ${source_dir})
link_directories(${CMAKE_BINARY_DIR}/external/glm)