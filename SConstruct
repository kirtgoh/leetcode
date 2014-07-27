# Top level SConstruct for leetcode

import os

# Colored output of compliation
import sys

colors = {}
colors['cyan']   = '\033[96m'
colors['purple'] = '\033[95m'
colors['blue']   = '\033[94m'
colors['green']  = '\033[92m'
colors['yellow'] = '\033[93m'
colors['red']    = '\033[91m'
colors['end']    = '\033[0m'

# If the output is not a terminal, remove the colors
if not sys.stdout.isatty():
    for key, value in colors.iteritems():
        colors[key] = ''

compile_source_message = '%sCompiling %s:: %s$SOURCE ==> $TARGET%s' % \
    (colors['blue'], colors['purple'], colors['yellow'], colors['end'])

create_header_message = '%sCreating %s==> %s$TARGET%s' % \
    (colors['green'], colors['purple'], colors['yellow'], colors['end'])

compile_shared_source_message = '%sCompiling shared %s==> %s$SOURCE%s' % \
    (colors['cyan'], colors['purple'], colors['yellow'], colors['end'])

link_program_message = '%sLinking Program %s==> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['yellow'], colors['end'])

link_library_message = '%sLinking Static Library %s==> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['yellow'], colors['end'])

ranlib_library_message = '%sRanlib Library %s==> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['yellow'], colors['end'])

link_shared_library_message = '%sLinking Shared Library %s==> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['yellow'], colors['end'])

pretty_printing = ARGUMENTS.get('pretty', 1)

# Base Environment used to compile leetcode (leetcode and supterstl)
if int(pretty_printing) :
    base_env = Environment(
            CXXCOMSTR = compile_source_message,
            CREATECOMSTR = create_header_message,
            CCCOMSTR = compile_source_message,
            SHCCCOMSTR = compile_shared_source_message,
            SHCXXCOMSTR = compile_shared_source_message,
            ARCOMSTR = link_library_message,
            RANLIBCOMSTR = ranlib_library_message,
            SHLINKCOMSTR = link_shared_library_message,
            LINKCOMSTR = link_program_message,
            )
else:
    base_env = Environment()

# Setup the environment
env = base_env.Clone()
env.Decider('MD5-timestamp')

env['CPPPATH'] = []
env['CPPPATH'].append(os.getcwd())
# Add gtest directory in CPPPATH
env['CPPPATH'].append(os.getcwd() + "/gtest/include")
env['CPPPATH'].append(os.getcwd() + "/gtest")
env['CPPPATH'].append(os.getcwd() + "/solutions")
env['CPPPATH'].append(os.getcwd() + "/tests")

env.Append(CXXFLAGS = ' -O0 -g')
Export('env')

# List of subdirectories where we have source code
dirs = ['solutions','gtest','tests']

# 1. Configure superstl
# stl_env = base_env.Clone()
# stl_env.Decider('MD5-timestamp')
# Export('stl_env')
#
# Compile superstl
# curr_dir = os.getcwd()
# stl_dir = "%s/superstl" % curr_dir
# stl_compile_script = "%s/SConscript" % stl_dir
# stl_lib = SConscript(stl_compile_script)

# Now call the SConscript in all subdirectories to build object files
# , lib/gtest and tests folders are included
tobjs = []
for dir in dirs:
    o = SConscript('%s/SConscript' % dir)
    if type(o) == list:
        tobjs.append(o[0])
    else:
        tobjs.append(o)

src_files = Glob('*.cpp')
objs = env.Object(src_files)

env.Program('leetcode', objs + tobjs, LIBS='pthread');
