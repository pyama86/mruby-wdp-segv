# mruby-wdp-segv   [![Build Status](https://travis-ci.org/pyama86/mruby-wdp-segv.svg?branch=master)](https://travis-ci.org/pyama86/mruby-wdp-segv)
WDPSegV class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'pyama86/mruby-wdp-segv'
end
```
## example
```ruby
p WDPSegV.hi
#=> "hi!!"
t = WDPSegV.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
