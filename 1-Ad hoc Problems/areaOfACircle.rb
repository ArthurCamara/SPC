#!/usr/bin/env ruby
include Math

def main()
  inp = $stdin.read.to_f
  printf("%.4f", (inp*inp)*Math::PI)

end


main()
