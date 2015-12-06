N, M = gets.split.map(&:to_i)
st = M.times.map{ gets.split.map(&:to_i) }
mem = Array.new(N + 2, 0)

st.each do |(s,t)|
  mem[s] += 1
  mem[t + 1] -= 1
end

(1..N+1).each do |i|
  mem[i] += mem[i - 1]
end

(1..N+1).each do |i|
  if mem[i] != 1 then
    mem[i] = 0
  end
  mem[i] += mem[i - 1]
end

ans = (1..M).each.select do |i|
  mem[st[i - 1].first - 1] == mem[st[i - 1].last]
end

puts ans.length
puts ans
