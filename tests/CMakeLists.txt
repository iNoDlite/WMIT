enable_testing()

### Simple model
add_test(NAME Convert_PIE2_to_PIE_simple COMMAND wmit ${PROJECT_SOURCE_DIR}/tests/pie/exjeep.pie out_exjeep.pie)
add_test(NAME Convert_PIE2_to_OBJ_simple COMMAND wmit ${PROJECT_SOURCE_DIR}/tests/pie/exjeep.pie out_exjeep.obj)
add_test(NAME Convert_PIE3_to_PIE_simple COMMAND wmit ${PROJECT_SOURCE_DIR}/tests/pie/exjeep3.pie out_exjeep3.pie)
add_test(NAME Convert_PIE3_to_OBJ_simple COMMAND wmit ${PROJECT_SOURCE_DIR}/tests/pie/exjeep3.pie out_exjeep3.obj)
# This will test that PIE3 to PIE is identical
add_test(NAME Compare_PIE3_to_PIE_simple COMMAND diff ${PROJECT_SOURCE_DIR}/tests/pie/exjeep3.pie out_exjeep3.pie)

### Test that effects flags are preserved
add_test(NAME Convert_PIE3_to_PIE_effect_flags COMMAND wmit ${PROJECT_SOURCE_DIR}/tests/pie/fxmflare3.pie out_fxmflare3.pie)
add_test(NAME Compare_PIE3_to_PIE_effect_flags COMMAND diff ${PROJECT_SOURCE_DIR}/tests/pie/fxmflare3.pie out_fxmflare3.pie)

### Test that INTERPOLATE 0 flag is preserved
add_test(NAME Convert_PIE3_to_PIE_animation_wo_interpolation
    COMMAND wmit ${PROJECT_SOURCE_DIR}/tests/pie/cybd_run_no_interpolation.pie out_cybd_run_no_interpolation.pie)
add_test(NAME Compare_PIE3_to_PIE_animation_wo_interpolation
    COMMAND diff ${PROJECT_SOURCE_DIR}/tests/pie/cybd_run_no_interpolation.pie out_cybd_run_no_interpolation.pie)
