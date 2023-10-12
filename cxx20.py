#! /usr/bin/env python
# encoding: utf-8

def configure(conf):
    def get_param(varname,default):
        return getattr(Options.options,varname,'')or default


    #cxx20_fragment="#include <memory>\nint main() { std::make_unique<int>(); enum class color {red, blue}; }"

    flags=['-std=c++20','-std=c++1y']
    if conf.options.cxx20_flag:
        flags=[conf.options.cxx20_flag]
    found_cxx14=False
    for flag in flags:
        try:
            conf.check_cxx(msg="Checking C++ 20 flag " + flag,
                           fragment=cxx20_fragment,
                           cxxflags=flag, linkflags=flag, uselib_store='cxx20')
        except conf.errors.ConfigurationError:
            continue
        else:
            found_cxx14=True
            break
    if not found_cxx14:
        conf.fatal('Could not find C++ 20 flag, try with the C++ 14 flag')

def options(opt):
    cxx14=opt.add_option_group('C++ 20 Options')
    cxx14.add_option('--cxx20-flag',
                     help='Flag to enable C++ 20')
