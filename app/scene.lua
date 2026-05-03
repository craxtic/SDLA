--- prototyping showcase #1

i = vec2f(10, 0)
j = vec2f(0, 10)


a = 5*i + 5*j
b = 10*i + 10*j

-- r1 = Rect(a, b)
-- r2 = Rect(a + i*10,  b + i*15)

-- add(r1)
-- add(r2)

-- -- press r to reload
-- for m = 0, 8 do
--   r = Rect(a + m*i*10, b + m*i*10)
--   add(r)
-- end


for m = 0, 8 do
  for n = 0, 7 do
    r = Rect(a + n*i*10 + m*j*10,  b + n*i*10 + m*j*10)
    add(r)
  end
end

-- i think my export is broken lol
-- i think my export is broken lol
-- i think my export is broken lol

