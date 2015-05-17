import os

NAME = "eventbus"
SOURCE_DIR = 'src'
SOURCE_MAIN = Glob(SOURCE_DIR + '/main.cpp')
#SOURCES_LIB = Glob(SOURCE_DIR + '/*.c*')
#SOURCES_LIB.remove(SOURCE_MAIN[0])
LIBRARIES = ['zmq', 'pthread', 'dl']

env = Environment(
    CPPPATH=[SOURCE_DIR],
    LIBS=LIBRARIES,
    CXXFLAGS=['-std=c++11', '-g'],
    ENV=os.environ,
)


"""
Build
"""
#lib  = env.StaticLibrary('lib/' + NAME, [SOURCES_LIB])
#LIBRARIES.append(lib)
prog = env.Program('bin/'+ NAME, [SOURCE_MAIN], LIBS=LIBRARIES)

subscriber = env.Program('bin/subscriber',  Glob(SOURCE_DIR + '/subscriber.cpp') , LIBS=LIBRARIES)

publisher = env.Program('bin/publisher',  Glob(SOURCE_DIR + '/publisher.cpp') , LIBS=LIBRARIES)

"""
Install
"""
INSTALL_DIR = '/usr/local/bin'
env.Install(INSTALL_DIR, prog)
env.Alias('install', INSTALL_DIR)
