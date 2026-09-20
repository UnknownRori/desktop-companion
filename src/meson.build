src_files = files(
  'main.c',
  'spritesheet.c',
  'window.c',
)

dependencies = [raylib_dep]

executable(
  meson.project_name(),
  src_files,
  include_directories: [rstb_inc],
  dependencies: dependencies,
)
