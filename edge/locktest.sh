#!/bin/bash
# Initial script to quickly test locking.
# Replaced by userspace. c

echo -n ONE > /dev/edge &
echo -n TWO > /dev/edge &
echo -n THREE > /dev/edge & 
echo -n FOUR > /dev/edge & 
