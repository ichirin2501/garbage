require 'pp'

N, M = gets.chomp('').split(" ").map{ |x| x.to_i }

S = Array.new(M)
T = Array.new(M)
mem = Array.new(N + 10, 0)
h = Hash.new()
M.times { |i|
  s,t = gets.chomp('').split(" ").map { |x| x.to_i }
  S[i] = s
  T[i] = t
  mem[s] += 1;
  mem[t + 1] -= 1;
  h[t] ||= []
  h[t].push(i)
}

for i in 1..N+1 do
  mem[i] += mem[i - 1]
end

s = 1
f = 1
ans = Array.new;

for i in 1..N+1 do
  if mem[i] > 1 then
    if f == 0 then
      f = 1
      s = i
    end
    if h.has_key?(i) then
     h[i].each { |idx|
        if s <= S[idx] then
          ans.push(idx)
        end
      }
    end
  else 
    f = 0
  end
end

ans.sort!
p ans.length
ans.each { |idx|
  p idx + 1
}
