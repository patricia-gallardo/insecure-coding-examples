FROM alpine:2.7

RUN apk add --update alpine-sdk
RUN apk add curl

# How to test:
# 1) Download this file
# 2) In that same folder run: "docker build -t unlink_uclibc_test ."
# 3) Then start the container: "docker container run -it unlink_uclibc_test /bin/sh"
# 4) Inside the container run "curl -O https://raw.githubusercontent.com/patricia-gallardo/insecure-coding-examples/master/exploit/unlink/unlink_uclibc.c"
# 5) Inside the container build the file: "gcc unlink_uclibc.c"
# 6) Inside the container run the binary: "./a.out"

# Check version in docker
# gcc -dumpmachine
# x86_64-alpine-linux-uclibc
