file(REMOVE_RECURSE
  "../scripts/base/bif"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/generate_outputs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
