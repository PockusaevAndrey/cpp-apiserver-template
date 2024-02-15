FROM ubuntu:latest
LABEL authors="{{cookiecutter.author}}"

RUN apt update &&  \
    apt install -y make cmake gcc g++ build-essential gdb git meson libpq-dev

ARG UID=1000
RUN useradd -m -u ${UID} -s /bin/bash builder
USER builder