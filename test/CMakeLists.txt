file(GLOB SRCS *.cpp)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(test_avl_tree ${SRCS} ../avl_tree/avl_tree.h)

target_link_libraries(test_avl_tree
        gtest
        gmock
)

include_directories("..")

install(TARGETS test_avl_tree DESTINATION bin)
