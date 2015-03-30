#!/usr/bin/env ruby

def main
  inp = $stdin.read
  teams = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P']
  input = inp.split("\n")
  for i in 0...input.length
    input[i] = input[i].split(" ").map {|a| a.to_i}
  end
  for i in (0...input.length)
    game = teams.shift(2)
    if input[i][0]>input[i][1]
      teams.push(game[0])
    else
      teams.push(game[1])
    end
  end
  print teams.shift.to_s + "\n"
end
main()
