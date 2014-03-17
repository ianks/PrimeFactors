#!/usr/bin/ruby

puts "Enter your integer."
num = gets.chomp
print "You hexvalue is: 0x"
puts Integer(num).to_s(16).upcase + "_cppui1024"
