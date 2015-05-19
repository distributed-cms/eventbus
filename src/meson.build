project('eventbus', 'cpp')
add_global_arguments('-std=c++14', language : 'cpp')


#zmq_dep = dependency('zmq')
zmq_dep = find_library('zmq')

executable('eventbus', 'main.cpp', dependencies : zmq_dep)

