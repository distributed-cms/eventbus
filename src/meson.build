project('eventbus', 'cpp')
add_global_arguments('-std=c++14', language : 'cpp')

#Dependencies

zmq_dep = find_library('zmq')

#Executables
executable('eventbus', 'main.cpp', dependencies : zmq_dep)

#Test
test_subscriber = executable('test_subscriber', 'test/test_subscriber.cpp', dependencies : zmq_dep)
#test('test subscriber', test_subscriber)

test_publisher = executable('test_publisher', 'test/test_publisher.cpp', dependencies : zmq_dep)
#test('test publisher', test_publisher)
