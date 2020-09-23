#!/bin/sh
set -ex

if [ ! -d "${HOME}/${CCOMPILER}-boost_${BOOST_VERSION}/include" ]; then
    # hardcoded download url because filename
    wget -O boost_${BOOST_VERSION}.tar.bz2 https://dl.bintray.com/boostorg/release/1.74.0/source/boost_1_74_0.tar.bz2
    tar jxf boost_${BOOST_VERSION}.tar.bz2
    cd boost_${BOOST_VERSION}
    ./bootstrap.sh --with-toolset=$TOOLSET --prefix=${HOME}/${CCOMPILER}-boost_${BOOST_VERSION}
    ./b2 --stagedir=. -j4 --layout=tagged variant=debug,release link=shared threading=multi address-model=64 cxxflags='-std=c++11' install >boost-build.log 2>&1
    cd ..
    rm -rf boost_${BOOST_VERSION}
    rm -rf boost_${BOOST_VERSION}.tar.bz2
fi
