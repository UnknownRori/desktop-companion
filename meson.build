project('rori-companion', 'c')

rstb_inc = include_directories('./external/rstb')

raylib_proj = subproject('raylib', default_options: ['default_library=static'])
raylib_dep = raylib_proj.get_variable('raylib_dep')

rconfig_proj = subproject('rconfig', default_options: ['default_library=static'])
rconfig_dep = rconfig_proj.get_variable('rconfig_dep')

subdir('src')
