add_executable(owi_tests
    tests_main.cpp
    test_optional_constructors.cpp
    test_optional_size.cpp)
target_link_libraries(owi_tests PRIVATE owi_optional) 

    