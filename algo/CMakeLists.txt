add_executable(random-generator misc/generate_input.cpp)
add_custom_command(
  OUTPUT output.require
  COMMAND random-generator
  COMMENT "Generating random int."
  VERBATIM
)
add_custom_target(
  # target requires dependency, dependency runs command,
  # command has output binary name inside..
  OutputInt ALL
  DEPENDS output.require
)
