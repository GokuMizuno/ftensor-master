def options(opt):
    opt.load('compiler_cxx gnu_dirs cxx14')

    cxx_flags=opt.add_option_group('C++ Flags')
    cxx_flags.add_option('--optimize',
                         help='Compiler option to maximize speed (e.g. -Ofast)')


def configure(conf):
    configure_variant(conf);

def configure_variant(conf):
    conf.load('compiler_cxx gnu_dirs cxx14')

    # Optimization flags
    optimize_msg="Checking for optimization flag "
    optimize_fragment="int main() {}\n"
    optimize_flags=['-Ofast','-O3','-O2','-O']
    if conf.options.optimize:
        optimize_flags=[conf.options.optimize]
    for flag in optimize_flags:
        try:
            conf.check_cxx(msg=optimize_msg+flag, fragment=optimize_fragment,
                           cxxflags=flag, uselib_store='optimize')
        except conf.errors.ConfigurationError:
            continue
        else:
            found_optimize=True
            break

def build(bld):
    default_flags=['-Wall', '-Wextra', '-Wconversion']

    start_dir = bld.path.find_dir('src')
    bld.install_files(bld.env.INCLUDEDIR, start_dir.ant_glob('**'),
                      cwd=start_dir, relative_trick=True)

    conformance_files=bld.path.ant_glob('tests/conformance/test_*.cpp') \
        + bld.path.ant_glob('tests/conformance/T*/*.cpp') \
        + bld.path.ant_glob('tests/conformance/Levi_Civita/*.cpp')

    bld.stlib(source=conformance_files,
        cxxflags=default_flags + ['-DFTENSOR_DEBUG','-g'],
        target='conformance_tests',
        use=['cxx14'],
        install_path=None
        )

    
    bld.program(
        source=['tests/conformance/main.cpp'],
        cxxflags=default_flags + ['-DFTENSOR_DEBUG','-g'],
        target='conformance',
        use=['cxx14','conformance_tests'],
        install_path=None
        )

    bld.program(
        source=['tests/conformance/main_for_gcc.cpp'],
        cxxflags=default_flags + ['-DFTENSOR_DEBUG','-g'],
        target='conformance_for_gcc',
        use=['cxx14','conformance_tests'],
        install_path=None
        )

    # bld.program(
    #     source=[''],
    #     use=['optimize'],
    #     cxxflags=default_flags,
    #     target='speed',
    #     use=['optimize']
    #     install_path=None
    #     )

