# CMake generated Testfile for 
# Source directory: C:/Users/dimik/CLionProjects/blatt-7-aufgabe-1-create-a-new-team
# Build directory: C:/Users/dimik/CLionProjects/blatt-7-aufgabe-1-create-a-new-team/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_avl_tree "test/test_avl_tree" "--gtest_output=xml:report.xml")
subdirs("googletest-build")
subdirs("test")
