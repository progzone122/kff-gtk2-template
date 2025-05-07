project('{APP_NAME}', 'cpp', version: '{VERSION}', default_options: ['cpp_std=c++17'], meson_version: '>=1.1')

# Define dependencies we want
gtk_dep = dependency('gtk+-2.0')

###
# Project definition
###
sources = files(
    './src/main.cpp'
)

include_dirs = include_directories(
  './src/include/'
)

executable('{APP_NAME}', sources, include_directories: include_dirs, dependencies: [gtk_dep], cpp_args: '-static-libstdc++', link_args: '-static-libstdc++')
