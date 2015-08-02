
export PUB_PORT=50001
export REQ_PORT=50002

sudo docker run -p 5001:50001 -p 5002:50002 -d carlosvin/eventbus
