#!/bin/sh
#Script to launch processes

./user -port=$3 -mongo-host=$6 &
exec ./registration-client -process=user -service=sock-shop-user -register=false -server=$1 -port=$2 -hostname=$4 -register-port=$5
