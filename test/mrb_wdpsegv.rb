##
## WDPSegV Test
##

assert("WDPSegV#hello") do
  t = WDPSegV.new "hello"
  assert_equal("hello", t.hello)
end

assert("WDPSegV#bye") do
  t = WDPSegV.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("WDPSegV.hi") do
  assert_equal("hi!!", WDPSegV.hi)
end
