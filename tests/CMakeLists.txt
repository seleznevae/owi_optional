add_executable(owi_tests
    tests_main.cpp
    test_optional_comparisons.cpp
    test_optional_constructors.cpp
    test_optional_size.cpp
    test_traits.cpp)
target_link_libraries(owi_tests PRIVATE owi_optional) 

    