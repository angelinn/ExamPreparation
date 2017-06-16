sumProd :: [[Integer]] -> Integer
sumProd ll = foldr1 (+) [ y | y <- [ foldr1 (*) x | x <- ll ], y > 0 ]

sumProd1 :: [[Integer]] -> Integer
sumProd1 ll = sum [ y | y <- [ product x | x <- ll ], y > 0]

sumProd2 :: [[Integer]] -> Integer
sumProd2 ll = sum [ product xs | xs <- ll, and [x > 0 | x <- xs ] ]
