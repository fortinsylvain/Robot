# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(robotXtave C CXX)   # C++ is needed for RadioHead

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)  # or 20, depending on your needs
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add directories to include path
include_directories(
    ${CMAKE_SOURCE_DIR}/Libraries/RadioHead  # RadioHead headers
)

# Define platform-specific macros for RadioHead
add_definitions(-DRH_PLATFORM=RH_PLATFORM_ARDUINO)
add_definitions(-DARDUINO_ARCH_RP2040)  # Define platform for Pico

# rest of your project
add_executable(${PROJECT_NAME}
    Libraries/RadioHead/RHCRC.cpp
    Libraries/RadioHead/RH_ASK.cpp  # RH_ASK or the appropriate RadioHead driver
    Libraries/RadioHead/RHGenericDriver.cpp
    main.cpp
    genpwm.c
    motor.c
    sonar.c
)

# Add pico_stdlib library which aggregates commonly used features(gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME}
   pico_stdlib       # Commonly used Pico functions
   hardware_pwm      # PWM hardware library
)


# Enable C++11 (or higher) as RadioHead requires C++
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11) # Use cxx_std_17 for consistency

# Enable mixed C and C++ language support
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

