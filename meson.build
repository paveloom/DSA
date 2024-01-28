project(
  'DSA',
  'cpp',
  default_options: [
    'buildtype=debug',
    'cpp_std=c++2a',
  ],
)

cpp_flags = []
cpp_link_flags = ['-stdlib=libc++']
override_options = []

if get_option('buildtype') == 'release'
  override_options += [
    # Use the LLD linker for LTO. In Nixpkgs, the LLVM gold plugin is disabled
    # for LLVM 16 because of https://github.com/llvm/llvm-project/issues/61350
    'b_lto=true',
    'strip=true',
    'warning_level=0',
  ]
elif get_option('buildtype') == 'debug'
  cpp_flags += [
    '-fdebug-macro',
    '-ferror-limit=500',
    '-g3',
    '-gdwarf-5',
    '-Wconversion',
    '-Wdouble-promotion',
    '-Wno-sign-conversion',
    '-Wno-unused-parameter',
    '-Wshadow',
  ]
  override_options += [
    'warning_level=3',
  ]
endif

compiler = meson.get_compiler('cpp')
add_project_arguments(compiler.get_supported_arguments(cpp_flags), language: 'cpp')
add_project_link_arguments(
  compiler.get_supported_link_arguments(cpp_link_flags),
  language: 'cpp',
)

sources = [
  'src/CtCI, 6th Edition/1.5 - One Away.cpp',
  'src/CtCI, 6th Edition/1.6 - String Compression.cpp',
  'src/CtCI, 6th Edition/1.7 - Rotate Matrix.cpp',
  'src/main.cpp',
]

include_dir = include_directories('include')

executable = executable(
  'main',
  sources: sources,
  override_options: override_options,
  include_directories: include_dir,
)

if get_option('buildtype') == 'debug'
  find_program('clang-check')
  find_program('cppcheck')
  find_program('cpplint')
  find_program('clang-tidy')
  custom_target(
    'lint',
    depends: executable,
    output: 'lint',
    command: 'lint.bash',
    env: {
      'MESON_CURRENT_BUILD_DIR': meson.current_build_dir(),
      'MESON_PROJECT_SOURCE_ROOT': meson.project_source_root(),
    },
    console: true,
    build_always_stale: true,
  )
endif
