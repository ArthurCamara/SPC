#!/usr/bin/env ruby


def main()
  inp = $stdin.read
  ammount = inp.to_i
  case ammount
  when 0..10
    topay = 7
  when 11..30
    topay = 7+ (ammount-10)
  when 31..100
    topay = 27+((ammount-30)*2)
  else
    topay = 167 + ((ammount-100)*5)
  end
  print topay
end

main()
