#!/bin/bash

##### RUN ONLY MANDATORY TESTS
if [ $1 == 'm' ] || [ $1 == 'a' ]
then
    # Run Buffer size 1
    export BUFFER=1
    make
    # Run Buffer size 42
    export BUFFER=100
    make
    # Run Buffer size 100
    export BUFFER=100
    make
    # Run Buffer size 10M
    export BUFFER=10000000
    make
fi

##### RUN ONLY BONUS TESTS
if [ $1 == 'b' ] || [ $1 == 'a' ]
then
    # Run Buffer size 1
    export BUFFER=1
    make bonus
    # Run Buffer size 42
    export BUFFER=100
    make bonus
    # Run Buffer size 100
    export BUFFER=100
    make bonus
    # Run Buffer size 10M
    export BUFFER=10000000
    make bonus
fi
