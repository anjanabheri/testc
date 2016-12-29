#!/usr/bin/perl

# **** License ****
# Copyright (c) 2014 by Brocade Communications Systems, Inc.
# All rights reserved.
# **** End License

use strict;
use warnings;

my $one = shift;
my $two = shift;

my $self = {
    test1 => shift,
    test2 => shift,
};

print "one: $one, two: $two \n";
print "class test1: $self->{test1}, test2: $self->{test2}\n";
