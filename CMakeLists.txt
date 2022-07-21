cmake_minimum_required(VERSION 3.15)

project(Medical-store-management LANGUAGES C CXX)

# Setting Release as the default configuration for project.
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BIN_DIR}/pkg)

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/Admin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Password.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Supplier.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Customer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/New_Inventory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Purchased_Data.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Validate_Input.cpp )

set(headers
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Admin.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Password.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Validate_Input.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Customer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Purchased_Data.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/New_Inventory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Supplier.h)

add_executable(medical ${sources} ${headers})
include(GNUInstallDirs)
install(TARGETS medical
        RUNTIME DESTINATION ${CMAKE_BUILD_TYPE}/bin)
