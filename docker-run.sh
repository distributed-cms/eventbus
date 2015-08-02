# TODO create smarter script to accept arguments and if they are not set, then use following vars as defaults.
export PUB_PORT=50001
export REQ_PORT=50002

sudo docker run -p $PUB_PORT:5001 -p $REQ_PORT:5002 -d carlosvin/eventbus
