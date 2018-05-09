file(REMOVE_RECURSE
  "../scripts/base/bif"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/generate_outputs_stage1.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
