$m = 10 ** 9 + 7
n = gets.to_i
dists = gets.split.map(&:to_i)
groups = Array.new(n, 0)

dists.each do |d|
  groups[d] += 1
end

if dists[0] != 0 || groups[0] != 1 then
  puts 0
  exit
end

zero = (1 .. dists.max).each.select do |i|
  groups[i] == 0
end

if ! zero.empty? then
  puts 0
  exit
end

if n == 1 then
  puts 1
  exit
end


def power_with_mod(a,b,m = $m)
  if b == 1 then
    return a % m
  end
  if b == 0 then
    return (a ** b) % m
  end

  ret = power_with_mod(a, b/2, m)
  if b % 2 == 0 then
    return ((ret % m) * (ret % m)) % m
  else
    return ((((ret % m) * (ret % m)) % m) * (a % m)) % m
  end
end 

def calc_group(x)
  return power_with_mod(2, (x * (x - 1) / 2))
end

def calc_link(prev_count, curr_count)
  a = ((power_with_mod(2, prev_count) + $m) - 1) % $m
  return power_with_mod(a, curr_count)
end


# ((2^(prev.count) - 1) ^ curr.count) * 2^(curr.count*(curr.count-1)/2)

ret = 1 * calc_group(groups[1])

(2 .. dists.max).each do |i|
  prev, curr = groups[i - 1], groups[i]
  ret = ((ret * calc_link(prev, curr)) % $m) * calc_group(curr)
  ret %= $m
end

puts ret
