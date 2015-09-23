project(CppUnitLite2)
cmake_minimum_required(VERSION 2.8)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(SRC
    src/TestResult.cpp
    src/ExceptionHandler.cpp
    src/Test.cpp
    src/TestRegistry.cpp
    src/TestResultStdErr.cpp
    src/Failure.cpp
    src/TestException.cpp
    src/Linux/SignalHandler.cpp
)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(SRC
        ${SRC}
        src/Linux/SignalHandler.cpp
    )
else()
    set(SRC
        ${SRC}
        src/Win32/SignalHandler.cpp
    )
endif()

add_library(CppUnitLite2 STATIC ${SRC})
