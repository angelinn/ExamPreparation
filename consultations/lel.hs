sum1 :: [Integer] -> Integer
sum1 [] = 0
sum1 (x:xs) = x + sum1 xs

sum2 :: [Integer] -> Integer
sum2 [] = 0
sum2 xs = if null xs then 0 else head xs + sum1(tail xs)

sum3 :: [Integer] -> Integer
sum3 [] = 0
sum3 xs 
    | null xs = 0
    | otherwise = head xs + sum (tail xs)

sum4 :: [Integer] -> Integer
sum4 [] = 0
sum4 xs = foldr (+) 0 xs

-- С тейл рекурсия
sum5 :: [Integer] -> Integer
sum5 [] = 0
sum5 xs = sumTailRec xs 0

sumTailRec :: [Integer] -> Integer -> Integer
sumTailRec [] acc = acc
sumTailRec (x:xs) acc = sumTailRec xs (acc + x)

sumProd xss = sum [ product xs | xs <- xss, and [x > 0 | x <- xs ] ]

-- 08.09.2010г. - трета задача
-- чист typedef - замества Trip с кода на кортежа
type Trip = (String, Integer, Float)
type Tour = [Trip]

discount :: Tour -> Integer -> Tour
discount tours len = [ (destination, length, (if length > len then 0.9 else 1)) | (destination, length, price) <- tours ]

shortenTour :: Tour -> String -> String -> Trip -> Tour
shortenTour [] _ _ _ = []
shortenTour tour from to trip
    | d == from = (d, l, p) : shortenTo tps tps from to trip
    | otherwise = (d, l, p) : shortenTour tps from to trip
    where
        (d, l, p) = head tour
        tps = tail tour

shortenTo :: Tour -> Tour -> String -> String -> Trip -> Tour
shortenTo original [] _ _ _ = original
shortenTo original ((d, l, p) : tps) from to trip
    | d == to   = trip : shortenTour tps from to trip
    | otherwise = shortenTo original tps from to trip

-- итеративен процес
sumNumbers :: Integer -> Integer -> Integer
sumNumbers a b
    | a == b    = 0
    | otherwise = a + sumNumbers (a + 1) b -- sumNumbers a (b - 1) + b

-- permutations :: Eq a => [a] -> [[a]]
permutations :: [a] -> [[a]]
permutations []  = []
permutations [x] = [[x]]
permutations xs  = concat [ [ x : p | p <- permutations [ y | (j, y) <- ixs, j /= i ] ] | (i, x) <- ixs ] 
                    where ixs = zip [ 0.. ] xs
    
-- permutations1 :: [a] -> [[a]]
-- permutations1 []  = []
-- permutations1 [x] = [[x]]
-- permutations1 (x:y:xs) = [ x : p | p <- permutations1 (y:xs) ] ++ [ y : p | p <- permutations1 (x:xs) ]

totalMin :: [(Float -> Float)] -> (Float -> Float)
totalMin fs = foldr1 (\f mf -> if f 0 < mf 0 then f else mf)

totalMin1 :: [(Float -> Float)] -> (Float -> Float)
totalMin1 [] = error "empty list"
totalMin1 [f] = f
totalMin1 (f1:f2:fs)
    | f1 0 < f2 0 = totalMin (f1:fs)
    | otherwise = totalMin (f2:fs)
