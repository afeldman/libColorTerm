#!/usr/bin/env python
# encoding: utf-8
# waf script for builduing project
# author: Anton Feldmann
# Copyright 2014 anton.feldmann@gmail.com
# license: MIT

import os, sys
from waflib import Build, TaskGen

name = 'libColorTerm'

major  = 0
minor  = 1
bugfix = 0

name_version = '%s-%d.%d.%d' % (name, major, minor, bugfix)

application = name
version     = '%d.%d.%d' % (major, minor, bugfix)

top = '.'
out = 'build'

def options(opt):
    opt.load('compiler_cxx compiler_c')

    #Add configuration options in python
    coloropt = opt.add_option_group ("%s Options" % name.upper())

    coloropt.add_option('--shared',
                      action='store_true',
                      default=False,
                      help='build all libs as shared libs')
    coloropt.add_option('--clang',
                      action='store_true',
                      default=False,
                      help='build with clang')
    colordebugopt = opt.add_option_group ("%s_Debugging Options" % name.upper())

    colordebugopt.add_option('--debug',
                            action='store_true',
                            default=False,
                            help='compile the project in debug mode')

def configure(conf):
    env=conf.env
    opt=conf.options

    from waflib import Options

    opts = Options.options

    if not os.name == 'nt':
        if(opts.clang):
            env.CXX = 'clang++'
            env.CC = 'clang'


def build(bld):
    # libshm headerfile install
    bld.install_files('${PREFIX}/include/libColorTerm/', bld.path.ant_glob(['include/libColorTerm/*.hpp'], remove=False))

    from waflib import Options
# process libcolorterm.pc.in -> libcolorterm.pc - by default it use the task "env" attribute
    pcf = bld(
        features = 'subst',
        source = '%s.pc.in' % name,
        target = '%s.pc' % name,
        install_path = '${PREFIX}/lib/pkgconfig/'
        )

    pcf.env.table.update(
        {'LIBS':'',
         'VERSION': version,
         'NAME': name,
         'PREFIX': '%s' % Options.options.prefix,
         'INCLUDEDIR': 'include/%s' % name}
        )
