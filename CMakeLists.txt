cmake_minimum_required(VERSION 3.26)
project(code)

set(CMAKE_CXX_STANDARD 17)

#add_executable(code main.cpp)


add_executable(p1100 dp/p1100.cc)
add_executable(p1215 dp/p1215.cc)
add_executable(p1145 dp/p1145.cc)
add_executable(p1035 dp/p1035.cc)
add_executable(p1219 dp/p1219.cc)
add_executable(p1142 dp/p1142.cc)
add_executable(p1039 dp/p1039.cc)

add_executable(P1000 backtrack/P1000.cc)

add_executable(p1147 dfs/p1147.cc)
add_executable(p1094 dfs/p1094.cc)

add_executable(01 0812jindong/01.cc)
add_executable(findtarget interview/findtarget.cc)
add_executable(numberofisland interview/numberofisland.cc)

add_executable(treedeep interview/tree/treedeep.cc)
add_executable(bubble interview/paixue/bubble.cc)
