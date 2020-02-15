# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(bq_holo SHARED
	Arch.hpp
	Arch.cpp
	Emitter.hpp
	Emitter.cpp
	Field.hpp
	Field.cpp
	fields.hpp
	FramesPerSecond.cpp
	FramesPerSecond.hpp
	Grid.hpp
	Grid.cpp
	IField.hpp
	IField.cpp
	IGram.hpp
	IGram.cpp
	IProtocol.hpp
	IProtocol.cpp
	Program.cpp
	Program.hpp 
	Protocol.hpp
	Protocol.cpp		
	Sprite.cpp 
	Sprite.hpp
	types.hpp	
)
add_dependencies(bq_holo BQ_SDL2_PROJ)
add_dependencies(bq_holo GLM_PROJ)
target_link_libraries(bq_holo bq_sdl2 )
# We need this directory, and users of our library will need it too
#target_include_directories(bqpd PUBLIC )

# This depends on (header only) boost
#target_link_libraries(modern_library PRIVATE Boost::boost)
include_directories(${DOCTEST_INCLUDE_DIR} ${BQ_UTILS_INCLUDE_DIRS} ${BQ_SDL2_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})

foreach(X #################################
	Arch
	Emitter
	Field	
	FramesPerSecond
	Grid
	IField
	IGram
	IProtocol
	Program
	Protocol
	Sprite	
)#########################################
	message(STATUS "making ${X}_test")
	add_executable("${X}_test" "${X}_test.cpp")
	target_link_libraries("${X}_test" bq_holo bq_sdl2)
	add_dependencies("${X}_test" BQ_SDL2_PROJ doctest GLM_PROJ)
	add_test("${X}_test" "${X}_test")
endforeach()
