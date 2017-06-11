-- 07.2015 - 5 задача

type Trip = (String, Integer, Float)
type Tour = [Trip]

discount :: Tour -> Integer -> Tour
discount tour len = map (apply len) tour

apply :: Integer -> Trip -> Trip
apply l (x, y, z)
 | y > l = (x, y, z - z / 10)
 | otherwise = (x, y, z)
