enable_testing()

add_executable(evtol_test evtol_test.cpp "test_util.h" )
target_link_libraries(evtol_test vehicle)
add_test(Evtol_Test evtol_test)

add_executable(charger_test charger_test.cpp "test_util.h")
target_link_libraries(charger_test charger vehicle)
add_test(Charger_Test charger_test)