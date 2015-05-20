project('eventbus', 'cpp')
add_global_arguments('-std=c++14', language : 'cpp')

#Dependencies

zmq_dep = find_library('zmq')

#Executables
executable('eventbus', 'main.cpp', dependencies : zmq_dep)

