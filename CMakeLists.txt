cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main)

target_sources(main
  PRIVATE
    main.cxx
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      inc
    FILES
      inc/LinearSolution.h
      inc/TwoPointerSolution.h
      inc/PriorityQueueSolution.h
)

target_link_libraries(main
  PRIVATE
    LinearSolution
    TwoPointerSolution
    PriorityQueueSolution
)

add_library(LinearSolution)

target_sources(LinearSolution
  PRIVATE
    src/LinearSolution.cxx

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      inc
    FILES
      inc/LinearSolution.h
)

add_library(TwoPointerSolution)

target_sources(TwoPointerSolution
  PRIVATE
    src/TwoPointerSolution.cxx

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      inc
    FILES
      inc/TwoPointerSolution.h
)

add_library(PriorityQueueSolution)

target_sources(PriorityQueueSolution
  PRIVATE
    src/PriorityQueueSolution.cxx

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      inc
    FILES
      inc/PriorityQueueSolution.h
)
