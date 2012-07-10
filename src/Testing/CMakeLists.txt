# Find tests generated in the binary directory
message("GENERATED TESTS DIR ${CMAKE_CURRENT_BINARY_DIR}")
message("GENERATED TESTS ${GENERATED_FILTER_LIST}")

# To add a new file, just add it to this list.  Any GoogleTests inside will be automatically
# added to ctest.
set ( CYCAMORE_TEST_CORE 
  ${CMAKE_CURRENT_SOURCE_DIR}/ConverterModelTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/FacilityModelTests.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/InstModelTests.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/MarketModelTests.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/ModelTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/RegionModelTests.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/StubModelTests.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/StubCommModelTests.cpp 
  PARENT_SCOPE)

# Add all the tests by parsing the source code
# This macro searches for GoogleTest macros and adds them as tests automatically
macro(ADD_GOOGLE_TESTS executable)
  # Add the generated tests
  set ( AllTestsHits ${GENERATED_TEST_LIST} )

  foreach ( source ${ARGN} )
    file(READ "${source}" contents)

    # Find all test lists
    string(REGEX MATCHALL "TEST_?[FP]?\\(([A-Za-z_0-9 ,_]+)\\)" AllTests ${contents})

    # Convert the C++ code into a short test name
    foreach(hit ${AllTests})
      string(REGEX REPLACE ".*\\(( *[A-Za-z_0-9]+)[, ]*([A-Za-z_0-9]+) *\\).*" "\\1.\\2" test_name ${hit})
      set ( AllTestsHits ${AllTestsHits} ${test_name} )
    endforeach()
  endforeach()

  list ( SORT AllTestsHits )
  # Add all the remaining tests to CTest's test list
  foreach(hit ${AllTestsHits})
    add_test(${hit} ${executable} --gtest_filter=${hit})
  endforeach()
endmacro()


