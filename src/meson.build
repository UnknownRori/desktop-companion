src_files = files(
  'companion_config.c',
  'input.c',
  'main.c',
  'render.c',
  'spritesheet.c',
  'window.c',
  'config/config.c',
)

dependencies = [raylib_dep]

executable(
  meson.project_name(),
  src_files,
  include_directories: [rstb_inc],
  dependencies: dependencies,
)
