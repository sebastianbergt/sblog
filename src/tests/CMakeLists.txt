add_executable(sblog_test sblog_test.cpp)

target_link_libraries(sblog_test PRIVATE sblog Catch2::Catch2WithMain trompeloeil::trompeloeil)

add_test(NAME sblog_test COMMAND sblog_test)
