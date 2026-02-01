cmake_minimum_required(VERSION 3.27)
project(dapper_dash)

file(GLOB SOURCE_FILES
  "src/*.cpp"
  "headers/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(headers /usr/local/include /opt/homebrew/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIRS})
#  target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
#  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
