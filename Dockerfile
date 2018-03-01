##############################################################################
## Build image with (lastly built with ubuntu:18.04):
##   docker build -t runino:v1 .
##
## Run with:
##   docker run -v `pwd`:/data -it --rm runino:v1 bash
#############################################################################

FROM ubuntu:latest

RUN apt update && \
  apt install -y --no-install-recommends perl g++ arduino-mk && \
  rm -rf /var/lib/apt/lists/*

RUN cpan Config::Properties Device::SerialPort File::Which File::HomeDir

COPY . /tmp/runino
WORKDIR /tmp/runino

RUN make install

WORKDIR /data
