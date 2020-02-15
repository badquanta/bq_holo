# PROJECT/CMakeList.txt
# - started in bq_TEMPLATE++
cmake_minimum_required (VERSION 3.13) 
project(bq_holo
	VERSION "0.0.0"
)
# Externals & Settings 
include("scripts/external_projects.cmake")
include("scripts/project_settings.cmake")
# Sub directories
add_subdirectory(src)
# Installation configuration
install(TARGETS bq_holo	 
#	LIBRARY bq_holo
	DESTINATION bq_holo
	PUBLIC_HEADER ${bq_XXXXXXXXXX_PUBLIC_INCLUDE_DIRECTORIES}
)



