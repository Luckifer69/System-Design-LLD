cmake_minimum_required(VERSION 3.10)
project(BloggingPlatform CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    main.cpp
    models/Comment.cpp
    models/User.cpp
    models/Post.cpp
    services/BloggingPlatform.cpp
)

add_executable(blogging_platform ${SOURCES})
