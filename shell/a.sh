#!/bin/bash
function abc()
{
    local a1="fick"
    a=100
    
    echo $a1
    echo $a
}

abc

echo $a
echo $a1
source ./n.sh
